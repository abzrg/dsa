#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

//------------------------------------------------------------------------------

#include <stdlib.h>
#include <limits.h>
#include <assert.h>

#define SENTINEL_VALUE INT_MIN


typedef struct dsa_node_t {
    int value;
    struct dsa_node_t* next;
} dsa_node_t ;


typedef struct dsa_queue_t {
    dsa_node_t* first;
    dsa_node_t* last;
    size_t length;
} dsa_queue_t;


// Default initializes a queue to zero (or NULL)
static inline void dsa_queue_init(dsa_queue_t* self)
{
    self->length = 0;
    self->first = NULL;
    self->last = NULL;
}

// Add a value to the tail of the queue
static inline void dsa_enqueue(dsa_queue_t* self, int value)
{
    assert(self && "Queue is not initialized.");

    dsa_node_t* node = malloc(sizeof(*node));
    node->value = value,
    node->next = NULL,
    assert(node && "Could not initialize the node.");

    if (self->length == 0)
    {
        assert(self->first == NULL && "Queue is empty but first != NULL");
        assert(self->last == NULL && "Queue is empty but last != NULL");

        // Adding first node to queue
        self->first = node;
        self->last = node;
    } else {
        assert(self->first != NULL && "Queue is not empty but first == NULL.");
        assert(self->last != NULL && "Queue is not empty but last == NULL.");

        self->last->next = node;
        self->last = node;
    }

    self->length++;
}

// Removes value residing at last node and returns its value
static inline int dsa_deque(dsa_queue_t* self)
{
    assert(self && "Queue is not initialized.");

    // Empty queue
    if (self->length == 0) {
        return SENTINEL_VALUE;
    }

    dsa_node_t* first_node = self->first;
    const int first_value = self->first->value;

    // Queue with one node
    if (self->length == 1) {
        assert(self->first == self->last && "queue.length == 1 but queue.first != queue.last");

        free(self->first);
        self->first = NULL;
        self->last = NULL;
    } else {
        self->first = first_node->next;
        free(first_node);
        first_node = NULL;
    }

    self->length--;

    return first_value;
}

// Returns value residing at first node
static inline int dsa_peek(dsa_queue_t* self)
{
    assert(self && "Queue is not initialized.");

    if (self->first == NULL) {
        return SENTINEL_VALUE;
    } else {
        return self->first->value;
    }
}


static inline size_t dsa_queue_get_len(dsa_queue_t* self)
{
    return self->length;
}


//------------------------------------------------------------------------------

#endif
