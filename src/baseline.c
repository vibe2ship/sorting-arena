#include "arena.h"

/*============================================================
 *  Baseline: stdlib qsort
 *  This is the reference implementation to beat.
 *============================================================*/

static int cmp_int(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

void baseline_sort(int *arr, size_t n) {
    qsort(arr, n, sizeof(int), cmp_int);
}
