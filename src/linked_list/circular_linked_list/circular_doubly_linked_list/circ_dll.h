#include <stdbool.h>
#include <stddef.h>

// A node type containing an integer value that points to next and previous
typedef struct dnode_t dnode_t;

// A circular doubly-linkedlist type
typedef struct circ_dll_t circ_dll_t;


// Initialize the list to zero/NULL
void dll_init(circ_dll_t** self);

// Terminates (destruct) the list
void dll_terminate(circ_dll_t** self);

// Get the number of element in the list
size_t dll_get_len(const circ_dll_t* self);

// Prepends a node to a list
void dll_prepend(circ_dll_t* self, int value);

// Appends a node to the end of the list
void dll_append(circ_dll_t* self, int value);

// Inserts a node at a specific place ("index") in the list
void dll_insert_at(circ_dll_t* self, size_t index, int value);

// Returns a copy of the value at a certain position ("index") in the list
int dll_get(const circ_dll_t* self, size_t index);

// Pop a value from the end of the list
bool dll_pop(circ_dll_t* self, int* retval);

// pop from head side
bool dll_popleft(circ_dll_t* self, int* retval);

bool dll_remove_at(circ_dll_t* self, size_t index, int* retval);

// Removes the first node in the list with a specific value
// (returns -1 if the value cannot be found in the list)
int dll_remove(circ_dll_t* self, int value);

// Prints the list
void print_list(circ_dll_t* list);
