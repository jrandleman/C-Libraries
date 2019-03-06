/* AUTHOR: JORDAN RANDLEMAN -:- USE LL TO SIMULATE DYNAMIC ARRAY CREATION */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dyni {
	int elem;
	struct dyni *next;
	struct dyni *prev;
} DYNI;

typedef struct dyn_arr {
	DYNI *headi;
	DYNI *taili;
} DYN_ARR;

/* EMPTY CELL VALUES elemi = pie */
DYNI emptyi = { .elem = 314271, .next = NULL, .prev = NULL };

void _DYN_ARR_INIT(DYN_ARR *u_da) {
	u_da -> headi = NULL;
	u_da -> taili = NULL;
	return;
}

/* =================================================================
 * FUNCTION PROTOTYPES: _actionDatatype(array_name, index, value) */
/* =================================================================
 * ACTIONS:    || DATA TYPES:
 *   'a'dd     ||   'i'nt
 *   'd'elete  ||   'c'har
 *   's'wap    ||
 *   'g'et     ||
 *   'l'ength  ||
 * ============================================================= */
void _ai(DYN_ARR *, int, int); /* + index, value */
int _di(DYN_ARR *, int); /* +- index */
int _si(DYN_ARR *, int, int); /* index, newValue */
int _gi(DYN_ARR *, int); /* +- index */
int _li(DYN_ARR *);


int main() {
	/* USER-DEFINED DYNAMIC ARRAY */
	DYN_ARR x[2], y[2];

	/* INITIALIZE DEFINED DYNAMIC ARRAYS */
	_DYN_ARR_INIT(x);
	_DYN_ARR_INIT(y);

	_ai(x,0,6); /* 'a'dd 6 to index 0 in array x */
	_ai(x,1,5); /* 'a'dd 5 to index 1 in array x */
	_di(x,0); /* 'd'elete index 0 in array x */
	printf("%d\n", _gi(x,0)); /* 'g'et new element at index 0 in array x to printf*/
	_ai(x,3,9); /* 'a'dd 9 to index 3 */
	printf("%d\n", _gi(x,3)); /* 'g'et element at index 3 in array x to printf */
	_si(x,3,4); /* 's'wap element at index 3 with value 4 in array x */
	printf("%d\n", _gi(x,3)); /* 'g'et element at index 3 in array x to printf */
	_di(x,3); /* 'd'elete index 3 */
	printf("%d\n", _li(x)); /* printf 'l'ength of filled cells (empty non-inclusive) in array x */

	_ai(y,0,6); /* 'a'dd 6 to index 0 in array y */
	printf("%d\n", _gi(y,0)); /* 'g'et new element at index 0 in array y to printf*/
	return 0;
}


/***************************************************************************
* 'L'ENGTH ==> return length of current LL
***************************************************************************/
int _li(DYN_ARR *u_da) {
	int count = 0;
	DYNI *p = u_da -> headi;
	if(p != NULL) {
		while(p -> next != NULL) {
			count++;
			p = p -> next;
		}
	}
	return count;
}
/**************************************************************************
* 'G'ET ==> return: index's element true, -40404 DNE ==> -index backwards
***************************************************************************/
int _gi(DYN_ARR *u_da, int index) {
	int count = 0, i;
	DYNI *p;
	if(u_da -> headi == NULL) return -40404;
	if(index > 0) { /* traverse forwards */
		p = u_da -> headi;
		for(i = 0; i < index; i++, p = p -> next)
			if(p == NULL || p == u_da -> taili) return -40404;
		if(p == NULL || p == u_da -> taili || p -> elem == 314271) return -40404;
		return p -> elem;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> taili -> prev; /* taili empty as dynamic node creation buffer */
		for(i = 1; i < -index; i++, p = p -> prev)
			if(p == NULL) return -40404;
		if(p == NULL || p -> elem == 314271) return -40404;
		return p -> elem;
	}
	return u_da -> headi -> elem; /* index = 0 means return headi elem */
}
/**************************************************************************
* 'D'ELETE ==> return: 1 true, 0 DNE ==> -index backwards
***************************************************************************/
int _di(DYN_ARR *u_da, int index) {
	int count = 0, i;
	DYNI *p;
	if(u_da -> headi == NULL) return 0;
	if(index > 0) { /* traverse forwards */
		p = u_da -> headi;
		for(i = 0; i < index; i++, p = p -> next)
			if(p == NULL || p == u_da -> taili) return 0;
		if(p == NULL || p == u_da -> taili) return 0;
		p -> next -> prev = p -> prev;
		p -> prev -> next = p -> next;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> taili -> prev; /* taili empty as dynamic node creation buffer */
		for(i = 1; i < -index; i++, p = p -> prev)
			if(p == NULL) return 0;
		if(p == NULL) return 0;
		if(p == u_da -> headi) {
			p -> next -> prev = NULL;
			u_da -> headi = u_da -> headi -> next;
		} else {
			p -> next -> prev = p -> prev;
			p -> prev -> next = p -> next;
		}
	} else { /* index = 0 means delete headi */
		p = u_da -> headi;
		p -> next -> prev = NULL;
		u_da -> headi = u_da -> headi -> next;
	}
	free(p);
	return 1;
	return u_da -> headi -> elem;
}
/***************************************************************************
* 'S'WAP ==> swap index's element with new value, return: 1 true, 0 DNE
***************************************************************************/
int _si(DYN_ARR *u_da, int index, int value) {
	int count = 0, i;
	DYNI *p = u_da -> headi;
	for(i = 0; i < index; i++, p = p -> next)
		if(p == NULL || p == u_da -> taili) return 0;
	if(p == NULL || p == u_da -> taili) return 0;
	p -> elem = value;
	return 1;
}
/*******************************************************************************
* 'A'DD ==> add value at index
*******************************************************************************/
void _ai(DYN_ARR *u_da, int index, int value) {
	DYNI *p = (DYNI *)malloc(sizeof(DYNI));
	p -> elem = value;
	if(index == 0) { /* insert in front */
		p -> prev = NULL;
		if(u_da -> headi == NULL) { /* create new LL */
			u_da -> headi = p;
			u_da -> taili = (DYNI *)malloc(sizeof(DYNI));
			*(u_da -> taili) = emptyi;
			u_da -> headi -> next = u_da -> taili;
			u_da -> taili -> prev = u_da -> headi;
		} else { /* add to front of existing LL */
			u_da -> headi -> prev = p;
			p -> next = u_da -> headi;
			u_da -> headi = p;
		}
		return;
	}
	DYNI *q = u_da -> headi;
	int position;
	for(position = 0; position < index; position++, q = q -> next) {
		if(u_da -> headi == NULL) { /* create new LL */
			u_da -> headi = (DYNI *)malloc(sizeof(DYNI));
			u_da -> taili = (DYNI *)malloc(sizeof(DYNI));
			*(u_da -> headi) = emptyi;
			*(u_da -> taili) = emptyi;
			q = u_da -> headi;
			u_da -> headi -> next = u_da -> taili;
			u_da -> taili -> prev = u_da -> headi;
		} else if(q == u_da -> taili) { /* extend LL if index arg > current LL */
			DYNI *endof = (DYNI *)malloc(sizeof(DYNI));
			*endof = emptyi;
			u_da -> taili -> next = endof;
			endof -> prev = u_da -> taili;
			u_da -> taili = endof;
		}
	}
	p -> next = q;
	p -> prev = q -> prev;
	q -> prev -> next = p;
	q -> prev = p;
	return;
}
