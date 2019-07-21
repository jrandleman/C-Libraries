# doubly_Linked_List_dynamic_array
_Doubly linked list to simulate a dynamically growing array!_
-----------------------------------------------------------

**Include Library:**
```c
#include "dynarr.h"
```
**Declare locally:**
```c
DYN_AR user_array_name[1];
```
**Then initialize "user_array_name" as per 'I'nt or 'C'har array:**
```c
DA_INIT(user_array_name, 'i'); // initialize 'i'nt array
DA_INIT(user_array_name, 'c'); // initialize 'c'har array
```
 
**Deinitialize mallocs before ending program:**
```c
DA_DNIT(user_array_name);
```

**===============================================================**<br/>
**FUNCTION PROTOTYPES: _actionDatatype(user_array_name, index, [int || char \*])**<br/>
**===============================================================**<br/>
**ACTIONS: add - del - put - len - elt - idx - swap**<br/>
**DATA TYPES: 'i'nt - 'c'har**<br/>
**===============================================================**<br/>

**ADD (*create new cell*):**</br>
void _add(user_array_name, index_No, [int || char *]);
```c
_add(user_array_name, 0, 1);
_add(user_array_name, 0, "one");
```

**DELETE (*remove cell*):**</br>
int _del(user_array_name, index_No);
```c
_del(user_array_name, 1);
```

**PUT (*edit existing cell*):**</br>
int _put(user_array_name, index_No, [int || char *]);
```c
_put(user_array_name, 0, 1);
_put(user_array_name, 0, "one");
```

**LENGTH (*get array length*):**</br>
int _len(user_array_name);
```c
_len(user_array_name);
```

**ELEM (*get element at an index*):**</br>
int _elti(user_array_name, index_No);</br>
char* _eltc(user_array_name, index_No);
```c
_elti(user_array_name, 0);
_eltc(user_array_name, 0);
```
* **_=> returns 32202/"32202" 'ERROR' if element DNE_** 

**INDEX (*get first index of an element*):**</br>
int _idx(user_array_name, [int || char *]);
```c
_idx(user_array_name, 1);
_idx(user_array_name, "one");
```

**SWAP (*swap two cell positions*):**</br>
int _swap(user_array_name, index_No1, index_No2);
```c
_swap(user_array_name, 0, 1);
```

**===============================================================**<br/>
_**MULTIDIMENSIONAL DYNAMIC ARRAYS:**_
**===============================================================**<br/>
**Local Declaration:**<br/>
```c
DYN_MAR user_marray_name[USER_MAR_SIZE];
```
_=> M(ultiple)AR(rays)_

**Initialization post-declaration:**
```c
DMA_INIT(user_marray_name, USER_MAR_SIZE, 'i'); // initialize 'i'nt multi-dimensional array
DMA_INIT(user_marray_name, USER_MAR_SIZE, 'c'); // initialize 'c'har multi-dimensional array
```
 
 
**Deinitialization before ending program:**
```c
DMA_DNIT(user_marray_name);
```
 
 **FUNCTIONALITY => Identical to 1D, save for 2 key changes:**
1) All func names end with 'm' ['m'ulti-Dim]
2) All take ACCESS_INDEX of specific dynamic array to alter in 2D marray
```c
_len(user_array_name); // Becomes:
_lenm(user_marray_name[ACCESS_INDEX]);
```
