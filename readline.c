#include "readline.h"
#include <string.h>

int count = 0;

void readline(char *dest, int n, FILE *source){
  if(fgets(dest, n, source) != NULL) {
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
  }else count++;
}
