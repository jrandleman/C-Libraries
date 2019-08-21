// AUTHOR: JORDAN RANDLEMAN -- smrtptr_SampleExec.c -- smrtptr.h Library Sample Execution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smrtptr.h"

/*
 * "smrtptr.h" provides 5 functions to handle pointers:
 * (1) smrtptr()     -- pass an allocated pointer argument     -- freed atexit
 * (2) smrtmalloc()  -- treat like malloc (passing size)       -- freed atexit
 * (3) smrtcalloc()  -- treat like calloc (passing num, size)  -- freed atexit
 * (4) smrtrealloc() -- treat like realloc (passing ptr, size) -- freed atexit
 *                      compatible w/ both "smart" & "dumb" pointers!
 * (5) smrtfree()    -- treat like free -- frees ptr immediately, & not atexit
 */

int main() {
  // convert an allocated "dumb" pointer to a "smart" pointer
  char *str = malloc(sizeof(char) * 5);
  smrtptr(str); 

  // malloc a smart pointer
  int *nums = smrtmalloc(sizeof(int) * 3); 

  // calloc a smart pointer
  long *bigNums = smrtcalloc(8, sizeof(long)); 

  // free a smart pointer immediately, prior to atexit
  smrtfree(nums); 

  // realloc a smart pointer
  str = smrtrealloc(str, sizeof(char) * 20);

  // malloc a dumb pointer, then realloc & convert it to a smart pointer
  char *temp = malloc(sizeof(char) * 8);
  temp = smrtrealloc(temp, sizeof(char) * 20);

  return 0;
}
