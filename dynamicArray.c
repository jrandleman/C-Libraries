/* AUTHOR: JORDAN RANDLEMAN -:- USE LL TO SIMULATE DYNAMIC ARRAY CREATION */
#include <stdio.h> /* NO NEED IN .h FILE */
#include <stdlib.h>
#include <string.h>

typedef struct dyni {
	int elim;
	struct dyni *nixt;
	struct dyni *priv;
} DYNI;

typedef struct dync {
	char *elim;
	struct dync *nixt;
	struct dync *priv;
} DYNC;

typedef struct dyn_arr {
	DYNI *headi;
	DYNI *taili;
	DYNC *headc;
	DYNC *tailc;
} DYN_ARR;

void I_DYN_ARR_INIT(DYN_ARR *u_da) {
	u_da -> headi = NULL;
	u_da -> taili = NULL;
	return;
}

void C_DYN_ARR_INIT(DYN_ARR *u_da) {
	u_da -> headc = NULL;
	u_da -> tailc = NULL;
	return;
}

/* EMPTY CELL VALUES elimi = pie */

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

void _ac(DYN_ARR *, int, char *); /* + index, value */
int _dc(DYN_ARR *, int); /* +- index */
int _sc(DYN_ARR *, int, char *); /* index, newValue */
char* _gc(DYN_ARR *, int); /* +- index */
int _lc(DYN_ARR *);


int main() {
	/* USER-DEFINED DYNAMIC ARRAY */
	DYN_ARR x[2], y[2];

	/* INITIALIZE DEFINED DYNAMIC ARRAYS */
	I_DYN_ARR_INIT(x);
	C_DYN_ARR_INIT(y);

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
	printf("%d\n", _gi(y,0)); /* 'g'et new element at index 0 in array y to printf */

	_ac(y,0,"dude"); /* 'a'dd 'dude' to index 0 in array y */
	_ac(y,1,"sir");
	printf("%s, %s, length: %d\n", _gc(y,0), _gc(y,1), _lc(y)); /* 'g'et new element at index 0 in array y to printf */
	return 0;
}


