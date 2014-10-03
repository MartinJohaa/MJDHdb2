#include "list.h"
#include "nodestruct.h"
#include "readline.h"
#include <stdlib.h>

void build(char *filename) {
  FILE *database = fopen(filename, "r"); // opens the file stored in filename and sets it to readmode
  while(!(feof(database))){
    // while the file is not completely read, do this stuff
    Node newNode = malloc(sizeof(struct node)); // allocate memory for newNode
    readline(buffer, 128, database); // reads up to 128 characters and stores it in buffer
    newNode->key = malloc(strlen(buffer) + 1); // allocate memory for key
    strcpy(newNode->key, buffer); // copy string from buffer to key
    readline(buffer, 128, database); // reads up to 128 characters and stores it in buffer
    newNode->value = malloc(strlen(buffer) + 1); // allocate memory for value 
    strcpy(newNode->value, buffer); // copy string from buffer to value
    newNode->next = list; // set the next node equal to list
    list = newNode; // save what we just read in list
  }
}
