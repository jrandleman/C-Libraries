/* AUTHOR: JORDAN RANDLEMAN -:- USE LL TO SIMULATE DYNAMIC ARRAY CREATION */
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
} DYN_ARR; /* declare locally: DYN_ARR userDynArrName[2] */

void I_DYN_ARR_INIT(DYN_ARR *u_da) {
	u_da -> headi = NULL;
	u_da -> taili = NULL;
	return; /* if int arr, init post declare I_DYN_ARR_INIT(userDynArrName) */
}
void C_DYN_ARR_INIT(DYN_ARR *u_da) {
	u_da -> headc = NULL;
	u_da -> tailc = NULL;
	return; /* if char arr, init post declare C_DYN_ARR_INIT(userDynArrName) */
}
void I_DYN_ARR_WIPE(DYN_ARR *u_da) {
	if(u_da -> headi != NULL) {
		DYNI *q = u_da -> taili;
		while(q -> priv != NULL) {
			DYNI *p = q;
			q = q -> priv;
			q -> nixt = NULL;
			p -> priv = NULL;
			free(p);
		}
		u_da -> headi = NULL;
	}
	u_da -> taili = NULL;
	free(u_da -> headi);
	free(u_da -> taili);
	return; /* wipe when done to free mallocs I_DYN_ARR_WIPE(userDynArrName) */
}
void C_DYN_ARR_WIPE(DYN_ARR *u_da) {
	if(u_da -> headc != NULL) {
		DYNC *q = u_da -> tailc;
		while(q -> priv != NULL) {
			DYNC *p = q;
			q = q -> priv;
			q -> nixt = NULL;
			p -> priv = NULL;
			free(p);
		}
		u_da -> headc = NULL;
	}
	u_da -> tailc = NULL;
	free(u_da -> headc);
	free(u_da -> tailc);
	return; /* wipe when done to free mallocs C_DYN_ARR_WIPE(userDynArrName) */
}
/* _actionDatatype(array_name, index, value) */
/******************************************************************************
* 'L'ENGTH ==> return length of current LL
******************************************************************************/
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
* 'I'NDEX ==> return: first index with element true, -1 DNE
******************************************************************************/
int _ii(DYN_ARR *u_da, int value) {
	int count = 0;
	DYNI *p = u_da -> headi;
	if(p != NULL) {
		while(p -> nixt != NULL) {
			if(p -> elim == value) return count;
			count++;
			p = p -> nixt;
		}
	}
	return -1;
}
int _ic(DYN_ARR *u_da, char *value) {
	int count = 0;
	DYNC *p = u_da -> headc;
	if(p != NULL) {
		while(p -> nixt != NULL) {
			if(strcmp(p -> elim, value) == 0) return count;
			count++;
			p = p -> nixt;
		}
	}
	return -1;
}
/******************************************************************************
* 'E'LEM ==> return: index's elem true, 96969/"XQXQX" DNE ==> -index backwards
******************************************************************************/
int _ei(DYN_ARR *u_da, int index) {
	int count = 0, i;
	DYNI *p;
	if(u_da -> headi == NULL) return 96969;
	if(index > 0) { /* traverse forwards */
		p = u_da -> headi;
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> taili) return 96969;
		if(p == NULL || p == u_da -> taili || p -> elim == 80808)return 96969;
		return p -> elim;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> taili -> priv; /* tail empty : dyn node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) return 96969;
		if(p == NULL || p -> elim == 80808) return 96969;
		return p -> elim;
	}
	return u_da -> headi -> elim; /* index = 0 means return headi elem */
}
char* _ec(DYN_ARR *u_da, int index) {
	int count = 0, i;
	DYNC *p;
	if(u_da -> headc == NULL) return "XQXQX";
	if(index > 0) { /* traverse forwards */
		p = u_da -> headc;
		for(i = 0; i < index; i++, p = p -> nixt)
			if(p == NULL || p == u_da -> tailc) return "XQXQX";
		if(p == NULL || p == u_da -> tailc || p -> elim == '\0')return "XQXQX";
		return p -> elim;
	} else if(index < 0) { /* traverse backwards */
		p = u_da -> tailc -> priv; /* tail empty : dyn node creation buffer */
		for(i = 1; i < -index; i++, p = p -> priv)
			if(p == NULL) return "XQXQX";
		if(p == NULL || p -> elim == '\0') return "XQXQX";
		return p -> elim;
	}
	return u_da -> headc -> elim; /* index = 0 means return headc elem */
}
/******************************************************************************
* 'P'UT ==> put new value as index's element, return: 1 true, 0 DNE
******************************************************************************/
int _pi(DYN_ARR *u_da, int index, int value) {
	int count = 0, i;
	DYNI *p = u_da -> headi;
	for(i = 0; i < index; i++, p = p -> nixt)
		if(p == NULL || p == u_da -> taili) return 0;
	if(p == NULL || p == u_da -> taili) return 0;
	p -> elim = value;
	return 1;
}
int _pc(DYN_ARR *u_da, int index, char *value) {
	int count = 0, i;
	DYNC *p = u_da -> headc;
	for(i = 0; i < index; i++, p = p -> nixt)
		if(p == NULL || p == u_da -> tailc) return 0;
	if(p == NULL || p == u_da -> tailc) return 0;
	p -> elim = value;
	return 1;
}
/******************************************************************************
* 'S'WAP ==> swap idx1 & idx2 elements, return: 1 true, 0 DNE
******************************************************************************/
int _si(DYN_ARR *u_da, int idx1, int idx2) {
	int value1 = _ei(u_da, idx1);
	if(value1 == 96969) return 0;
	int value2 = _ei(u_da, idx2);
	if(value2 == 96969) return 0;
	if(_pi(u_da, idx1, value2) == 0 || _pi(u_da, idx2, value1) == 0) return 0;
	return 1;
}
int _sc(DYN_ARR *u_da, int idx1, int idx2) {
	char *value1 = _ec(u_da, idx1);
	if(strcmp(value1, "XQXQX") == 0) return 0;
	char *value2 = _ec(u_da, idx2);
	if(strcmp(value2, "XQXQX") == 0) return 0;
	if(_pc(u_da, idx1, value2) == 0 || _pc(u_da, idx2, value1) == 0) return 0;
	return 1;
}
/******************************************************************************
* 'D'ELETE ==> return: 1 true, 0 DNE ==> -index backwards
******************************************************************************/
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
		p = u_da -> taili -> priv; /* tail empty : dyn node creation buffer */
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
		p = u_da -> tailc -> priv; /* tail empty : dyn node creation buffer */
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
/******************************************************************************
* 'A'DD ==> add value at index
******************************************************************************/
void _ai(DYN_ARR *u_da, int index, int value) {
	/* EMPTY CELL VALUES elimi = "80808" */
	DYNI emptyi = { .elim = 80808, .nixt = NULL, .priv = NULL };
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
		p = NULL;
		free(p);
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
		} else if(q == u_da -> taili) { /* extend LL if index arg>current LL */
			DYNI *endof = (DYNI *)malloc(sizeof(DYNI));
			*endof = emptyi;
			u_da -> taili -> nixt = endof;
			endof -> priv = u_da -> taili;
			u_da -> taili = endof;
			endof = NULL;
			free(endof);
		}
	}
	p -> nixt = q;
	p -> priv = q -> priv;
	q -> priv -> nixt = p;
	q -> priv = p;
	return;
}
void _ac(DYN_ARR *u_da, int index, char *value) {
	/* EMPTY CELL VALUES elimc = "XQXQX" */
	DYNC emptyc = { .elim = "XQXQX", .nixt = NULL, .priv = NULL };
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
		p = NULL;
		free(p);
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
		} else if(q == u_da -> tailc) { /* extend LL if index arg>current LL */
			DYNC *endof = (DYNC *)malloc(sizeof(DYNC));
			*endof = emptyc;
			u_da -> tailc -> nixt = endof;
			endof -> priv = u_da -> tailc;
			u_da -> tailc = endof;
			endof = NULL;
			free(endof);
		}
	}
	p -> nixt = q;
	p -> priv = q -> priv;
	q -> priv -> nixt = p;
	q -> priv = p;
	return;
}
