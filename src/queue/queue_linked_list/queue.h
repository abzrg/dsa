#ifndef DSA_QUEUE_H
#define DSA_QUEUE_H

//------------------------------------------------------------------------------

#include <limits.h>

#define SENTINEL_VALUE INT_MIN


typedef struct dsa_node_t {
    int value;
    dsa_node_t* next;
} dsa_node_t ;


typedef struct dsa_queue_t {
    dsa_node_t* first;
    dsa_node_t* last;
    size_t length;
} dsa_queue_t;


// Default initializes a queue to zero (or NULL)
static inline void dsa_init_queue(dsa_queue_t* self)
{
    self->length = 0;
    self.first = NULL;
    self.last = NULL;
}

// Add a value to the tail of the queue
/*

            A{1}   B{2}

   Q -> /


   */
static inline void dsa_enqueu(dsa_queue_t* self, int value)
{
    assert(self && "Queue is not initialized.");

    dsa_node_t* n = malloc(sizeof(*n));
    *n = (node_t){
        .value = value,
        .next = NULL,
    }
    assert(n && "Could not initialize the node.")
    // n->value = value;
    // n->next = NULL;

    if (self.first == NULL)
    {
        self.first = n;
        self.last = n;
     else {
        self.last = n;
    }
}

// Removes value residing at head and returns its value
static inline int dsa_deque(dsa_queue_t* self)
{
    assert(self && "Queue is not initialized.");

    return 1;
}

// Returns value residing at head
static inline int dsa_peek(dsa_queue_t* self)
{
    assert(self && "Queue is not initialized.");

    if (self.first == NULL) {
        return SENTINEL_VALUE;
    } else {
        return self.first.value;
    }
}


//------------------------------------------------------------------------------

#endif
