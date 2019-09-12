/* AUTHOR: JORDAN RANDLEMAN -:- USE DOUBLY LL TO SIMULATE DYNAMIC ARRAY CREATION */
/***
 * RESERVED INTEGERS:
 *   => 32202 ("ERROR")
 *   => 8080808 (EMPTY INITIAL VALUE)
 * RESERVED STRINGS:
 *   => "32202" ("ERROR")
 *   => "8080808" (EMPTY INITIAL VALUE)
 *
 * CLIENT-SIDE DYNAMIC ARRAY INTERFACE (fcn names indicate args as well as actions):
 *   => NOTE: da = dynamic arr, dma = dynamic multi-dim array, idx = index, elt = element
 *   => DYNAMIC ARRAY
 *      - DA_INIT        // given a DYN_AR pointer & either 'i' or 'c', initializes dynamic array
 *      - DA_DNIT        // given a DYN_AR pointer, frees all alocated memory (destroying dynamic array)
 *      - da_length      // given da: returns current number of cells
 *      - da_idx_of      // given da, idx, elt: returns "idx" of first "elt" instance in "da"
 *      - da_idx_insert  // given da, idx, elt: allocs & inserts a new "da" cell at "idx" w/ "elt" value
 *      - da_idx_assign  // given da, idx, elt: changes "da"'s current "idx" value to "elt"
 *      - da_idx_delete  // given da & idx: returns 1 success or 0 fail for deleting "da" cell at "idx"
 *      - da_idx_swap    // given da, idx1, & idx2: returns 1 success or 0 fail for swapping elts at "idx1" & "idx2"
 *      - da_idx_ival    // given da & idx, returns int "elt" at "da"'s "idx"
 *      - da_idx_cval    // given da & idx, returns char* "elt" at "da"'s "idx"
 *   => DYNAMIC MULTI-DIMENSIONAL ARRAY
 *      - DMA_INIT       // given a DYN_MAR pointer, number of dynamic arrays, & either 'i' or 'c', initializes dynamic array
 *      - DMA_DNIT       // given a DYN_MAR pointer & number of dynamic arrays, frees all alocated memory (destroying dynamic array)
 *      - dma_length     // see da_length, but w/ "dma" instead of "da"
 *      - dma_idx_of     // see da_idx_of, but w/ "subscripted dma" instead of "da"
 *      - dma_idx_insert // see da_idx_insert, but w/ "subscripted dma" instead of "da"
 *      - dma_idx_assign // see da_idx_assign, but w/ "subscripted dma" instead of "da"
 *      - dma_idx_delete // see da_idx_delete, but w/ "subscripted dma" instead of "da"
 *      - dma_idx_swap   // see da_idx_swap, but w/ "subscripted dma" instead of "da"
 *      - dma_idx_ival   // ee da_idx_ival, but w/ "subscripted dma" instead of "da"
 *      - dma_idx_cval   // ee da_idx_cval, but w/ "subscripted dma" instead of "da"
 */

#ifndef DYNARR_H_
#define DYNARR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* n0() => RVAL NUMBER ADDRESS -:- v4() => RVAL VAR ADDRESS [n0() W/ STR'S] */
#define n0(MAC_NUM_VAL) ({int MAC_NUM_ADDRESS = MAC_NUM_VAL;&MAC_NUM_ADDRESS;})
#define v4(v4_ELEM,v4_TYPE) ({int v44MP = ((v4_TYPE == 1)*(int)v4_ELEM);(void*)&v44MP;})
#define da_idx_of(i_DYNA,i_ELIM)\
	((i_DYNA->da_type == 0)?(dynamicarr_index_of(i_DYNA,(void*)i_ELIM)):(dynamicarr_index_of(i_DYNA,v4(i_ELIM,i_DYNA->da_type))))
#define da_idx_assign(p_DYNA,p_IDX,p_ELIM)\
	((p_DYNA->da_type == 0)?(dynamicarr_index_assign(p_DYNA,p_IDX,(void*)p_ELIM)):(dynamicarr_index_assign(p_DYNA,p_IDX,v4(p_ELIM,p_DYNA->da_type))))
#define da_idx_insert(a_DYNA,a_IDX,a_ELIM)\
	((a_DYNA->da_type == 0)?(dynamicarr_index_push(a_DYNA,a_IDX,(void*)a_ELIM)):(dynamicarr_index_push(a_DYNA,a_IDX,v4(a_ELIM,a_DYNA->da_type))))
