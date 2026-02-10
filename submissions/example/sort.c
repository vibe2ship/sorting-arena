#include "arena.h"

/*============================================================
 *  Implement participant_sort() to beat qsort.
 *
 *  Rules:
 *    - Pure C (C11), no external libraries
 *    - Extra memory: O(n) max
 *    - Must produce correct ascending sort
 *    - AI: go wild
 *============================================================*/

void participant_sort(int *arr, size_t n) {
    /* --- YOUR IMPLEMENTATION HERE --- */

    /* Starting point: insertion sort. Very slow. Go beat qsort. */
    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        size_t j = i;
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = key;
    }
}