/***************************************************************************
* 'L'ENGTH ==> return length of current LL
***************************************************************************/
int _li(DYN_ARR *u_da) {
	int count = 0;
	DYNI *p = u_da -> headi;
	if(p != NULL) {
		while(p -> nixt != NULL) {
			count++;
			p = p -> nixt;
		}
	}
	return count;
}
int _lc(DYN_ARR *u_da) {
	int count = 0;
	DYNC *p = u_da -> headc;
	if(p != NULL) {
		while(p -> nixt != NULL) {
			count++;
			p = p -> nixt;
		}
	}
	return count;
}
/******************************************************************************
* 'G'ET ==> return: index's element true, -40404, '\0' DNE ==> -index backwards
******************************************************************************/
int _gi(DYN_ARR *u_da, int index) {
	int count = 0, i;
	DYNI *p;
	if(u_da -> headi == NULL) return -40404;
	if(index > 0) { /* traverse forwards */
		p = u_da -> headi;
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> taili) return -40404;
		if(p == NULL || p == u_da -> taili || p -> elim == 314271) return -40404;
		return p -> elim;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> taili -> priv; /* taili empty as dynamic node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) return -40404;
		if(p == NULL || p -> elim == 314271) return -40404;
		return p -> elim;
	}
	return u_da -> headi -> elim; /* index = 0 means return headi elem */
}
char* _gc(DYN_ARR *u_da, int index) {
	int count = 0, i;
	DYNC *p;
	if(u_da -> headc == NULL) return "EMMPPPTTY\0";
	if(index > 0) { /* traverse forwards */
		p = u_da -> headc;
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> tailc) return "EMMPPPTTY\0";
		if(p == NULL || p == u_da -> tailc || p -> elim == '\0') return "EMMPPPTTY\0";
		return p -> elim;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> tailc -> priv; /* tailc empty as dynamic node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) return "EMMPPPTTY\0";
		if(p == NULL || p -> elim == '\0') return "EMMPPPTTY\0";
		return p -> elim;
	}
	return u_da -> headc -> elim; /* index = 0 means return headc elem */
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
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> taili) return 0;
		if(p == NULL || p == u_da -> taili) return 0;
		p -> nixt -> priv = p -> priv;
		p -> priv -> nixt = p -> nixt;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> taili -> priv; /* taili empty as dynamic node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) return 0;
		if(p == NULL) return 0;
		if(p == u_da -> headi) {
			p -> nixt -> priv = NULL;
			u_da -> headi = u_da -> headi -> nixt;
		} else {
			p -> nixt -> priv = p -> priv;
			p -> priv -> nixt = p -> nixt;
		}
	} else { /* index = 0 means delete headi */
		p = u_da -> headi;
		p -> nixt -> priv = NULL;
		u_da -> headi = u_da -> headi -> nixt;
	}
	free(p);
	return 1;
}
int _dc(DYN_ARR *u_da, int index) {
	int count = 0, i;
	DYNC *p;
	if(u_da -> headc == NULL) return 0;
	if(index > 0) { /* traverse forwards */
		p = u_da -> headc;
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> tailc) return 0;
		if(p == NULL || p == u_da -> tailc) return 0;
		p -> nixt -> priv = p -> priv;
		p -> priv -> nixt = p -> nixt;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> tailc -> priv; /* tailc empty as dynamic node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) return 0;
		if(p == NULL) return 0;
		if(p == u_da -> headc) {
			p -> nixt -> priv = NULL;
			u_da -> headc = u_da -> headc -> nixt;
		} else {
			p -> nixt -> priv = p -> priv;
			p -> priv -> nixt = p -> nixt;
		}
	} else { /* index = 0 means delete headc */
		p = u_da -> headc;
		p -> nixt -> priv = NULL;
		u_da -> headc = u_da -> headc -> nixt;
	}
	free(p);
	return 1;
}
/***************************************************************************
* 'S'WAP ==> swap index's element with new value, return: 1 true, 0 DNE
***************************************************************************/
int _si(DYN_ARR *u_da, int index, int value) {
	int count = 0, i;
	DYNI *p = u_da -> headi;
	for(i = 0; i < index; i++, p = p -> nixt)
		if(p == NULL || p == u_da -> taili) return 0;
	if(p == NULL || p == u_da -> taili) return 0;
	p -> elim = value;
	return 1;
}
int _sc(DYN_ARR *u_da, int index, char *value) {
	int count = 0, i;
	DYNC *p = u_da -> headc;
	for(i = 0; i < index; i++, p = p -> nixt)
		if(p == NULL || p == u_da -> tailc) return 0;
	if(p == NULL || p == u_da -> tailc) return 0;
	p -> elim = value;
	return 1;
}
/*******************************************************************************
* 'A'DD ==> add value at index
*******************************************************************************/
void _ai(DYN_ARR *u_da, int index, int value) {
	/* EMPTY CELL STRUCTURE */
	DYNI emptyi = { .elim = 314271, .nixt = NULL, .priv = NULL };
	DYNC emptyc = { .elim = "EMMPPPTTY\0", .nixt = NULL, .priv = NULL };

	DYNI *p = (DYNI *)malloc(sizeof(DYNI));
	p -> elim = value;
	if(index == 0) { /* insert in front */
		p -> priv = NULL;
		if(u_da -> headi == NULL) { /* create new LL */
			u_da -> headi = p;
			u_da -> taili = (DYNI *)malloc(sizeof(DYNI));
			*(u_da -> taili) = emptyi;
			u_da -> headi -> nixt = u_da -> taili;
			u_da -> taili -> priv = u_da -> headi;
		} else { /* add to front of existing LL */
			u_da -> headi -> priv = p;
			p -> nixt = u_da -> headi;
			u_da -> headi = p;
		}
		return;
	}
	DYNI *q = u_da -> headi;
	int position;
	for(position = 0; position < index; position++, q = q -> nixt) {
		if(u_da -> headi == NULL) { /* create new LL */
			u_da -> headi = (DYNI *)malloc(sizeof(DYNI));
			u_da -> taili = (DYNI *)malloc(sizeof(DYNI));
			*(u_da -> headi) = emptyi;
			*(u_da -> taili) = emptyi;
			q = u_da -> headi;
			u_da -> headi -> nixt = u_da -> taili;
			u_da -> taili -> priv = u_da -> headi;
		} else if(q == u_da -> taili) { /* extend LL if index arg > current LL */
			DYNI *endof = (DYNI *)malloc(sizeof(DYNI));
			*endof = emptyi;
			u_da -> taili -> nixt = endof;
			endof -> priv = u_da -> taili;
			u_da -> taili = endof;
		}
	}
	p -> nixt = q;
	p -> priv = q -> priv;
	q -> priv -> nixt = p;
	q -> priv = p;
	return;
}
void _ac(DYN_ARR *u_da, int index, char *value) {
	/* EMPTY CELL VALUES elimc = "EMMPPPTTY" */
	DYNC emptyc = { .elim = "EMMPPPTTY\0", .nixt = NULL, .priv = NULL };
	DYNC *p = (DYNC *)malloc(sizeof(DYNC));
	p -> elim = value;
	if(index == 0) { /* insert in front */
		p -> priv = NULL;
		if(u_da -> headc == NULL) { /* create new LL */
			u_da -> headc = p;
			u_da -> tailc = (DYNC *)malloc(sizeof(DYNC));
			*(u_da -> tailc) = emptyc;
			u_da -> headc -> nixt = u_da -> tailc;
			u_da -> tailc -> priv = u_da -> headc;
		} else { /* add to front of existing LL */
			u_da -> headc -> priv = p;
			p -> nixt = u_da -> headc;
			u_da -> headc = p;
		}
		return;
	}
	DYNC *q = u_da -> headc;
	int position;
	for(position = 0; position < index; position++, q = q -> nixt) {
		if(u_da -> headc == NULL) { /* create new LL */
			u_da -> headc = (DYNC *)malloc(sizeof(DYNC));
			u_da -> tailc = (DYNC *)malloc(sizeof(DYNC));
			*(u_da -> headc) = emptyc;
			*(u_da -> tailc) = emptyc;
			q = u_da -> headc;
			u_da -> headc -> nixt = u_da -> tailc;
			u_da -> tailc -> priv = u_da -> headc;
		} else if(q == u_da -> tailc) { /* extend LL if index arg > current LL */
			DYNC *endof = (DYNC *)malloc(sizeof(DYNC));
			*endof = emptyc;
			u_da -> tailc -> nixt = endof;
			endof -> priv = u_da -> tailc;
			u_da -> tailc = endof;
		}
	}
	p -> nixt = q;
	p -> priv = q -> priv;
	q -> priv -> nixt = p;
	q -> priv = p;
	return;
}
