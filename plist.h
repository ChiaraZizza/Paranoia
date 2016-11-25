#pragma once

/*
 * Struct definitions for nodes and lists used in the following functions.
 */
typedef struct node {
  char* name;
  struct node *next;
} pnode_t;

typedef struct list {
  pnode_t *first;
} plist_t;


/*
 * Allocates a new node on the heap with the given values.
 */
pnode_t* make_node(char *name, pnode_t *next);

/*
 * Allocates a new, empty list on the heap.
 */
plist_t* make_list();

/*
 * Frees the given node.
 */
void free_node(pnode_t *node);

/*
 * Frees the given list.
 */
void free_list(plist_t *list);

/*
 * Inserts the given name (as a string) into the end of the list.
 */
void list_insert(plist_t *list, char *name);

/*
 * Traverses a list and sees where a given name is in the list--returns
 * a pointer to the node containing the name.
 */
pnode_t* contains(plist_t *list, char *name);

/* 
 * Removes the given name from the list, returning a pointer to the list
 * with the node containing the name removed.
 */
plist_t* list_remove(plist_t *list, char *name);

/*
 * Returns the number of elements in the list.
 */
int list_size(plist_t *list);

/*
 * Prints the current list interpreting it as the "target ring."
 */
void printAsTargetRing(plist_t *list);

/*
 * Prints the current list, interpreting it as the "tagged list."
 */
void printAsTaggedList(plist_t *list);
