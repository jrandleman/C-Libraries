/* AUTHOR: JORDAN RANDLEMAN -:- USE LL TO SIMULATE DYNAMIC ARRAY CREATION */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dyni {
	int elem;
	struct dyni *next;
	struct dyni *prev;
} DYNI;

/* GLOBAL VARS -:- blank cell value = pie */
DYNI *headi = NULL, *taili = NULL, empty = { .elem = 314271, .next = NULL, .prev = NULL };

/* FUNCTION PROTOTYPES */
int dai(char *, int, int);

int main() {
	dai("a",0,6); /* 'a'dd 6 to index 0 */
	dai("a",1,5); /* 'a'dd 5 to index 1 */
	dai("d",0,0); /* 'd'elete index 0 */
	printf("%d\n",dai("g",0,0)); /* 'g'et new element at index 0 to printf*/
	dai("a",3,9); /* 'a'dd 9 to index 3 */
	printf("%d\n", dai("g",3,0)); /* 'g'et element at index 3 to printf */
	dai("s",3,4); /* 's'wap element at index 3 with value 4 */
	printf("%d\n", dai("g",3,0)); /* 'g'et element at index 3 to printf */
	dai("d",3,0); /* 'd'elete index 3 */
	printf("%d\n", dai("l",0,0)); /* printf 'l'ength of filled cells (empty non-inclusive) */
	return 0;
}


int dai(char *action, int index, int value) {
	/* "a,A"dd ====> at index add value
	 * "d,D"elete => delete index & ignore value, if -index traverse backwards
	 * "s,S"wap ===> replace element at index with value
	 * "g,G"et ====> return element at index || -40404 if DNE, ignore value, if -index traverse backwards
	 * "l,L"ength => return length of current LL, ignore index & value
	 * */
	if(*action == 'l' || *action == 'L') {
		/**************************************************************************/
		/* 'L'ENGTH */
		/**************************************************************************/
		int count = 0;
		DYNI *p = headi;
		if(p != NULL) {
			while(p -> next != NULL) {
				count++;
				p = p -> next;
			}   
		}   
		return count;
	} else if(*action == 'g' || *action == 'G') {
		/**************************************************************************/
		/* 'G'ET */
		/**************************************************************************/
		int count = 0, i;
		DYNI *p; 
		if(headi == NULL) return -40404; 
		if(index > 0) { /* traverse forwards */
			p = headi;
			for(i = 0; i < index; i++, p = p -> next)
				if(p == NULL || p == taili) return -40404;
			if(p == NULL || p == taili || p -> elem == 314271) return -40404;
			return p -> elem;
		} else if(index < 0) { /* traverse backwards */
			p = taili -> prev; /* taili empty as dynamic node creation buffer */
			for(i = 1; i < -index; i++, p = p -> prev)
				if(p == NULL) return -40404;
			if(p == NULL || p -> elem == 314271) return -40404;
			return p -> elem;
		}
		return headi -> elem; /* index = 0 means return head elem */
	} else if(*action == 'd' || *action == 'D') {
		/**************************************************************************/
		/* 'D'ELETE */
		/**************************************************************************/
		int count = 0, i;
		DYNI *p;
		if(headi == NULL) return -40404;
		if(index > 0) { /* traverse forwards */
			p = headi;
			for(i = 0; i < index; i++, p = p -> next)
				if(p == NULL || p == taili) return -40404;
			if(p == NULL || p == taili) return -40404;
			p -> next -> prev = p -> prev;
			p -> prev -> next = p -> next;
		} else if(index < 0) { /* traverse backwards */
			p = taili -> prev; /* taili empty as dynamic node creation buffer */
			for(i = 1; i < -index; i++, p = p -> prev)
				if(p == NULL) return -40404;
			if(p == NULL) return -40404;
			if(p == headi) {
				p -> next -> prev = NULL;
				headi = headi -> next;
			} else {
				p -> next -> prev = p -> prev;
				p -> prev -> next = p -> next;
			}
		} else { /* index = 0 means delete headi */
			p = headi;
			p -> next -> prev = NULL;
			headi = headi -> next;
		}
		free(p);
		return 1;
		return headi -> elem;
	} else if(*action == 's' || *action == 'S') {
		/**************************************************************************/
		/* 'S'WAP */
		/**************************************************************************/
		int count =0, i;
		DYNI = *p; 
		for(i = 0; i < index; i++, p = p -> next)
			if(p == NULL || p == taili) return -40404;
		if(p == NULL || p == taili) return -40404;
		p -> elem = value;
		return 1;
	} else if(*action != 'a') {
		/**************************************************************************/
		/* EXIT IF INVALID ACTION */
		/**************************************************************************/
		return -40404;
	}
	/******************************************************************************/
	/* 'A'DD */
	/******************************************************************************/
	DYNI *p = (DYNI *)malloc(sizeof(DYNI));
	p -> elem = value;
	if(index == 0) { /* insert in front */
		p -> prev = NULL;
		if(headi == NULL) { /* create new LL */
			headi = p;
			taili = (DYNI *)malloc(sizeof(DYNI));
			*taili = empty;
			headi -> next = taili;
			taili -> prev = headi;
		} else { /* add to front of existing LL */
			headi -> prev = p;
			p -> next = headi;
			headi = p;
		}
		return 1;
	}
	DYNI *q = headi;
	int position;
	for(position = 0; position < index; position++, q = q -> next) {
		if(headi == NULL) { /* create new LL */
			headi = (DYNI *)malloc(sizeof(DYNI));
			taili = (DYNI *)malloc(sizeof(DYNI));
			*headi = empty;
			*taili = empty;
			q = headi;
			headi -> next = taili;
			taili -> prev = headi;
		} else if(q == taili) { /* extend LL if index arg > current LL */
			DYNI *endof = (DYNI *)malloc(sizeof(DYNI));
			*endof = empty;
			taili -> next = endof;
			endof -> prev = taili;
			taili = endof;
		}
	}
	p -> next = q;
	p -> prev = q -> prev;
	q -> prev -> next = p;
	q -> prev = p;
	return 1;
}
