# doubly_Linked_List_dynamic_array
Doubly linked list to simulate a dynamically growing array
-----------------------------------------------------------

**Declare locally:** 
1) DYN_ARR user_array_name[2];

**Then initialize "user_array_name" as per 'I'nt or 'C'har array:**
 1) I_DYN_ARR_INIT(user_array_name);
 2) C_DYN_ARR_INIT(user_array_name);
 
 
**Wipe mallocs before ending program as per 'I'nt or 'C'har array:**
 1) I_DYN_ARR_WIPE(user_array_name);
 2) C_DYN_ARR_WIPE(user_array_name);

 * **===============================================================**
 * **FUNCTION PROTOTYPES: _actionDatatype(user_array_name, index, value)**
 * **===============================================================**
 * **ACTIONS: 'a'dd - 'd'elete - 'p'ut - 'l'ength - 'e'lem - 'i'ndex - 's'wap**
 * **DATA TYPES: 'i'nt - 'c'har**
 * **===============================================================**

**ADD (*create new cell*):**
* void _ai(DYN_ARR *, int, int);
* void _ac(DYN_ARR *, int, char *);
    * _ai(user_array_name, index_No, value);

**DELETE (*remove cell*):**
* int _di(DYN_ARR *, int);
* int _dc(DYN_ARR *, int);
    * _di(user_array_name, index_No);

**PUT (*edit existing cell*):**
* int _pi(DYN_ARR *, int, int);
* int _pc(DYN_ARR *, int, char *);
    * _pi(user_array_name, index_No, value);

**LENGTH (*get array length*):**
* int _li(DYN_ARR *);
* int _lc(DYN_ARR *);
    * li(user_array_name);

**ELEM (*get element at an index*):**
* int _ei(DYN_ARR *, int);
* char* _ec(DYN_ARR *, int);
    * _ei(user_array_name, index_No);

**INDEX (*get first index of an element*):**
* int _ii(DYN_ARR *, int);
* char* _ic(DYN_ARR *, char *);
    * _ii(user_array_name, value);

**SWAP (*swap two cell positions*):**
* int _si(DYN_ARR *, int, int);
* int _sc(DYN_ARR *, int, int);
    * _si(user_array_name, index_No1, index_No2);
