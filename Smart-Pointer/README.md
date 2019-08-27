# Smart-Pointer!
## _Provides 5 Fcns & a Macro Handling Ptrs via Automated Garbage Collection!_
-----------
### Including the Library:
```c
#include "smrtptr.h"
```
### Enabling Alerts & Disabling Asserts:
```c
#define NOISYSMRTPTR // printf's how many smrtptrs were freed atexit
#define NDEBUG       // disables all smrtassert() statements

// must be defined ABOVE the smrtptr.h library to take effect
#include "smrtptr.h"
```
-----------
### Provides 5 Pointer Functions & a Macro:
* _**Note**: smart pointers either freed by_ '`smrtptr.h`' _via_ '`atexit()`' _, or prematurely by the user via_ '`smrtfree()`'
```c
// (1) smrtptr() -- convert an "dumb" allocated ptr arg to "smart" ptr -- freed atexit
char *str = malloc(sizeof(char)*10);
smrtptr(str);


// (2) smrtmalloc() -- treat like malloc (passing size) -- freed atexit
int *nums = smrtmalloc(sizeof(int)*10);


// (3) smrtcalloc() -- treat like calloc (passing num, size) -- freed atexit
short *lil = smrtcalloc(10, sizeof(short));


// (4) smrtrealloc() -- treat like realloc (passing ptr, size) -- freed atexit
//                      compatible with both "dumb" & "smart" pointers!
str = smrtrealloc(str, sizeof(char)*20); // realloc a "smart" ptr
int *digits = malloc(sizeof(int)*10);    // alloc a "dumb" ptr
digits = smrtrealloc(sizeof(int)*20);    // realloc & convert "dumb" ptr to "smart" ptr


// (5) smrtfree() -- treat like free -- frees ptr immediately & not atexit
smrtfree(nums);


// (6) smrtassert() -- performs like assert, but exits rather than abort to free smrtptrs
//                     in this case smrtrealloc actually checks this for us, but for demo's sake
smrtassert(digits != NULL);
```
