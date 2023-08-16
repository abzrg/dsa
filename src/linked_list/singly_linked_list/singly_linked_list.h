#ifndef DSA_SINGLY_LINKED_LIST_H
#define DSA_SINGLY_LINKED_LIST_H

/*----------------------------------------------------------------------------*/

#include <stdbool.h>


typedef struct node_t {
    int val;
    node_t* next;
} node_t ;


typedef struct {
    node_t* head;
    node_t* tail; // an optimization for operation done on the tail node
    size_t length;
} dsa_singly_linked_list_t;


void dsa_insert_at(dsa_singly_linked_list_t* sll, size_t index, int value);
void dsa_append(dsa_singly_linked_list_t* sll, int value);
void dsa_prepend(dsa_singly_linked_list_t* sll, int value);


int dsa_get_at(const dsa_singly_linked_list_t* sll, size_t index);
size_t dsa_get_length(const dsa_singly_linked_list_t* sll);


int dsa_remove_at(const dsa_singly_linked_list_t* sll, size_t index);
int dsa_remove(const dsa_singly_linked_list_t* sll, int value);



/*----------------------------------------------------------------------------*/
#endif // DSA_SINGLY_LINKED_LIST_H
