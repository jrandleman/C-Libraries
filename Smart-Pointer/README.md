# Smart-Pointer!
## _Provides 4 Fcns for Handling Ptrs With Automated Garbage Collection!_

### Include the Library:
```c
#include "smrtptr.h"
```

### Provides 4 Pointer Functions:
* _**Note**: smart pointers either freed by_ '`smrtptr.h`' _via_ '`atexit()`' _, or prematurely by the user via_ '`smrtfree()`'
```c
// (1) smrtptr()    -- pass an allocated pointer argument    -- freed atexit
char *str = malloc(sizeof(char)*10); 
smrtptr(str);

// (2) smrtmalloc() -- treat like malloc (passing size)      -- freed atexit
int *nums = smrtmalloc(sizeof(int)*10);

// (3) smrtcalloc() -- treat like calloc (passing num, size) -- freed atexit
short *lil = smrtcalloc(10, sizeof(short));

// (4) smrtfree()   -- treat like free -- frees ptr immediately & not atexit
smrtfree(nums);
```
