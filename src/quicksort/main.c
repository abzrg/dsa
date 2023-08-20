#include <stdio.h>
#include <stdlib.h>

#include "quicksort.h"

void print_arr(int *arr, size_t len)
{
    printf("[");
    for (size_t i = 0; i < len - 1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[len - 1]);
}

int main(void)
{
    int arr[] = {8, 7, 6, 4, 5};
    const size_t len = 5;

    printf("Before:\t");
    print_arr(arr, len);

    dsa_quicksort(arr, len);

    printf("After:\t");
    print_arr(arr, len);

    return EXIT_SUCCESS;
}
