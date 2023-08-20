#include "quicksort.h"


// Divides the array into two partitions
static int partition(int* arr, int lo, int hi)
{
    const int pivot = arr[hi];

    // Index of the division (temporary pivot index)
    int div_index = lo - 1;

    // Weak sort
    // ( [[values lt pivot],[values gt pivot], pivot] )
    //                     ^ div_idx
    for (size_t i = lo; i < hi; i++) {
        if (arr[i] <= pivot) {
            div_index++;
            const int tmp = arr[i];
            arr[i] = arr[div_index];
            arr[div_index] = tmp;
        }
    }

    // Move the pivot element to the correct pivot position (between the smaller
    // and larger elements)
    div_index++;
    arr[hi] = arr[div_index];
    arr[div_index] = pivot;

    return div_index;
}


// Sorts (a portion of) an array, divides it into two partitions, then sorts
// those
static void qs(int* arr, int lo, int hi)
{
    // Ensure indices are in correct order
    if (lo >= hi) {
        return;
    }

    // Partition the array and the get the pivot index
    const int pivot_index = partition(arr, lo, hi);

    // Sort the two partitions
    qs(arr, lo, pivot_index - 1); // Left side of the pivot
    qs(arr, pivot_index + 1, hi); // Right side of the pivot
}


void dsa_quicksort(int* arr, size_t len)
{
    if (len <= 1 ) {
        return;
    }

    // TODO: For small size arrays, one can replace the following algorithm with
    // another simpler or faster (for smaller dataset) algorithm.

    qs(arr, 0, len - 1);
}
