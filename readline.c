#include "readline.h"
#include <string.h>

<<<<<<< HEAD
int count = 0;

void readline(char *dest, int n, FILE *source){
  if(fgets(dest, n, source) != NULL) {
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
  }else count++;
=======
void readline(char *dest, int n, FILE *source){
  fgets(dest, n, source);
  int len = strlen(dest);
  if(dest[len-1] == '\n')
    dest[len-1] = '\0';
>>>>>>> 1ee905749c4553e5acf3de72c734dede009b3c36
}
