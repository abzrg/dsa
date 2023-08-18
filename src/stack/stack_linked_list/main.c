#include <stdio.h>
#include "stack_linked_list.h"


int main(void)
{
    dsa_stack_t s;
    dsa_stack_init(&s);

    printf("stack size: %zu\n", s.height);

    dsa_push(&s, 1);
    dsa_push(&s, 2);
    dsa_push(&s, 3);
    dsa_push(&s, 4);

    printf("stack size: %zu\n", s.height);

    int top = dsa_peek(&s);
    printf("stack top: %d\n", top);

    for (size_t i = 0, height = s.height; i < height + 1; i++) {
        int popped = dsa_pop(&s);

        if (popped == SENTINEL_VALUE) {
            printf("Could not pop stack. Stack is empty\n");
        } else {
            printf("%zu. popped value: %d\n", i + 1, popped);
        }
    }

    return 0;
}
