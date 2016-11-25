#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "plist.h"

/*
 * Reads a line of input from the user, storing the first k
 * characters of the input into a char array assumed to be
 * of size k+1.
 */
void readline(char *buf, int k) { //k = 20
  scanf("%s", buf);
}

/* 
 * Given a string, allocates a copy of the string on the
 * heap and returns a pointer to it.
 */
char* stralloc(char *str) {
  char* s = malloc(sizeof(char));
  strcpy(s, str);
  return s;
}

/*
 * Plays Paranoia.
 */
int main(void) {
  plist_t *target = make_list();
  plist_t *tagged = make_list();
  char s[20];
  int i = 0;

  /* Builds up list of players in game */
  printf("Enter a player's name (enter 'quit' to start the game): ");
  readline(s, 20);
  list_insert(target, stralloc(s));
  while(1) {
    printf("Enter another player's name: ");
    readline(s, 20);
    if(strcmp(s, "quit") == 0) {
      break;
    } else {
      list_insert(target, stralloc(s));
    }
  }
  printf("\n");
  printAsTargetRing(target);
  printAsTaggedList(tagged);
  printf("\n");

  /* Starts the process of removing players from game as they are tagged */
  int length = list_size(target);
  while(i < length - 1) {
    printf("-------------------\n");
    printf("There are %d people left!\n", length - i);
    printf("Enter a target: ");
    readline(s, 20);

    /* Checks to see if the given name exists before removing it */
    if(contains(target, s) != NULL) {
      target = list_remove(target, s);
      list_insert(tagged, stralloc(s));
      printf("\n%s was tagged!\n\n", s);
      printAsTargetRing(target);
      printAsTaggedList(tagged);
      printf("\n");
      i++;
    } else {
      printf("\n%s is not a target!\n\n", s);
    }
  }
  
  /* Frees memory no longer needed */
  free_list(target);
  free_list(tagged);
}
