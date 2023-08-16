// Size of the array should be known at compile time
#define FIXED_SIZE 8


// Macro to calculate the number of items in an array during compile time
#define ARR_SIZE(ARR) sizeof((ARR)) / sizeof((ARR)[0])


int main(void)
{
    // Declare and then populate values
    int numbers[FIXED_SIZE];
    numbers[0] = 1;
    numbers[FIXED_SIZE - 1] = 8;

    // Let the compiler calculate the size
    double constants[] = { 3.1415, 2.7, 1.618 };

    // Using the macro above to calculate the size of the array
    unsigned long size = ARR_SIZE(constants);

    // All zero
    int zeros[FIXED_SIZE] = { 0 };

    // Initialize in place
    int ones[FIXED_SIZE] = { 1, 1, 1, 1, 1 };

    // name = [A, L, I, C, E, 0, 0, 0]
    char name[FIXED_SIZE] = { 'A', 'L', 'I', 'C', 'E' };

    // Array of N pointers to ints
    int alice, bob, charlie;
    int* addresses[FIXED_SIZE] = { &alice, &bob, &charlie };

    // Pointer to an Array of N chars
    char (*ref_name)[FIXED_SIZE] = &name;

    return 0;
}
