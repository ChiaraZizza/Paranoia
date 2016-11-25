#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plist.h"

/*
 * Allocates a new node on the heap with the given values.
 */
pnode_t* make_node(char *name, pnode_t *next) {
  pnode_t *ret = (pnode_t*)malloc(sizeof(pnode_t));
  ret->name = name;
  ret->next = next;
  return ret;
}

/*
 * Allocates a new, empty list on the heap.
 */
plist_t* make_list(void) {
  plist_t *ret = (plist_t*)malloc(sizeof(plist_t));
  ret->first = NULL;
  return ret;
}

/*
 * Frees the given node.
 */
void free_node(pnode_t *node) {
  free(node);
}

/*
 * Frees the given list.
 */
void free_list(plist_t *list) {
  pnode_t *cur = list->first;
  while (cur != NULL) {
    pnode_t *next = cur->next;
    free_node(cur);
    cur = next;
  }
  free(list);
}

/*
 * Inserts the given name (as a string) into the end of the list.
 */
void list_insert(plist_t *list, char *name) {
  pnode_t *new_node = make_node(name, NULL);
  if(list->first == NULL) {
    list->first = new_node;
  } else {
    pnode_t *cur = list->first;
    while (cur->next != NULL) {
      cur = cur->next;
    }
    cur->next = new_node;
  }
}

/*
 * Traverses a list and sees where a given name is in the list--returns
 * a pointer to the node containing the name.
 */
pnode_t* contains(plist_t *list, char *name) {
  pnode_t *cur = list->first;
  while (cur != NULL) {
    if (strcmp(cur->name, name) == 0) {
      return cur;
    }
    cur = cur->next;
  }
  return NULL;
}

/* 
 * Removes the given name from the list, returning a pointer to the list
 * with the node containing the name removed.
 */
plist_t* list_remove(plist_t *list, char *name) {
  pnode_t *cur = list->first;
  pnode_t *prev = NULL;
  while (cur != NULL) {
    if(strcmp(cur->name, name) == 0) {
      if(prev == NULL) {
	list->first = cur->next;
	return list;
      } else {
	prev->next = cur->next;
	return list; //returns the node with the removed name in it
      }
    }
    prev = cur;
    cur = cur->next;
  }
  return NULL;
}

/*
 * Returns the number of elements in the list.
 */
int list_size(plist_t *list) {
  int sum = 0;
  pnode_t *cur = list->first;
  while (cur != NULL) {
    sum++;
    cur = cur->next;
  }
  return sum;
}

/*
 * Prints the current list interpreting it as the "target ring."
 */
void printAsTargetRing(plist_t *list) {
  pnode_t *cur = list->first;
  pnode_t *prev = cur;
  pnode_t *name1 = list->first;
  printf("Target Ring: \n");
  if(list_size(list) > 1) {
    while (cur->next != NULL) {
      printf("\t%s is stalking %s\n", prev->name, cur->next->name);
      prev = cur->next;
      cur = prev;
    }
    printf("\t%s is stalking %s\n", prev->name, name1->name);
  } else {
    printf("\t%s is the final person remaining!\n", prev->name);
  }
}

/*
 * Prints the current list, interpreting it as the "tagged list."
 */
void printAsTaggedList(plist_t *list) {
  pnode_t *cur = list->first;
  if(list->first == NULL) {
    printf("No people have been tagged yet!\n");
  } else {
    printf("Tagged List:\n");
    while (cur != NULL) {
      printf("\t%s\n", cur->name);
      cur = cur->next;
    }
  }
}
