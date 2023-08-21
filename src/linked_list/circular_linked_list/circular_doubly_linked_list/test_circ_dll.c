#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "circ_dll.h"


int main(void)
{
    circ_dll_t* list;
    dll_init(&list);


    // Test dll_prepend and dll_append
    dll_prepend(list, 10);
    dll_prepend(list, 20);
    dll_append(list, 30);
    dll_append(list, 40);
    print_list(list);

    // Test dll_insert_at
    dll_insert_at(list, 2, 25);
    print_list(list);


    putchar('\n');


    // Test dll_get_length and dll_get
    size_t length = dll_get_len(list);
    printf("List length: %zu\n", length);

    for (size_t i = 0; i < length; i++) {
        printf("List[%zu]: %d\n", i, dll_get(list, i));
    }
    print_list(list);


    putchar('\n');


    // Test dll_pop and dll_popleft
    int value;
    while (dll_pop(list, &value)) {
        printf("Popped value: %d\n", value);
    }
    print_list(list);
    if (dll_popleft(list, &value)) {
        printf("Popped left value: %d\n", value);
    } else {
        printf("Could not pop value. List is empty.\n");
    }


    putchar('\n');


    // Test dll_remove_at
    dll_prepend(list, 10);
    dll_prepend(list, 20);
    dll_prepend(list, 30);
    print_list(list);
    if (dll_remove_at(list, 1, &value)) {
        printf("Removed value at index 1: %d\n", value);
    }
    if (dll_remove_at(list, 0, &value)) {
        printf("Removed value at index 0: %d\n", value);
    }


    putchar('\n');


    // Test dll_remove
    dll_append(list, 40);
    dll_append(list, 50);
    int index = dll_remove(list, 40);
    printf("Value 40 removed from index: %d\n", index);



    return 0;
}
