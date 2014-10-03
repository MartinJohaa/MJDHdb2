#include <stdlib.h>
#include <string.h>
#include "binary.h"
#include "binarystruct.h"
#include "readline.h"

int first = 1;
Node root = NULL;
Node temp = NULL;
int done = 0;
char str[128];

extern int count;

void build(char *filename) {
  FILE *database = fopen(filename, "r");
  while (!(feof(database))){
    if (first) {
      Node newNode = malloc(sizeof(struct node)); // allocate memory for newNode
      readline(buffer, 128, database); // reads up to 128 characters and stores it in buffer
      newNode->key = malloc(strlen(buffer) + 1); // allocate memory for key
      strcpy(newNode->key, buffer); // copy string from buffer to key
    
      readline(buffer, 128, database); // reads up to 128 characters and stores it in buffer
      newNode->value = malloc(strlen(buffer) + 1); // allocate memory for value 
      strcpy(newNode->value, buffer); // copy string from buffer to value
    
      newNode->left = NULL;
      newNode->right = NULL;
      root = newNode;
      printf("%s and %s placed in root\n",newNode->key, newNode->value);
      first = 0;
    }
    
    done = 0;
    temp = root;
    Node newNode = malloc(sizeof(struct node)); // allocate memory for newNode
    readline(buffer, 128, database); // reads up to 128 characters and stores it in buffer
    if (!count){
      newNode->key = malloc(strlen(buffer) + 1); // allocate memory for key
      strcpy(newNode->key, buffer); // copy string from buffer to key

      readline(buffer, 128, database); // reads up to 128 characters and stores it in buffer
      newNode->value = malloc(strlen(buffer) + 1); // allocate memory for value 
      strcpy(newNode->value, buffer); // copy string from buffer to value

      newNode->left = NULL;
      newNode->right = NULL;

      while(!done) {
        if (strcmp(temp->key, newNode->key) < 0) {
          if (temp->right == NULL){
            temp->right = newNode;
            printf("%s and %s was placed to the right\n", newNode->key, newNode->value);
            done = 1;
          }
          else {
            temp = temp->right;
            printf("Continue to the right\n");
          }
        }
 
        else {
          if (temp->left == NULL){
            temp->left = newNode;
            printf("%s and %s was placed to the left\n", newNode->key, newNode->value);
            done = 1;
          }
          else{
            temp = temp->left;
            printf("Continue to the left\n");
          }
        }
      }
    } else break;

  }

}


void print(Node root) {
  if(root == NULL) return;

  print(root->left);
  printf("%s: %s\n", root->key, root->value);
  print(root->right);
}

void search(Node root, char* key){
  if (root == NULL) {
    printf("Key \"%s\" not found.\n", key);
  }
  else {
    if(strcmp(key, root->key) == 0) {
      printf("Found.\nKey: %s\nValue: %s\n", key, root->value);
    }
    else {
      if(strcmp(key, root->key) > 0) { // key comes after root->key, go right
        search(root->right, key);
      }
      else search(root->left, key);
    }
  }
}

void delete(Node root, char* key){
  if (root == NULL) {
    printf("Key \"%s\" not found.\n", key);
  }
  else {
    if(strcmp(key, root->key) == 0) {
      printf("Key: %s\nValue: %s\n Has been deleted \n", key, root->value);
      root->key = NULL;
      root->value = NULL;
    }
    else {
      if(strcmp(key, root->key) > 0) { // key comes after root->key, go right
        delete(root->right, key);
      }
      else delete(root->left, key);
    }
  }
}



char *xstrdup(const char *s)
{
  size_t len = strlen(s);
  char *s2 = malloc(len + 1);
  strcpy(s2, s);
  return s2;
}


/* Node makeNode(char* val, char* k) {
      Node newNode = malloc(sizeof(struct node));
      newNode->value = xstrdup(val);
      newNode->key = xstrdup(k);
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode; 
}

*/

void insert(Node node, char* val, char* k) {

  if (root == NULL) // No keys in tree, add new key in root
    {
      Node newNode = malloc(sizeof(struct node));
      newNode->value = xstrdup(val);
      newNode->key = xstrdup(k);
      newNode->left = NULL;
      newNode->right = NULL;
      root = newNode;
      printf("Key added.");
      return;
    }
  
  if(strcmp(k, node->key) == 0) 
    {
      printf("Key already exists.");
      return;
    }
  
  else if(strcmp(k, node->key) > 0) // New key comes after node->key, place to right if null else go right
    { 
      if(node->right == NULL) 
        {
          Node newNode = malloc(sizeof(struct node));
          newNode->value = xstrdup(val);
          newNode->key = xstrdup(k);
          newNode->left = NULL;
          newNode->right = NULL;
          node->right = newNode;
          printf("Key added.");
        } else insert(node->right ,val, k);
    }
  else if(strcmp(k, node->key) < 0) // New key comes before node->key, place to left if null else go left
    { 
      if(node->left == NULL) 
        {
          Node newNode = malloc(sizeof(struct node));
          newNode->value = xstrdup(val);
          newNode->key = xstrdup(k);
          newNode->left = NULL;
          newNode->right = NULL;
          node->left = newNode;
          printf("Key added.");
        } else  insert(node->left, val, k);
    }
}

void update(Node root, char* key){
  if (root == NULL) {
    printf("Key \"%s\" not found.\n", key);
  }
  else {
    if(strcmp(key, root->key) == 0) {

      char newKey[128];
      char newVal[128];
      printf("Replace key: %s\n With new key: ", key);
      scanf("%s", newKey);
      printf("And replace old value %s\n With new value: ", root->value);
      scanf("%s", newVal);
      root->key = newKey;
      root->value = newVal;
    }
    else {
      if(strcmp(key, root->key) > 0) { // key comes after root->key, go right
        update(root->right, key);
      }
      else update(root->left, key);
    }
  }
}


void options() {
  int choice = -1;
  char key[128];
  char val[128];
  while(choice != 0){
    puts("Please choose an operation");
    puts("1. Query a key");
    puts("2. Update an entry");
    puts("3. New entry");
    puts("4. Remove entry");
    puts("5. Print database");
    puts("0. Exit database");
    printf("? ");
    scanf("%d", &choice);
    while(getchar() != '\n'); // Clear stdin
    switch(choice){
    case 1:
      printf("Type key to query: ");
      scanf("%s", key);
      search(root, key);
      break;
    case 2:
      printf("Type key to update: ");
      scanf("%s", key);
      update(root, key);
      break;
    case 3:
      printf("Type key to add: ");
      scanf("%s", key);
      printf("Type value to add to key: ");
      scanf("%s", val);
      insert(root, val, key);
      break;
    case 4:
      printf("Type key to delete: ");
      scanf("%s", key);
      delete(root, key);
      break;
    case 5:
      print(root);
      break;
    case 0:
      // Exit
      puts("Good bye!");
      break;
    default:
      // Please try again
      puts("Could not parse choice! Please try again");
    }
    puts("");
  }
}
