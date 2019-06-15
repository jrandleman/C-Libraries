# doubly_Linked_List_dynamic_array
_Doubly linked list to simulate a dynamically growing array!_
-----------------------------------------------------------

**Include Library:**
#include "dynarr.h"

**Declare locally:**
DYN_AR user_array_name[1];

**Then initialize "user_array_name" as per 'I'nt or 'C'har array:**
 1) DA_INIT(user_array_name, 'i');
 2) DA_INIT(user_array_name, 'c');
 
 
**Deinitialize mallocs before ending program:**
 1) DA_DNIT(user_array_name);

**===============================================================**<br/>
**FUNCTION PROTOTYPES: _actionDatatype(user_array_name, index, [int || char \*])**<br/>
**===============================================================**<br/>
**ACTIONS: add - del - put - len - elt - idx - swap**<br/>
**DATA TYPES: 'i'nt - 'c'har**<br/>
**===============================================================**<br/>

**ADD (*create new cell*):**
* void _add(user_array_name, index_No, [int || char *]);
    * _add(user_array_name, 0, 1);
    * _add(user_array_name, 0, "one");

**DELETE (*remove cell*):**
* int _del(user_array_name, index_No);
    * _del(user_array_name, 1);

**PUT (*edit existing cell*):**
* int _put(user_array_name, index_No, [int || char *]);
    * _put(user_array_name, 0, 1);
    * _put(user_array_name, 0, "one");

**LENGTH (*get array length*):**
* int _len(user_array_name);
    * _len(user_array_name);

**ELEM (*get element at an index*):**
* int _elti(user_array_name, index_No);
* char* _eltc(user_array_name, index_No);
    * _elti(user_array_name, 0);
    * _eltc(user_array_name, 0);
* **_=> returns 32202/"32202" 'ERROR' if element DNE_** 

**INDEX (*get first index of an element*):**
* int _idx(user_array_name, [int || char *]);
    * _idx(user_array_name, 1);
    * _idx(user_array_name, "one");

**SWAP (*swap two cell positions*):**
* int _swap(user_array_name, index_No1, index_No2);
    * _swap(user_array_name, 0, 1);

**===============================================================**<br/>
_**MULTIDIMENSIONAL DYNAMIC ARRAYS:**_
**===============================================================**<br/>
**Local Declaration:**<br/>
DYN_MAR user_marray_name[USER_MAR_SIZE];<br/>
_=> M(ultiple)AR(rays)_

**Initialization post-declaration:**
 1) DMA_INIT(user_marray_name, USER_MAR_SIZE, 'i');
 2) DMA_INIT(user_marray_name, USER_MAR_SIZE, 'c');
 
 
**Deinitialization before ending program:**
 1) DMA_DNIT(user_marray_name);
 
 **FUNCTIONALITY => Identical to 1D, save for 2 key changes:**
1) All func names end with 'm' ['m'ulti-Dim]
2) All take ACCESS_INDEX of specific dynamic array to alter in 2D marray
    * _len(user_marray_name); => _lenm(user_marray_name[ACCESS_INDEX]);
