#ifndef SORTING_ARENA_H
#define SORTING_ARENA_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*============================================================
 *  Sorting Arena — Common Header
 *
 *  Participants only need to implement:
 *    void participant_sort(int *arr, size_t n);
 *============================================================*/

/* ---- Sort function signature ---- */
typedef void (*sort_fn)(int *arr, size_t n);

/* ---- High-resolution timer ---- */
static inline double time_ms(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1000.0 + ts.tv_nsec / 1e6;
}

/* ---- Data generation ---- */
static inline void generate_data(int *arr, size_t n, unsigned seed) {
    srand(seed);
    for (size_t i = 0; i < n; i++) arr[i] = rand();
}

/* ---- Verification ---- */
static inline int is_sorted(const int *arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

/* ---- Benchmark sizes ---- */
/*
 * Default sizes: 1K to 1M.
 * Compile with -DSIZE_10M to include 10M (slow for naive implementations).
 */
static const size_t bench_sizes[] = { 1000, 10000 };
static const char *size_labels[] __attribute__((unused)) = { "1K", "10K" };
#define NUM_SIZES 2
#define WARMUP_RUNS 1
#define BENCH_RUNS  3
#define SEED 42

#endif /* SORTING_ARENA_H */
