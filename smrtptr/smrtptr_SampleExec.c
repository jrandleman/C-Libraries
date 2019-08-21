// AUTHOR: JORDAN RANDLEMAN -- smrtptr_SampleExec.c -- smrtptr.h library sample execution

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smrtptr.h"

/*
 * "smrtptr.h" provides 4 functions to handle pointers:
 * (1) smrtptr()    -- pass an allocated pointer argument    -- freed atexit
 * (2) smrtmalloc() -- treat like malloc (passing size)      -- freed atexit
 * (3) smrtcalloc() -- treat like calloc (passing num, size) -- freed atexit
 * (4) smrtfree()   -- treat like free -- frees ptr immediately & not atexit
 */

int main() {
  char *str = malloc(sizeof(char) * 5); // convert an allocated pointer to a smart pointer
  smrtptr(str); 

  int *nums = smrtmalloc(sizeof(int) * 3); // malloc a smart pointer

  long *bigNums = smrtcalloc(8, sizeof(long)); // calloc a smart pointer

  smrtfree(nums); // free a smart pointer prior to atexit

  return 0;
}
