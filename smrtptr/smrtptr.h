// AUTHOR: JORDAN RANDLEMAN -- smrtptr.h -- auto pointer-freeing library

#ifndef SMRTPTR_H_
#define SMRTPTR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * "smrtptr.h" provides 4 functions to handle pointers:
 * (1) smrtptr()    -- pass an allocated pointer argument    -- freed atexit
 * (2) smrtmalloc() -- treat like malloc (passing size)      -- freed atexit
 * (3) smrtcalloc() -- treat like calloc (passing num, size) -- freed atexit
 * (4) smrtfree()   -- treat like free -- frees ptr immediately & not atexit
 */

// garbage collector & smart pointer storage struct
static struct SMRTPTR_GARBAGE_COLLECTOR {
  long len, max; // current # of ptrs && max capacity
  void **ptrs;   // unique ptr set to free all smrt ptrs
} SMRTPTR_GC = {-1};

// invoked by atexit to free all ctor-alloc'd memory
static void smrtptr_free_all() { 
  int i = 0;
  for(; i < SMRTPTR_GC.len; ++i) free(SMRTPTR_GC.ptrs[i]);
  if(SMRTPTR_GC.len > 0) free(SMRTPTR_GC.ptrs);
  // if(SMRTPTR_GC.len > 0) printf("FREED %ld SMART POINTERS!\n", SMRTPTR_GC.len); // optional
  SMRTPTR_GC.len = 0;
}

// smrtptr stores ptr passed as arg to be freed atexit
void smrtptr(void *ptr) { 
  // free ptrs atexit
  atexit(smrtptr_free_all);
  // malloc garbage collector
  if(SMRTPTR_GC.len == -1) {
    SMRTPTR_GC.ptrs = malloc(sizeof(void *) * 10);
    if(!SMRTPTR_GC.ptrs) {
      fprintf(stderr, "-:- ERROR: COULDN'T MALLOC MEMORY FOR SMRTPTR.H'S GARBAGE COLLECTOR -:-\n");
      exit(EXIT_FAILURE);
    }
    SMRTPTR_GC.max = 10, SMRTPTR_GC.len = 0;
  }
  // reallocate if "max" ptrs already added
  if(SMRTPTR_GC.len == SMRTPTR_GC.max) { 
    SMRTPTR_GC.max *= SMRTPTR_GC.max;
    void **SMRTPTR_TEMP = realloc(SMRTPTR_GC.ptrs, sizeof(void *) * SMRTPTR_GC.max);
    if(!SMRTPTR_TEMP) {
      fprintf(stderr, "-:- ERROR: COULDN'T REALLOC FOR SMRTPTR.H'S GARBAGE COLLECTOR -:-\n");
      fprintf(stderr, "-:- FREEING ALLOCATED MEMORY THUS FAR AND TERMINATING PROGRAM -:-\n");
      exit(EXIT_FAILURE); // still frees any ptrs allocated thus far
    }
    SMRTPTR_GC.ptrs = SMRTPTR_TEMP;
  }
  // add ptr to SMRTPTR_GC if not already present (ensures no double-freeing)
  int i = 0; 
  for(; i < SMRTPTR_GC.len; ++i) if(SMRTPTR_GC.ptrs[i] == ptr) return;
  SMRTPTR_GC.ptrs[SMRTPTR_GC.len++] = ptr;
}

// malloc's a pointer, stores it in the garbage collector, then returns ptr
void *smrtmalloc(size_t alloc_size) {
  void *smtr_malloced_ptr = malloc(alloc_size);
  if(smtr_malloced_ptr == NULL) {
    fprintf(stderr, "-:- ERROR: COULDN'T MALLOC MEMORY FOR SMRTPTR.H'S SMRTMALLOC FUNCTION -:-\n");
    exit(EXIT_FAILURE);
  }
  smrtptr(smtr_malloced_ptr);
  return smtr_malloced_ptr;
}

// calloc's a pointer, stores it in the garbage collector, then returns ptr
void *smrtcalloc(size_t alloc_num, size_t alloc_size) {
  void *smtr_calloced_ptr = calloc(alloc_num, alloc_size);
  if(smtr_calloced_ptr == NULL) {
    fprintf(stderr, "-:- ERROR: COULDN'T CALLOC MEMORY FOR SMRTPTR.H'S SMRTCALLOC FUNCTION -:-\n");
    exit(EXIT_FAILURE);
  }
  smrtptr(smtr_calloced_ptr);
  return smtr_calloced_ptr;
}

// prematurely frees ptr arg prior to atexit (if exists)
void smrtfree(void *ptr) {
  int i = 0, j;
  for(; i < SMRTPTR_GC.len; ++i) // find ptr in garbage collector
    if(SMRTPTR_GC.ptrs[i] == ptr) {
      free(ptr);
      for(j = i; j < SMRTPTR_GC.len - 1; ++j) // shift ptrs down
        SMRTPTR_GC.ptrs[j] = SMRTPTR_GC.ptrs[j + 1];
      SMRTPTR_GC.len--;
      return;
    }
}

#endif
