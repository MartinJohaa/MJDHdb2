#ifndef __nodestruct_h
#define __nodestruct_h
#include <string.h>

typedef struct node{
  char *key;
  char *value;
  struct node *next;
} *Node;

char buffer[128]; // maximum amount of characters we can read
Node list; // create a node called list and initialize it to being empty (NULL)
int found;
Node cursor;

#endif
