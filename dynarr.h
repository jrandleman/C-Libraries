/* AUTHOR: JORDAN RANDLEMAN -:- USE LL TO SIMULATE DYNAMIC ARRAY CREATION */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union elum {
	int ida_val;
	char *cda_val;
} ELUM;
typedef struct dyna {
	struct dyna *nixt;
	struct dyna *priv;
	ELUM elim;
} DYNA;
typedef struct dyn_arr {
	DYNA *da_head;
	DYNA *da_tail;
	int da_type;
} DYN_ARR; /* declare locally: DYN_ARR userDynArrName[1]; */

void DA_INIT(DYN_ARR *u_da, char u_da_type) {
	if(u_da_type != 'i' && u_da_type != 'I' && u_da_type != 'c' && u_da_type != 'C') {
		printf("\n\nINCOMPATIBLE DYNAMIC ARRAY TYPE\n=> ENTER 'i' ");
		printf("FOR INT ARRAY\n=> ENTER 'c' FOR CHAR/STR ARRAY\n\n");
		exit(0);
	}
	(u_da_type == 'i' || u_da_type == 'I') ? (u_da -> da_type = 1) : (u_da -> da_type = 0);
	u_da -> da_head = u_da -> da_tail = NULL;
	return; /* init post declare: DA_INIT(userDynArrName, 'i''c') */
}
void DA_DNIT(DYN_ARR *u_da) {
	if(u_da -> da_head != NULL) {
		DYNA *q = u_da -> da_tail;
		while(q -> priv != NULL) {
			DYNA *p = q;
			q = q -> priv;
			q -> nixt = p -> priv = NULL;
			free(p);
		}
		u_da -> da_head = NULL;
	}
	u_da -> da_tail = NULL;
	free(u_da -> da_head);
	free(u_da -> da_tail);
	return; /* free mallocs at end: DA_DNIT(userDynArrName) */
}
/******************************************************************************
* 'L'ENGTH ==> return length of current LL
******************************************************************************/
int _l(DYN_ARR *u_da) {
	int count = 0;
	DYNA *p = u_da -> da_head;
	if(p != NULL) {
		while(p -> nixt != NULL) {
			count++;
			p = p -> nixt;
		}
	}
	return count;
}
/******************************************************************************
* 'I'NDEX ==> return: first index with element true, -1 DNE
******************************************************************************/
int _id(DYN_ARR *u_da, void *value) {
	int count = 0;
	DYNA *p = u_da -> da_head;
	if(p != NULL) {
		while(p -> nixt != NULL) {
			if (u_da -> da_type == 1) {
				if(p -> elim.ida_val == *(int*)value) return count;
			} else {
				if(strcmp(p -> elim.cda_val, value) == 0) return count;
			}
			count++;
			p = p -> nixt;
		}
	}
	return -1;
}
int _ii(DYN_ARR *u_da, int value) { return _id(u_da, &value); }
int _ic(DYN_ARR *u_da, char *value) { return _id(u_da, value); }
/******************************************************************************
* 'E'LEM ==> return: index's elem true, 32202/"32202" DNE ==> -index backwards
******************************************************************************/
void* _ed(DYN_ARR *u_da, int index, int elim_val_type) { 
	int count = 0, i, err_num = 32202;
	void *da_err = &err_num;
	DYNA *p;
	if(u_da -> da_head == NULL) {
		if(elim_val_type == 2) return (void*)"32202";
		return da_err;
	}
	if(index > 0) { /* traverse forwards */
		p = u_da -> da_head;
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> da_tail) {
				if(elim_val_type == 2) return (void*)"32202";
				return da_err;
			}
		if(p == NULL || p == u_da -> da_tail) {
			if(elim_val_type == 1 && p -> elim.ida_val == 80808) {
				return da_err;
			} else if(elim_val_type == 2 && p -> elim.cda_val == '\0') {
				return (void*)"32202";
			}
		}
		if(elim_val_type == 1){
			da_err = &(p -> elim.ida_val);
			return da_err;
		} else {
			return (void*)(p -> elim.cda_val);
		}
		return da_err;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> da_tail -> priv; /* tail empty : dyn node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) {
				if(elim_val_type == 2) return (void*)"32202";
				return da_err;
			}
		if(p == NULL) {
			if(elim_val_type == 1 && p -> elim.ida_val == 80808) {
				return da_err;
			} else if(elim_val_type == 2 && p -> elim.cda_val == '\0') {
				return (void*)"32202";
			}
		}
		if(elim_val_type == 1) {
			da_err = &(p -> elim.ida_val);
			return da_err;
		} else {
			return (void*)(p -> elim.cda_val);
		}
	}
	if(elim_val_type == 1){ /* index = 0 means return da_head elem */
		da_err = &(u_da -> da_head -> elim.ida_val);
		return da_err;
	} else {
		return (void*)(u_da -> da_head -> elim.cda_val);
	}
}
int _ei(DYN_ARR *u_da, int index) { return *(int*)_ed(u_da, index, u_da -> da_type); }
char* _ec(DYN_ARR *u_da, int index) { return _ed(u_da, index, u_da -> da_type); }
/******************************************************************************
* 'P'UT ==> put new value as index's element, return: 1 true, 0 DNE
******************************************************************************/
int _pd(DYN_ARR *u_da, int index, void *value) {
	int count = 0, i;
	DYNA *p = u_da -> da_head;
	for(i = 0; i < index; i++, p = p -> nixt)
		if(p == NULL || p == u_da -> da_tail) return 0;
	if(p == NULL || p == u_da -> da_tail) return 0;
	if(u_da -> da_type == 1) {
		p -> elim.ida_val = *(int*)value;
	} else {
		p -> elim.cda_val = value;
	}
	return 1;
}
int _pi(DYN_ARR *u_da, int index, int value) { return _pd(u_da, index, &value); }
int _pc(DYN_ARR *u_da, int index, char *value) { return _pd(u_da, index, value); }
/******************************************************************************
* 'S'WAP ==> swap idx1 & idx2 elements, return: 1 true, 0 DNE
******************************************************************************/
int _s(DYN_ARR *u_da, int idx1, int idx2) {
	int value1, value2;
	char *val1, *val2;
	if (u_da -> da_type == 1) {
		value1 = _ei(u_da, idx1);
		if(value1 == 32202) return 0;
		value2 = _ei(u_da, idx2);
		if(value2 == 32202) return 0;
		if(_pi(u_da, idx1, value2) == 0 || _pi(u_da, idx2, value1) == 0) return 0;
	} else {
		val1 = _ec(u_da, idx1);
		if(strcmp(val1, "32202") == 0) return 0;
		val2 = _ec(u_da, idx2);
		if(strcmp(val2, "32202") == 0) return 0;
		if(_pc(u_da, idx1, val2) == 0 || _pc(u_da, idx2, val1) == 0) return 0;
	}
	return 1;
}
/******************************************************************************
* TRIM EMPTY CELLS AT THE END OF ARRAYS POST DELETION, ONLY KEEPING LAST BUFFER
******************************************************************************/
void da_trim_cells_(DYN_ARR *u_da) {
	while(u_da -> da_tail -> priv != NULL) {
		if(u_da -> da_type == 1) {
			if(u_da -> da_tail -> priv -> elim.ida_val != 80808) return;
		} else {
			if(strcmp(u_da -> da_tail -> priv -> elim.cda_val, "XQXQX") != 0) return;
		}
		DYNA *q = u_da -> da_tail;
		u_da -> da_tail = u_da -> da_tail -> priv;
		u_da -> da_tail -> nixt = NULL;
		q -> priv = NULL;
		free(q);
	}
	return;
}
/******************************************************************************
* 'D'ELETE ==> return: 1 true, 0 DNE ==> -index backwards
******************************************************************************/
int _d(DYN_ARR *u_da, int index) {
	int count = 0, i;
	DYNA *p;
	if(u_da -> da_head == NULL) return 0;
	if(index > 0) { /* traverse forwards */
		p = u_da -> da_head;
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> da_tail) return 0;
		if(p == NULL || p == u_da -> da_tail) return 0;
		p -> nixt -> priv = p -> priv;
		p -> priv -> nixt = p -> nixt;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> da_tail -> priv; /* tail empty : dyn node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) return 0;
		if(p == NULL) return 0;
		if(p == u_da -> da_head) {
			p -> nixt -> priv = NULL;
			u_da -> da_head = u_da -> da_head -> nixt;
		} else {
			p -> nixt -> priv = p -> priv;
			p -> priv -> nixt = p -> nixt;
		}
	} else { /* index = 0 means delete da_head */
		p = u_da -> da_head;
		p -> nixt -> priv = NULL;
		u_da -> da_head = u_da -> da_head -> nixt;
	}
	free(p);
	da_trim_cells_(u_da);
	return 1;
}
/******************************************************************************
* 'A'DD ==> add value at index
******************************************************************************/
void _ad(DYN_ARR *u_da, int index, void *value) {
	/* EMPTY CELL VALUES */
	DYNA emptyi = { .nixt = NULL, .priv = NULL, .elim.ida_val = 80808 };
	DYNA emptyc = { .nixt = NULL, .priv = NULL, .elim.cda_val = "XQXQX" };
	DYNA *p = (DYNA *)malloc(sizeof(DYNA));
	if(u_da -> da_type == 1) {
		p -> elim.ida_val = *(int*)value;
	} else {
		p -> elim.cda_val = value;
	}
	if(index == 0) { /* insert in front */
		p -> priv = NULL;
		if(u_da -> da_head == NULL) { /* create new LL */
			u_da -> da_head = p;
			u_da -> da_tail = (DYNA *)malloc(sizeof(DYNA));
			if(u_da -> da_type == 1) {
				*(u_da -> da_tail) = emptyi;
			} else {
				*(u_da -> da_tail) = emptyc;
			}
			u_da -> da_head -> nixt = u_da -> da_tail;
			u_da -> da_tail -> priv = u_da -> da_head;
		} else { /* add to front of existing LL */
			u_da -> da_head -> priv = p;
			p -> nixt = u_da -> da_head;
			u_da -> da_head = p;
		}
		p = NULL;
		free(p);
		return;
	}
	DYNA *q = u_da -> da_head;
	int position;
	for(position = 0; position < index; position++, q = q -> nixt) {
		if(u_da -> da_head == NULL) { /* create new LL */
			u_da -> da_head = (DYNA *)malloc(sizeof(DYNA));
			u_da -> da_tail = (DYNA *)malloc(sizeof(DYNA));
			if(u_da -> da_type == 1) {
				*(u_da -> da_head) = emptyi;
				*(u_da -> da_tail) = emptyi;
			} else {
				*(u_da -> da_head) = emptyc;
				*(u_da -> da_tail) = emptyc;
			}
			q = u_da -> da_head;
			u_da -> da_head -> nixt = u_da -> da_tail;
			u_da -> da_tail -> priv = u_da -> da_head;
		} else if(q == u_da -> da_tail) { /* extend LL if index arg>current LL */
			DYNA *end_list_buffer = (DYNA *)malloc(sizeof(DYNA));
			if(u_da -> da_type == 1) {
				*end_list_buffer = emptyi;
			} else {
				*end_list_buffer = emptyc;
			}
			u_da -> da_tail -> nixt = end_list_buffer;
			end_list_buffer -> priv = u_da -> da_tail;
			u_da -> da_tail = end_list_buffer;
			end_list_buffer = NULL;
			free(end_list_buffer);
		}
	}
	p -> nixt = q;
	p -> priv = q -> priv;
	q -> priv -> nixt = p;
	q -> priv = p;
	return;
}
void _ai(DYN_ARR *u_da, int index, int value) { _ad(u_da, index, &value); }
void _ac(DYN_ARR *u_da, int index, char *value) { _ad(u_da, index, value); }
