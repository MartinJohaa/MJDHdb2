#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "node.h"

void options(void);

void welcomeMessage() {
  puts("Welcome to");
  puts(" ____    ____       ");
  puts("/\\  _`\\ /\\  _`\\     ");
  puts("\\ \\ \\/\\ \\ \\ \\L\\ \\   ");
  puts(" \\ \\ \\ \\ \\ \\  _ <\\ ");
  puts("  \\ \\ \\_\\ \\ \\ \\L\\ \\ ");
  puts("   \\ \\____/\\ \\____/ ");
  puts("    \\/___/  \\/___/  ");
  puts("");  
}

int main(int argc, char *argv[]){
  if (argc < 2){
    puts("Usage: db [FILE]");
    return -1;
  }
  // Print welcome message
  welcomeMessage();
  // Read the input file
  char *filename = argv[1]; // the second argument in the command line
  printf("Loading database \"%s\"...\n\n", filename); 
  build(filename);
  // Main loop
  options();
  return 0;
}

void options() {
  int choice = -1;
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
      search();
      break;
    case 2:
      update();
      break;
    case 3:
      insert();
      break;
    case 4:
      delete();
      break;
    case 5:
      print();
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

