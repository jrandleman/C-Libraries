# doubly_Linked_List_dynamic_array
Doubly linked list to simulate a dynamically growing array
-----------------------------------------------------------

**Declare locally:** 
1) DYN_ARR user_array_name[2];

**Then initialize "user_array_name" as per 'I'nt or 'C'har array:**
 1) I_DYN_ARR_INIT(user_array_name);
 2) C_DYN_ARR_INIT(user_array_name);

 * **===============================================================**
 * **FUNCTION PROTOTYPES: _actionDatatype(user_array_name, index, value)**
 * **===============================================================**
 * **ACTIONS: 'a'dd - 'd'elete - 'p'ut - 'g'et - 'l'ength**
 * **DATA TYPES: 'i'nt - 'c'har**
 * **===============================================================**

**ADD:**
* void _ai(DYN_ARR *, int, int);
* void _ac(DYN_ARR *, int, char *);
    * _ai(user_array_name, 0, 5);

**DELETE:**
* int _di(DYN_ARR *, int);
* int _dc(DYN_ARR *, int);
    * _di(user_array_name, 0);

**PUT:**
* int _pi(DYN_ARR *, int, int);
* int _pc(DYN_ARR *, int, char *);
    * _pi(user_array_name, 0, 3);

**GET:**
* int _gi(DYN_ARR *, int);
* char* _gc(DYN_ARR *, int);
    * _gi(user_array_name, 0);

**LENGTH:**
* int _li(DYN_ARR *);
* int _lc(DYN_ARR *);
    * li(user_array_name);
