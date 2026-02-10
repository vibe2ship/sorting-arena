#include "arena.h"

extern void baseline_sort(int *arr, size_t n);
extern void participant_sort(int *arr, size_t n);

#define BAR_WIDTH 40

static double run_bench(sort_fn fn, int *src, size_t n) {
    int *buf = malloc(n * sizeof(int));
    if (!buf) { perror("malloc"); exit(1); }

    /* warmup */
    for (int r = 0; r < WARMUP_RUNS; r++) {
        memcpy(buf, src, n * sizeof(int));
        fn(buf, n);
    }

    /* timed runs — take best of BENCH_RUNS */
    double best = 1e18;
    for (int r = 0; r < BENCH_RUNS; r++) {
        memcpy(buf, src, n * sizeof(int));
        double t0 = time_ms();
        fn(buf, n);
        double t1 = time_ms();
        double elapsed = t1 - t0;
        if (elapsed < best) best = elapsed;

        if (r == BENCH_RUNS - 1 && !is_sorted(buf, n)) {
            fprintf(stderr, "[FAIL] output is NOT sorted!\n");
            free(buf);
            return -1.0;
        }
    }

    free(buf);
    return best;
}

static void print_bar(const char *label, double ms, double max_ms, const char *color, int is_winner) {
    int len = (max_ms > 0) ? (int)(ms / max_ms * BAR_WIDTH) : 0;
    if (len < 1 && ms > 0) len = 1;

    printf("  %-11s %s", label, color);
    for (int i = 0; i < len; i++) printf("█");
    printf("\033[0m");
    for (int i = len; i < BAR_WIDTH; i++) printf(" ");

    if (ms < 0)
        printf("  FAIL ✗\n");
    else if (is_winner)
        printf("  %8.2f ms  ◀\n", ms);
    else
        printf("  %8.2f ms\n", ms);
}

int main(void) {
    printf("\n");
    printf("  ┌─────────────────────────────────────────────────────────────┐\n");
    printf("  │              \033[1mSorting Arena  ·  Benchmark\033[0m                     │\n");
    printf("  │              Vibe2Ship Hackathon                            │\n");
    printf("  └─────────────────────────────────────────────────────────────┘\n");
    printf("\n");
    printf("  \033[33m█\033[0m qsort (reference)    \033[36m█\033[0m participant (you)\n\n");

    int wins = 0;

    for (int si = 0; si < NUM_SIZES; si++) {
        size_t n = bench_sizes[si];
        int *src = malloc(n * sizeof(int));
        if (!src) { perror("malloc"); return 1; }

        generate_data(src, n, SEED);

        double t_qsort = run_bench(baseline_sort, src, n);
        double t_part  = run_bench(participant_sort, src, n);
        double max_ms  = t_qsort > t_part ? t_qsort : t_part;
        if (max_ms <= 0) max_ms = 1;

        int part_wins = (t_part > 0 && t_part < t_qsort);

        printf("  ━━ %s (%zu elements) ", size_labels[si], n);
        if (t_qsort > 0 && t_part > 0) {
            double ratio = t_qsort / t_part;
            if (part_wins)
                printf("\033[32m%.2fx faster\033[0m", ratio);
            else
                printf("\033[31m%.2fx slower\033[0m", 1.0 / ratio);
        }
        printf("\n\n");

        print_bar("qsort",       t_qsort, max_ms, "\033[33m", !part_wins);
        print_bar("participant", t_part,  max_ms, "\033[36m",  part_wins);
        printf("\n");

        if (part_wins) wins++;
        free(src);
    }

    printf("  ┌─────────────────────────────────────────────────────────────┐\n");
    printf("  │  Result:  ");
    if (wins == NUM_SIZES)
        printf("\033[32m★  PERFECT — you beat qsort on every test!\033[0m");
    else if (wins > 0)
        printf("\033[33m~  You beat qsort on %d/%d tests. Keep going!\033[0m  ", wins, NUM_SIZES);
    else
        printf("\033[31m✗  qsort wins every test. Time to optimize!\033[0m   ");
    printf("  │\n");
    printf("  └─────────────────────────────────────────────────────────────┘\n\n");

    return 0;
}
