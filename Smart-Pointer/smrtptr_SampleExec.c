// AUTHOR: JORDAN RANDLEMAN -- smrtptr_SampleExec.c -- smrtptr.h Library Sample Execution

#include <stdio.h>
#include <stdlib.h>

// #define NOISYSMRTPTR // tell smrtptr.h to printf how many smrtptrs freed atexit
// #define NDEBUG       // tells smrtptr.h to disable all "smrtassert()" expressions
#include "smrtptr.h"

/**
 * "smrtptr.h" provides 5 functions & a macro to handle pointers:
 *
 * (1) smrtptr()     -- pass an allocated pointer argument     -- freed atexit
 *
 * (2) smrtmalloc()  -- treat like malloc (passing size)       -- freed atexit
 *
 * (3) smrtcalloc()  -- treat like calloc (passing num, size)  -- freed atexit
 *
 * (4) smrtrealloc() -- treat like realloc (passing ptr, size) -- freed atexit
 *                      => compatible w/ both "smart" & "dumb" pointers!
 *
 * (5) smrtfree()    -- treat like free -- frees ptr immediately, & not atexit
 *                      => put "#define NOISYSMRTPTR" B4 "#includ smrtptr.h" 
 *                         to show how many smart pointers were freed
 *
 * (6) smrtassert()  -- performs like assert.h, but frees smrtptrs prior exit
 *                   -- also like assert.h, put "#define NDEBUG" above 
 *                      "#include smrtptr.h" to deactivate all "smrtassert"'s
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

  // assert that temp != NULL, freeing all smart pointers & exiting if not
  // in this case smrtrealloc actually checks this for us, but for demo's sake
  smrtassert(temp != NULL);

  return 0;
}
