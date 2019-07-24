// Author: Jordan Randleman - Split-String Library Sample Execution.

#include "split.h"

/******************************************************************************
* SPLIT() SAMPLE EXECUTION FUNCTION
******************************************************************************/

int main() {

  splitHelp(), printf("\n");

  char *str = "yo how are you howard hope your homework went well";

  char** buffer = split(str, "");
  for(int i = 0; buffer[i][0] != '\0'; i++) {
    printf("%s\n", buffer[i]); 
  }
  printf("\n");

  char** ample = split(str, " ");
  for(int i = 0; ample[i][0] != '\0'; i++) {
    printf("%s\n", ample[i]); 
  }
  printf("\n");

  char** sample = split(str, "o");
  for(int i = 0; sample[i][0] != '\0'; i++) {
    printf("%s\n", sample[i]); 
  }
  printf("\n");

  char** examples = split(str, "how");
  for(int i = 0; examples[i][0] != '\0'; i++) {
    printf("%s\n", examples[i]); 
  }
}
