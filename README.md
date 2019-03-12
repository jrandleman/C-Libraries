# doubly_Linked_List_dynamic_array
Doubly linked list to simulate a dynamically growing array
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
**FUNCTION PROTOTYPES: _actionDatatype(user_array_name, index, [n0(int) || char \*])**<br/>
**===============================================================**<br/>
**ACTIONS: 'a'dd - 'd'elete - 'p'ut - 'l'ength - 'e'lem - 'i'ndex - 's'wap**<br/>
**DATA TYPES: 'i'nt - 'c'har => wrap int elements with n0(#) when passing to functions**<br/>
**===============================================================**<br/>

**ADD (*create new cell*):**
* void _a(user_array_name, index_No, [n0(int) || char *]);
    * _a(user_array_name, 0, n0(1));
    * _a(user_array_name, 0, "one");

**DELETE (*remove cell*):**
* int _d(user_array_name, index_No);
    * _d(user_array_name, 1);

**PUT (*edit existing cell*):**
* int _p(user_array_name, index_No, [n0(int) || char *]);
    * _p(user_array_name, 0, n0(1));
    * _p(user_array_name, 0, "one");

**LENGTH (*get array length*):**
* int _l(user_array_name);
    * _l(user_array_name);

**ELEM (*get element at an index*):**
* int _ei(user_array_name, index_No);
* char* _ec(user_array_name, index_No);
    * _ei(user_array_name, 0);
    * _ec(user_array_name, 0);
* **_=> returns 32202/"32202" 'ERROR' if element DNE_** 

**INDEX (*get first index of an element*):**
* int _i(user_array_name, [n0(int) || char *]);
    * _i(user_array_name, n0(1));
    * _i(user_array_name, "one");

**SWAP (*swap two cell positions*):**
* int _s(user_array_name, index_No1, index_No2);
    * _s(user_array_name, 0, 1);

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
 
 **FUNCTIONALITY => Identical to 1D, save for 3 key changes:**
1) All func names end with 'm' ['m'ulti-Dim]
2) All take ACCESS_INDEX of specific dynamic array to alter in 2D marray
    * _l(user_array_name); => _lm(user_marray_name[ACCESS_INDEX]);
3) 'add' function [\_am()] takes ADDRESS of user_marray_name with '&':
    * _am(&user_marray_name[ACCESS_INDEX],0,n0(1));
