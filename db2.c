#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary.h"

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


