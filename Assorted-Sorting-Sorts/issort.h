/* AUTHOR: JORDAN RANDLEMAN -:- SORT-FUNCTIONS/BSEARCH FOR INTEGERS AND WORDS IN A STRING */
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define issort_swap(X,Y) ({int TEMP;(TEMP)=(X);(X)=(Y);(Y)=(TEMP);})
#define issort_sswap(X,Y) ({char TEMP[strlen(X)];strcpy(TEMP,X);strcpy(X,Y);strcpy(Y,TEMP);})
#define Q2SSCANF(STR,MATRIX) ({int i=0,j=0,LEN=strlen(STR);while(i<LEN){sscanf(&STR[i],"%s",MATRIX[j++]);i+=(strlen(MATRIX[j-1])+1);}j;}) /* words: 1D->2D */
#define Q2SPRINTF(STR,MATRIX,LEN) ({int i=0,j=0;for(;i<LEN;i++){sprintf(&STR[j],"%s ",MATRIX[i]);j+=(strlen(MATRIX[i])+1);}STR[j-1]='\0';}) /* words: 2D->1D */
int __W8__ = 1;
int loW8(int x,int y) {return((((x%__W8__)==0)^((y%__W8__)==0))==1)?((x%__W8__)==0):(x<y);}
int hiW8(int x,int y) {return((((x%__W8__)==0)^((y%__W8__)==0))==1)?((x%__W8__)==0):(x>y);}
int cmpstr(char *x, char *y) {return (-1)*strcmp(x,y);}
/*
SORT FCN NAMES:
	(1) BUBBLE (2) SELECT (3) INSERT (4) SHELL (5) QUICK (6) HEAP (7) MERGE (8) HASH
============================================================================================
SORT NAME EXTENSIONS:
	=> "_sort" (integers) && "_ssort" (string's words)
============================================================================================
SORT ARGUMENTS:
	(int/char array[], int size, int (*your_Compare_Fcn)())
	=> SIZE: only for integers
	=> CMP FCN: if desired, pre-made fcns are available above:
		- loW8/hiW8 (ascending/descending) fcns for biased int sorting
			* bias: towards multiples of the global __W8__ value (assign pre-sort)
		- cmpstr fcn for ascending words in a string sorting (opposite strcmp)
============================================================================================
BINARY SEARCH FCNS: (bin_search => ints && bin_ssearch => string's words)
	=> int idx = bin_search(findThis, array, length {only for ints}, &found, &your_Cmp_Fcn);
*/
/******************************************************************************
* BUBBLE SORT -:- BEST: O(n) & WORST: O(n^2) -:- STABLE
	- "bubble-up" values, swapping only with adjacent cells
	- flag checks if any swaps made in case array's fully sorted
******************************************************************************/
void bubble_sort(int a[], int n, int (*cmp)()) {
	int i, j, flag = 0;
	for(i = 0; i < n-1 && flag == 0; i++) for(flag = 1, j = n-1; j > i; j--)
		if((*cmp)(a[j],a[j-1]) > 0) {issort_swap(a[j], a[j-1]); flag = 0;}
}
void bubble_ssort(char a[], int (*cmp)()) {
	char m[strlen(a)][strlen(a)];
	int i, j, flag = 0, n = Q2SSCANF(a, m);
	for(i = 0; i < n-1 && flag == 0; i++) for(flag = 1, j = n-1; j > i; j--)
		if((*cmp)(m[j],m[j-1]) > 0) {issort_sswap(m[j], m[j-1]); flag = 0;}
	Q2SPRINTF(a, m, n);
}
/******************************************************************************
* SELECTION SORT -:- BEST & WORST: O(n^2) -:- UNSTABLE
	- mv wall 0 to n-1, find best value ahead of wall & swap with wall's value
******************************************************************************/
void select_sort(int a[], int n, int (*cmp)()) {
	int i, j, min;
	for(i = 0; i < n - 1; i++) {
		for(min = i, j = i + 1; j < n; j++) if((*cmp)(a[j], a[min]) > 0) min = j;
		if(min != i) issort_swap(a[min], a[i]);
	}
}
void select_ssort(char a[], int (*cmp)()) {
	char m[strlen(a)][strlen(a)];
	int i, j, min, n = Q2SSCANF(a, m);
	for(i = 0; i < n - 1; i++) {
		for(min = i, j = i + 1; j < n; j++) if((*cmp)(m[j], m[min]) > 0) min = j;
		if(min != i) issort_sswap(m[min], m[i]);
	}
	Q2SPRINTF(a, m, n);
}
/******************************************************************************
* INSERTION SORT -:- BEST: O(n) & WORST: O(n^2) -:- STABLE
	- mv wall 0 to n-1, placing wall's value in sorted position behind wall
******************************************************************************/
void insert_sort(int a[], int n, int (*cmp)()) {
	int i, j, temp;
	for(i = 1; i < n; i++) {
		for(temp = a[i], j = i-1; j >= 0 && (*cmp)(temp, a[j]) > 0; j--) a[j+1] = a[j];
		a[j+1] = temp;
	}
}
void insert_ssort(char a[], int (*cmp)()) {
	char m[strlen(a)][strlen(a)];
	int i, j, n = Q2SSCANF(a, m);
	for(i = 1; i < n; i++) {
		char temp[strlen(m[i])];
		for(strcpy(temp,m[i]), j=i-1; j>=0 && (*cmp)(temp,m[j])>0; j--) strcpy(m[j+1], m[j]);
		strcpy(m[j+1], temp);
	}
	Q2SPRINTF(a, m, n);
}
/******************************************************************************
* SHELL SORT -:- BEST: O(nlogn) & WORST: O(Quadratic) -:- UNSTABLE
	- insert sort gradually decreasing "k"-number of sections of the array
	- "k" values derived (and extended) from Ciura's Sequence
******************************************************************************/
static int init_shell_k_values(int k[], int n) {
	int i, CiuraSeq[] = {1, 4, 10, 23, 57, 132, 301, 701};
	for(i = 0; i < 8 && CiuraSeq[i] < n; i++) k[i] = CiuraSeq[i];
	i--; while(k[i] < n) { k[i+1] = k[i] * 100 / 43; i++; }
	return i;
}
void shell_sort(int a[], int n, int (*cmp)()) {
	int k[n], k_total = init_shell_k_values(k, n), i, j, l, shell;
	for(i = k_total - 1; i >= 0; i--) { /* for each k value */
		for(shell = 0; shell < k[i]; shell++) { /* for each shell */
			for(l = k[i] + shell; l < n; l += k[i]) { /* insertion sort */
				int temp = a[l];
				for(j = l-k[i]; j >= 0 && (*cmp)(temp,a[j])>0; j-=k[i]) a[j+k[i]] = a[j];
				a[j+k[i]] = temp;
			}
		}
	}
}
void shell_ssort(char a[], int (*cmp)()) {
	char m[strlen(a)][strlen(a)];
	int k[strlen(a)], n = Q2SSCANF(a, m), k_total = init_shell_k_values(k, n), i, j, l, shell;
	for(i = k_total - 1; i >= 0; i--) { /* for each k value */
		for(shell = 0; shell < k[i]; shell++) { /* for each shell */
			for(l = k[i] + shell; l < n; l += k[i]) { /* insertion sort */
				char temp[strlen(m[l])];
				strcpy(temp, m[l]);
				for(j = l-k[i]; j >= 0 && (*cmp)(temp,m[j])>0; j-=k[i]) strcpy(m[j+k[i]], m[j]);
				strcpy(m[j+k[i]], temp);
			}
		}
	}
	Q2SPRINTF(a, m, n);
}
/******************************************************************************
* QUICK SORT -:- BEST: O(nlogn) & WORST: O(n^2) -:- UNSTABLE
	- sort the array relative to the pivot value (determines partition point)
	- split array & recursively sort each slice relative to new pivot values
******************************************************************************/
static void recursive_qsort(int a[], int lo, int hi, int (*cmp)()) {
	if(lo >= hi) return; /* array is sorted */
	int l = lo, r = hi, m = (hi+lo)/2, pivot;
	if((*cmp)(a[r], a[l]) > 0) issort_swap(a[l], a[r]);
	if((*cmp)(a[r], a[m]) > 0) { issort_swap(a[m], a[r]); }
	else if((*cmp)(a[m], a[l]) > 0) { issort_swap(a[m], a[l]); } /* better pivot */
	pivot = a[m]; /* sort the array relative to the pivot value */
	while(l <= r) { /* l will be the partition point */
		while((*cmp)(a[l], pivot) > 0) l++;
		while((*cmp)(pivot, a[r]) > 0) r--;
		if(l < r) { issort_swap(a[l], a[r]); l++; r--; } 
		else if(l == r) {l++; r--;}
	}
	recursive_qsort(a, lo, l-1, cmp), recursive_qsort(a, l, hi, cmp); /* sort L&R halves */
}
static void recursive_qssort(int len, char m[][len], int lo, int hi, int (*cmp)()) {
	if(lo >= hi) return; /* array is sorted */
	int l = lo, r = hi, mid = (lo+hi)/2;
	if((*cmp)(m[r], m[l]) > 0) issort_sswap(m[l], m[r]);
	if((*cmp)(m[r], m[mid]) > 0) { issort_sswap(m[mid], m[r]); } 
	else if((*cmp)(m[mid], m[l]) > 0) { issort_sswap(m[mid], m[l]); } /* better pivot */
	char pivot[strlen(m[mid])];
	strcpy(pivot, m[mid]); /* sort the array relative to the pivot value */
	while(l <= r) { /* l will be the partition point */
		while((*cmp)(m[l], pivot) > 0) l++;
		while((*cmp)(pivot, m[r]) > 0) r--;
		if(l < r) { issort_sswap(m[l], m[r]); l++; r--; } 
		else if(l == r) {l++; r--;}
	}
	recursive_qssort(len, m, lo, l-1, cmp), recursive_qssort(len, m, l, hi, cmp);
}
void quick_sort(int a[], int n, int (*cmp)()) { recursive_qsort(a, 0, n - 1, cmp); }
void quick_ssort(char a[], int (*cmp)()) { 
	char m[strlen(a)][strlen(a)]; int n = Q2SSCANF(a, m);
	recursive_qssort(strlen(a), m, 0, n - 1, cmp);
	Q2SPRINTF(a, m, n);
}
/******************************************************************************
* HEAP SORT -:- BEST & WORST: O(nlogn) -:- UNSTABLE
	- make a heap on 1 end of the array and mv the wall down from the other end
	- swap root and wall values, shift wall up, reheap, repeat
******************************************************************************/
#define PAR(I) (((I) - 1) / 2) /* get parent */
#define LCH(I) ((2 * (I)) + 1) /* get left child */
#define RCH(I) ((2 * (I)) + 2) /* get right child */
void heap_sort(int a[], int n, int (*cmp)()) {
	int i, j, child;
	for(i = 1, j = 1; i < n; j = i, i++) { /* heapify array - reheaping up */
		while((*cmp)(a[PAR(j)], a[j]) > 0 && j >= 0) {
			issort_swap(a[j], a[PAR(j)]); 
			j = PAR(j);
		}
	}
	for(i = n - 1, j = 0; i > 0; j = 0, i--) { /* heapsort - reheaping down */
		issort_swap(a[i], a[0]);
		while(LCH(j)<i && ((*cmp)(a[j],a[LCH(j)])>0 || (*cmp)(a[j],a[RCH(j)])>0)) {
			if((*cmp)(a[RCH(j)], a[LCH(j)]) > 0) { child = LCH(j); } 
			else { if(RCH(j) >= i) break; child = RCH(j); }
			issort_swap(a[j], a[child]); 
			j = child;
		}
	}
	if((*cmp)(a[0], a[1]) <= 0) issort_swap(a[1], a[0]);
}
void heap_ssort(char a[], int (*cmp)()) {
	char m[strlen(a)][strlen(a)];
	int i, j, child, n = Q2SSCANF(a, m);
	for(i = 1, j = 1; i < n; j = i, i++) { /* heapify array - reheaping up */
		while((*cmp)(m[PAR(j)], m[j]) > 0 && j >= 0) {
			issort_sswap(m[j], m[PAR(j)]); 
			j = PAR(j);
		}
	}
	for(i = n - 1, j = 0; i > 0; j = 0, i--) { /* heapsort - reheaping down */
		issort_sswap(m[i], m[0]);
		while(LCH(j)<i && ((*cmp)(m[j],m[LCH(j)]) > 0 || (*cmp)(m[j],m[RCH(j)]) > 0)) {
			if((*cmp)(m[RCH(j)], m[LCH(j)]) > 0) { child = LCH(j); } 
			else { if(RCH(j) >= i) break; child = RCH(j); }
			issort_sswap(m[j], m[child]); 
			j = child;
		}
	}
	if((*cmp)(m[0], m[1]) <= 0) issort_sswap(m[1], m[0]);
	Q2SPRINTF(a, m, n);
}
/******************************************************************************
* MERGE SORT -:- BEST & WORST: O(nlogn) -:- STABLE
	- recursively split array in half while "recursing down"
	- sort & merge the two halves while "recursing back up"
******************************************************************************/
void merge_sort(int a[], int n, int (*cmp)()) {
	if(n < 2) return; /* single elt subarray */
	int mi = n/2, nL = mi, nR = n-mi, L[nL], R[nR], i, j = 0, k = 0;
	for(i = 0; i < mi; i++) L[i] = a[i]; /* cpy left 1/2 of a[] */
	for(i = mi; i < n; i++) R[i - mi] = a[i]; /* cpy right 1/2 of a[] */
	merge_sort(L, nL, cmp), merge_sort(R, nR, cmp);
	i = 0;
	while(i < nL || j < nR) { /* while non-empty left/right subarrays */
		if(i < nL && ((*cmp)(L[i],R[j]) > 0 || j >= nR)) { /* put L value or empty R array */
			a[k++] = L[i++];
		} else { /* put R value or empty L array */
			a[k++] = R[j++];
		}
	}
}
static void recursive_mergessort(int len, char m[][len], int n, int (*cmp)()) {
	if(n < 2) return; /* single elt subarray */
	int mi = n/2, nL = mi, nR = n-mi, i, j = 0, k = 0;
	char L[nL][len], R[nR][len];
	for(i = 0; i < mi; i++) strcpy(L[i], m[i]); /* cpy left 1/2 of m[] */
	for(i = mi; i < n; i++) strcpy(R[i - mi], m[i]); /* cpy right 1/2 of m[] */
	recursive_mergessort(len, L, nL, cmp), recursive_mergessort(len, R, nR, cmp);
	i = 0;
	while(i < nL || j < nR) { /* while non-empty left/right subarrays */
		if(i < nL && ((*cmp)(L[i],R[j]) > 0 || j >= nR)) { /* put L value or empty R array */
			strcpy(m[k++], L[i++]);
		} else { /* put R value or empty L array */
			strcpy(m[k++], R[j++]);
		}
	}
}
void merge_ssort(char a[], int (*cmp)()) {
	char m[strlen(a)][strlen(a)]; int n = Q2SSCANF(a, m);
	recursive_mergessort(strlen(a), m, n, cmp);
	Q2SPRINTF(a, m, n);
}
/******************************************************************************
* HASH SORT (INTS) -:- BEST: O(n) & WORST: O(max(n,R)) -:- UNSTABLE
	- get max/minVals [(R)ange], mk hashmap[R+1], direct hash elts as idxs
	- taverse hashmap forwards/backwards for ascending/descending for sorted
******************************************************************************/
void hash_sort(int a[], int n, int (*cmp)()) {/* O(R) == O(max-min) */
	int i,j,k, is_sorted = 1, max=a[0],min=a[0], range, inc;
	for(i = 1; i < n; i++) { /* get max/min values -:- O(n) */
		if(a[i] > max) max = a[i];
		else if(a[i] < min) min = a[i];
		if((*cmp)(a[i-1], a[i]) <= 0) is_sorted = 0;
	}
	if(min == max || is_sorted == 1) return; /* array's sorted */
	range = (max - min + 1 > n) ? (max - min + 1) : (n); /* hashmap holds all elts */
	int hashmap[range];
	for(i = 0; i < range; i++) hashmap[i] = 0; /* init empty hashmap -:- O(R) */
	for(i = 0; i < n; i++) hashmap[a[i]-min] += 1; /* direct hash elts -:- O(n) */
	((*cmp)(1,3)>0&&(*cmp)(2,4)>0&&(*cmp)(1,6)>0&&(*cmp)(2,5)>0)?(inc=1):(inc=-1); /* ascend/descend */
	(inc == -1) ? (i = range-1) : (i = 0);
	for(j = 0; j < n; i += inc) /* get sorted hashmap values -:- WORST: O(max(n,R)) */
		for(k = 0; k < hashmap[i]; k++, j++) a[j] = i + min;
}
/******************************************************************************
* BINARY SEARCHES -:- BEST: O(logn) & WORST: O(logn)
******************************************************************************/
int bin_search(int sought, int a[], int arr_size, bool *found, int (*cmp)()) {
	int l = 0, h = arr_size - 1, c;
	while(l <= h) {
		c = (l + h) / 2;
		if(a[c] == sought) { *found = true; return c; }
		((*cmp)(a[c], sought) <= 0) ? (h = c - 1) : (l = c + 1);
	}
	*found = false; 
	return l;
}
int bin_ssearch(char *sought, char a[], bool *found, int (*cmp)()) {
	char m[strlen(a)][strlen(a)];
	int arr_size = Q2SSCANF(a, m), l = 0, h = arr_size - 1, c;
	while(l <= h) {
		c = (l + h) / 2;
		if(strcmp(m[c], sought) == 0) { *found = true; return c; }
		((*cmp)(m[c], sought) <= 0) ? (h = c - 1) : (l = c + 1);
	}
	*found = false; 
	return l; /* word (not letter) index */
}
