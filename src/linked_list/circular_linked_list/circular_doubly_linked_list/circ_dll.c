#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "circ_dll.h"


#define SENTINEL_VALUE INT_MIN


// TODO: If retval == NULL => ignore filling the value


struct dnode_t {
    struct dnode_t* next;
    struct dnode_t* prev;
    int value;
};

struct circ_dll_t {
    dnode_t* head;
    dnode_t* tail;
    size_t length;
};

// Initializes a list to zero/NULL
void dll_init(circ_dll_t** self)
{
    *self = malloc(sizeof(**self));
    if (*self) {
        (*self)->head = NULL;
        (*self)->tail = NULL;
        (*self)->length = 0;
    }
}

// Deallocate/Destruct a list
void dll_terminate(circ_dll_t** self)
{
    dnode_t* head = (*self)->head;

    // for (size_t i = 0, len = (*self)->length; i < len; i++) {
    //     dnode_t* tmp = head;
    //     head = head->next;
    //     free(tmp);
    // }

    int _;
    while (dll_pop(*self, &_)) { }

    free(*self);
}


size_t dll_get_len(const circ_dll_t* self)
{
    return self->length;
}

// Prepends a node to a list
void dll_prepend(circ_dll_t* self, int value)
{
    assert(self != NULL && "The container is NULL.");

    dnode_t* node = malloc(sizeof(*node));
    node->value = value;

    if (self->length == 0) {
        node->next = node;
        node->prev = node;
        self->head = node;
        self->tail = node;
    } else {
        node->next = self->head;
        node->prev = self->tail;

        self->head->prev = node;
        self->tail->next = node;

        self->head = node;
    }

    self->length++;
}

// Appends a node to the end of the list
void dll_append(circ_dll_t* self, int value)
{
    assert(self != NULL && "The container is NULL.");

    if (self->length == 0) {
        dll_prepend(self, value);
    }

    dnode_t* node = malloc(sizeof(*node));

    node->value = value;

    node->next = self->head;
    node->prev = self->tail;

    self->head->prev = node;
    self->tail->next = node;

    self->tail = node;

    self->length++;
}

// Inserts a node at a specific place ("index") in the list
void dll_insert_at(circ_dll_t* self, size_t index, int value)
{
    assert(self != NULL && "The container is NULL.");
    assert(index < self->length
           && "Cannot insert at the given index. Index out of bound.");

    // Prepend
    if (index == 0) {
        dll_prepend(self, value);
        return;
    }

    // Append
    if (index == self->length) {
        dll_append(self, value);
    }

    // Traverse index item into list
    dnode_t* tmp = self->head;
    for (size_t i = 0; i < index; i++) {
        tmp = tmp->next;
    }

    dnode_t* node = malloc(sizeof(*node));

    node->value = value;

    node->next = tmp;
    node->prev = tmp->prev;

    tmp->prev->next = node;
    tmp->prev = node;

    self->length++;
}

// Returns a copy of the value at a certain position ("index") in the list
int dll_get(const circ_dll_t* self, size_t index)
{
    assert(self != NULL && "The container is NULL.");
    assert(index < self->length
           && "Cannot insert at the given index. Index out of bound.");

    // Traverse index item into list
    dnode_t* tmp = self->head;
    for (size_t i = 0; i < index; i++) {
        tmp = tmp->next;
    }

    return tmp->value;
}

// Pop from tail side
bool dll_pop(circ_dll_t* self, int* retval)
{
    if (self->length == 0) {
        *retval = SENTINEL_VALUE;
        return false;
    }

    *retval = self->tail->value;

    dnode_t* tail = self->tail;

    if (self->length == 1) {
        self->head = NULL;
        self->tail = NULL;
    } else {
        tail->prev->next = self->head;
        self->head->prev = tail->prev;

        self->tail = tail->prev;
    }

    free(tail);

    self->length--;

    return true;
}

// pop from head side
bool dll_popleft(circ_dll_t* self, int* retval)
{
    assert(self != NULL && "The container is NULL.");

    if (self->length == 0) {
        *retval = SENTINEL_VALUE;
        return false;
    }

    if (self->length == 1) {
        return dll_pop(self, retval);
    }

    *retval = self->tail->value;

    dnode_t* tail = self->tail;

    tail->prev->next = self->head;
    self->head->prev = tail->prev;

    self->tail = tail->prev;

    free(tail);

    self->length--;

    return true;
}

// Removes an element at a certain position
// returns false if the index was out of bound or list was empty.
bool dll_remove_at(circ_dll_t* self, size_t index, int* retval)
{
    assert(self != NULL && "The container is NULL.");

    if (self->length == 0) {
        *retval = SENTINEL_VALUE;
        return false;
    }

    if (index >= self->length) {
        *retval = SENTINEL_VALUE;
        return false;
    }

    if (index == 0) {
        return dll_popleft(self, retval);
    }

    if (index == self->length - 1) {
        return dll_pop(self, retval);
    }

    // Traverse index item into list
    dnode_t* tmp = self->head;
    for (size_t i = 0; i < index; i++) {
        tmp = tmp->next;
    }

    // Get the value to be removed
    *retval = tmp->value;

    // Rearrange nodes in the list
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    // Release the node resource
    free(tmp);

    self->length--;

    return true;
}

int dll_remove(circ_dll_t* self, int value)
{
    if (self->length == 0) {
        return -1;
    }

    dnode_t* node = self->head;

    // h     t
    // a<-b->c
    // a->b<-c
    for (size_t i = 0, len = self->length; i < len; i++) {
        if (value == node->value) {
            if (i == 0) {
                dll_popleft(self, &value);
            } else if (i == len) {
                dll_pop(self, &value);
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;

                free(node);
                self->length--;
            }

            return (int)i;
        }
    }

    return -1;
}


void print_list(circ_dll_t* list)
{
    printf("List: [");

    if (list->length == 0) {
        printf("]\n");
        return;
    }

    dnode_t* node = list->head;
    for (size_t i = 0, len = list->length - 1; i < len; i++) {
        printf("%d, ", node->value);
        node = node->next;
    }

    printf("%d]\n", node->value);
}
