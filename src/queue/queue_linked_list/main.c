#include <stdio.h>

#include "queue_linked_list.h"

int main(void)
{
#if 0
    dsa_queue_t q = (dsa_queue_t){
        .length = 0,
        .first = NULL,
        .last = NULL
    };
#else
    dsa_queue_t q;
    dsa_queue_init(&q);
#endif

    size_t len = dsa_queue_get_len(&q);
    int check = dsa_peek(&q);    // sentinel value
    dsa_enqueue(&q, 1);
    dsa_enqueue(&q, 2);
    dsa_enqueue(&q, 3);
    dsa_enqueue(&q, 4);
    dsa_enqueue(&q, 5);
    check = dsa_peek(&q);        // 1
    len = dsa_queue_get_len(&q); // 5

    int result = dsa_deque(&q);  // 1
    result = dsa_deque(&q);      // 2
    result = dsa_deque(&q);      // 3
    result = dsa_deque(&q);      // 4
    result = dsa_deque(&q);      // 5
    result = dsa_deque(&q);      // sentinel value

    return 0;
}
