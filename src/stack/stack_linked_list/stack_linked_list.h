#ifndef DSA_SRC_STACK_LINKED_LIST_H
#define DSA_SRC_STACK_LINKED_LIST_H


#include <limits.h>
#include <assert.h>
#include <stdlib.h>


#define SENTINEL_VALUE INT_MIN


typedef struct _node_t {
    int value;
    struct _node_t* next;
} dsa_node_t ;


//                T{height: 4}
// 1 <- 2 <- 3 <- 4
typedef struct {
    dsa_node_t* top;
    size_t height;
} dsa_stack_t;


inline static void dsa_stack_init(dsa_stack_t* self)
{
    assert(self != NULL && "Stack is pointing to NULL.");

    self->height = 0;
    self->top = NULL;
}

inline static void dsa_push(dsa_stack_t* self, int value)
{
    assert(self != NULL && "Stack is pointing to NULL.");

    dsa_node_t* n = malloc(sizeof(*n));
    n->value = value;

    if (self->height == 0) {
        n->next = NULL;
        self->top = n;
    } else {
        n->next = self->top;
        self->top = n;
    }

    self->height++;
}

inline static int dsa_pop(dsa_stack_t* self)
{
    assert(self != NULL && "Stack is pointing to NULL.");

    if (self->height == 0) {
        return SENTINEL_VALUE;
    }

    const dsa_node_t* top = self->top;
    self->top = top->next;
    self->height--;

    return top->value;
}

inline static int dsa_peek(const dsa_stack_t* self)
{
    assert(self != NULL && "Stack is pointing to NULL.");

    if (self->height == 0) {
        return SENTINEL_VALUE;
    }

    return self->top->value;
}


#endif // !DSA_SRC_STACK_LINKED_LIST_H