#define dma_idx_of(i_DYMA,im_ELIM) (da_idx_of(i_DYMA.d4,im_ELIM))
#define dma_idx_assign(p_DYMA,pm_IDX,pm_ELIM) (da_idx_assign(p_DYMA.d4,pm_IDX,pm_ELIM))
#define dma_idx_insert(a_DYMA,am_IDX,am_ELIM) (da_idx_insert(a_DYMA.d4,am_IDX,am_ELIM))
/******************************************************************************
* DYNA LL NODE 'CELL' STRUCTURE W/ UNION FOR CORRESPONDING INT/CHAR DATA TYPE
******************************************************************************/
typedef union elum {
	int ida_val;
	char *cda_val;
} ELUM;
typedef struct dyna {
	struct dyna *nixt;
	struct dyna *priv;
	ELUM elim;
} DYNA;
/******************************************************************************
* MULTI/SINGLE DYNAMIC ARRAY STRUCTURES FOR LOCAL DECLARTION IN PROGRAM
******************************************************************************/
typedef struct dyn_ar { /* declare: DYN_AR userDynArrName[1]; */
	DYNA *da_head;
	DYNA *da_tail;
	int da_type;
} DYN_AR; 
typedef struct dyn_mar { /* declare: DYN_MAR userDynMultiArrName[USER_SIZE]; */
	DYN_AR d4[1];
	int dyn_mar_size;
} DYN_MAR; /* M(ultiple)AR(rays) ==> 2D array w/ capped columns & infin rows */
/******************************************************************************
* INIT/DEINIT FUNCTIONS TOP/BOT OF PROGRAM (BOTH POST DECLARATION ABOVE)
******************************************************************************/
void DA_INIT(DYN_AR *u_da, char u_da_type) { /* init: DA_INIT(userDynArrName, 'i'/'c') */
	if(u_da_type != 'i' && u_da_type != 'I' && u_da_type != 'c' && u_da_type != 'C') {
		printf("\n\n\033[1m\033[31mERROR\033[0m INCOMPATIBLE DYNAMIC ARRAY TYPE\n=> ENTER 'i' ");
		printf("FOR INT ARRAY\n=> ENTER 'c' FOR CHAR/STR ARRAY\n\n");
		exit(0);
	}
	(u_da_type == 'i' || u_da_type == 'I') ? (u_da -> da_type = 1) : (u_da -> da_type = 0);
	u_da -> da_head = u_da -> da_tail = NULL;
	return; 
}
/* multi(2D)arr init: DMA_INIT(userDynMultiArrName, USER_SIZE, 'i'/'c') */
void DMA_INIT(DYN_MAR *u_da, int size, char u_da_type) {
	u_da -> dyn_mar_size = size;
	for(int i = 0; i < size; i++) 
		DA_INIT(u_da[i].d4, u_da_type);
}
void DA_DNIT(DYN_AR *u_da) { /* deinit ending freeing mallocs: DA_DNIT(userDynArrName) */
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
	return; 
}
/* deinit multi(2D)arr ending freeing mallocs: DMA_DNIT(userDynMultiArrName) */
void DMA_DNIT(DYN_MAR *u_da) { for(int i = 0; i < (u_da -> dyn_mar_size); i++) DA_DNIT(u_da[i].d4); }
/******************************************************************************
* 'L'ENGTH ==> return length of current LL
******************************************************************************/
int da_length(DYN_AR *u_da) {
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
int dynamicarr_index_of(DYN_AR *u_da, void *value) {
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
/******************************************************************************
* 'E'LEM ==> return: index's elem true, 32202/"32202" DNE ==> -index backwards
******************************************************************************/
static void* da_return_index_value(DYN_AR *u_da, int index, int elim_val_type) { 
	int count = 0, i, err_num = 32202;
	void *err_val = &err_num, *gud_val;
	DYNA *p;
	if(u_da -> da_head == NULL) {
		if(elim_val_type == 1) return err_val;
		return (void*)"32202";
	}
	if(index > 0) { /* traverse forwards */
		p = u_da -> da_head;
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> da_tail) {
				if(elim_val_type == 1) return err_val;
				return (void*)"32202";
			}
		if(p == NULL || p == u_da -> da_tail) {
			if(elim_val_type == 1 && p -> elim.ida_val == 8080808) {
				return err_val;
			} else if(elim_val_type == 0 && p -> elim.cda_val == '\0') {
				return (void*)"32202";
			}
		}
		(elim_val_type == 1) ? (gud_val = n0(p -> elim.ida_val)) : (gud_val = (p -> elim.cda_val));
		return gud_val;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> da_tail -> priv; /* tail empty : dyn node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) {
				if(elim_val_type == 1) return err_val;
				return (void*)"32202";
			}
		if(p == NULL) {
			if(elim_val_type == 1 && p -> elim.ida_val == 8080808) {
				return err_val;
			} else if(elim_val_type == 0 && p -> elim.cda_val == '\0') {
				return (void*)"32202";
			}
		}
		(elim_val_type == 1) ? (gud_val = n0(p -> elim.ida_val)) : (gud_val = (p -> elim.cda_val));
		return gud_val;
	}
	if(elim_val_type == 1){ /* index = 0 means return da_head elem */
		return n0(u_da -> da_head -> elim.ida_val);
	} else {
		return (void*)(u_da -> da_head -> elim.cda_val);
	}
}
int da_idx_ival(DYN_AR *u_da, int index) { return *(int*)da_return_index_value(u_da, index, u_da -> da_type); }
char* da_idx_cval(DYN_AR *u_da, int index) { return da_return_index_value(u_da, index, u_da -> da_type); }
/******************************************************************************
* 'P'UT ==> put new value as index's element, return: 1 true, 0 DNE
******************************************************************************/
int dynamicarr_index_assign(DYN_AR *u_da, int index, void *value) {
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
/******************************************************************************
* 'S'WAP ==> swap idx1 & idx2 elements, return: 1 true, 0 DNE
******************************************************************************/
int da_idx_swap(DYN_AR *u_da, int idx1, int idx2) {
	int value1, value2;
	char *val1, *val2;
	if (u_da -> da_type == 1) {
		value1 = da_idx_ival(u_da, idx1);
		if(value1 == 32202) return 0;
		value2 = da_idx_ival(u_da, idx2);
		if(value2 == 32202) return 0;
		if(dynamicarr_index_assign(u_da, idx1, &value2) == 0 || dynamicarr_index_assign(u_da, idx2, &value1) == 0) return 0;
	} else {
		val1 = da_idx_cval(u_da, idx1);
		if(strcmp(val1, "32202") == 0) return 0;
		val2 = da_idx_cval(u_da, idx2);
		if(strcmp(val2, "32202") == 0) return 0;
		if(dynamicarr_index_assign(u_da, idx1, val2) == 0 || dynamicarr_index_assign(u_da, idx2, val1) == 0) return 0;
	}
	return 1;
}
/******************************************************************************
* TRIM EMPTY CELLS AT THE END OF ARRAYS POST DELETION, ONLY KEEPING LAST BUFFER
******************************************************************************/
static void dynamic_arr_trim_cells(DYN_AR *u_da) {
	while(u_da -> da_tail -> priv != NULL) {
		if(u_da -> da_type == 1) {
			if(u_da -> da_tail -> priv -> elim.ida_val != 8080808) return;
		} else {
			if(strcmp(u_da -> da_tail -> priv -> elim.cda_val, "8080808") != 0) return;
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
int da_idx_delete(DYN_AR *u_da, int index) {
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
	dynamic_arr_trim_cells(u_da);
	return 1;
}
/******************************************************************************
* 'A'DD ==> add value at index
******************************************************************************/
void dynamicarr_index_push(DYN_AR *u_da, int index, void *value) {
	/* EMPTY CELL VALUES */
	DYNA emptyi = { .nixt = NULL, .priv = NULL, .elim.ida_val = 8080808 };
	DYNA emptyc = { .nixt = NULL, .priv = NULL, .elim.cda_val = "8080808" };
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
/******************************************************************************
* MULTI ARRAY OF DYNAMIC ARRAYS FUNCTION COUNTERPARTS ==> function_name+'m'
******************************************************************************/
int dma_length(DYN_MAR u_da) { return da_length(u_da.d4); }
int dma_idx_ival(DYN_MAR u_da, int index) { return *(int*)da_return_index_value(u_da.d4, index, u_da.d4 -> da_type); }
char* dma_idx_cval(DYN_MAR u_da, int index) { return da_return_index_value(u_da.d4, index, u_da.d4 -> da_type); }
int dma_idx_swap(DYN_MAR u_da, int idx1, int idx2) { return da_idx_swap(u_da.d4, idx1, idx2); }
int dma_idx_delete(DYN_MAR u_da, int index) { return da_idx_delete(u_da.d4, index); }

#endif
