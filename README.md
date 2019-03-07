# doubly_Linked_List_dynamic_array
Doubly linked list to simulate a dynamically growing array
-----------------------------------------------------------

**Declare locally:** 
1) DYN_ARR userArrName[2];

**Initialize "userArrName" as per 'I'nt or 'C'har array:**
 1) I_DYN_ARR_INIT(userArrName);
 2) C_DYN_ARR_INIT(userArrName);

 * **=================================================================**
 * **FUNCTION PROTOTYPES: _actionDatatype(array_name, index, value)**
 * **=================================================================**
 * **ACTIONS: 'a'dd - 'd'elete - 's'wap - 'g'et - 'l'ength**
 * **DATA TYPES: 'i'nt - 'c'har**
 * **=============================================================**

**ADD:**
* void _ai(DYN_ARR *, int, int);
* void _ac(DYN_ARR *, int, char *);
    * _ai(userArrName, 0, 5);

**DELETE:**
* int _di(DYN_ARR *, int);
* int _dc(DYN_ARR *, int);
    * _di(userArrName, 0);

**SWAP:**
* int _si(DYN_ARR *, int, int);
* int _sc(DYN_ARR *, int, char *);
    * _si(userArrName, 0, 3);

**GET:**
* int _gi(DYN_ARR *, int);
* char* _gc(DYN_ARR *, int);
    * _gi(userArrName, 0);

**LENGTH:**
* int _li(DYN_ARR *);
* int _lc(DYN_ARR *);
    * li(userArrName);
