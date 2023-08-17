#include <stdio.h>


#define ARR_SIZE(ARR) sizeof(ARR) / sizeof((ARR)[0])


int linear_search(const int* arr, size_t len, int value);


int main(void)
{
    int numbers[] = { 1, 2, 3, 4, 5 };

    int four_index = linear_search(numbers, ARR_SIZE(numbers), 4);
    printf("four_index: %d\n", four_index);

    int six_index = linear_search(numbers, ARR_SIZE(numbers), 6);
    printf("six_index: %d\n", six_index);

    return 0;
}


// Returns index of the value in the array, otherwise returns -1 if the value
// can not be found in the array
int linear_search(const int* arr, size_t len, int value)
{
    for (size_t i = 0; i < len; i++) {
        if (arr[i] == value) {
            return i;
        }
    }

    return -1;
}
