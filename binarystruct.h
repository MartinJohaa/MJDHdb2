#ifndef __binarystruct_h
#define __binarystruct_h


typedef struct node{
  char *key;
  char *value;
  struct node *left;
  struct node *right;
} *Node;

char buffer[128]; // maximum amount of characters we can read
int found;
Node cursor;


#endif
