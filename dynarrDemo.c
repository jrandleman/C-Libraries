/* AUTHOR: JORDAN RANDLEMAN -:- DEMO PROGRAM FOR DYNAMIC ARRAY C LIBRARY */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dynarr.h" /* DYNAMIC ARRAY C LIBRARY */

int main() {
	/* USER-DEFINED DYNAMIC ARRAY */
	DYN_ARR int_arr1[1], int_arr2[1], char_arr1[1], char_arr2[1];

	/* INITIALIZE DEFINED DYNAMIC ARRAYS */
	DA_INIT(int_arr1, 'i'); /* int array */
	DA_INIT(int_arr2, 'i'); /* int array */
	DA_INIT(char_arr1, 'c'); /* char array */
	DA_INIT(char_arr2, 'c'); /* char array */

	/**************************************************************************
	* INT DYNAMIC ARRAY
	**************************************************************************/
	_a(int_arr1,0,n0(6)); /* 'a'dd 6 to index 0 in array int_arr1 */
	_a(int_arr1,1,n0(5)); /* 'a'dd 5 to index 1 */
	_d(int_arr1,0); /* 'd'elete index 0 */
	printf("\nint_arr1 index 0: %d\n", _ei(int_arr1,0)); /* get index 0 'e'lement */
	_a(int_arr1,3,n0(9)); /* 'a'dd 9 to index 3 */
	printf("int_arr1 index 3: %d\n", _ei(int_arr1,3)); /* get index 3 'e'lement */
	_p(int_arr1,3,n0(4)); /* 'p'ut value 4 in index 3 */
	printf("int_arr1 index 3: %d\n", _ei(int_arr1,3)); /* get index 3 'e'lement */
	_d(int_arr1,3); /* 'd'elete index 3 */
	printf("int_arr1 length: %d\n", _l(int_arr1)); /* array 'l'ength */

	_p(int_arr1,0,n0(6)); /* 'a'dd 6 to index 0 */
	printf("int_arr1 index 0: %d\n", _ei(int_arr1,0)); /* get 'e'lement at index 0 */
	printf("int_arr1 index w/ value 6: %d\n", _i(int_arr1,n0(6))); /* return 'i'ndex w/ 6, or -1 DNE */

	_a(int_arr2,0,n0(8)); /* 'a'dd 8 to index 0 in array int_arr2 */
	_a(int_arr2,5,n0(7)); /* 'a'dd 7 to index 5 */
	_p(int_arr2,3,n0(4)); /* 'p'ut 4 to index 3 */
	printf("\nSwap int_arr2 values: index 0: %d - index 3: %d\n", _ei(int_arr2,0), _ei(int_arr2,3));
	_s(int_arr2,0,3); /* 's'wap index 0 cell with index 3 cell */
	printf("Swap int_arr2 values: index 0: %d - index 3: %d\n\n", _ei(int_arr2,0), _ei(int_arr2,3));

	/**************************************************************************
	* CHAR DYNAMIC ARRAY
	**************************************************************************/
	_a(char_arr1,0,"hello"); /* 'a'dd 'dude' to index 0 in char_arr1 */
	_a(char_arr1,2,"my"); /* 'a'dd 'my' to index 2 */
	printf("Index 0: %s - index 2: %s\n", _ec(char_arr1,0), _ec(char_arr1,2));
	printf("char_arr1 length: %d\n", _l(char_arr1));
	_d(char_arr1,2); /* 'd'elete index 2 */
	_a(char_arr1,2,"guy"); /* 'a'dd 'guy' to index 2 */
	printf("Index 2: %s\n",_ec(char_arr1,2)); /* get 'e'lement at index 2 */

	printf("Indices of 'guy' - 'hello': %d - %d\n", _i(char_arr1,"guy"), _i(char_arr1,"hello"));

	_a(char_arr2,0,"hello"); /* 'a'dd '' to index 0 */
	_a(char_arr2,3,"bob"); /* 'a'dd '' to index 3 */
	printf("\nSwap char_arr2 values - index 0, index 3: %s, %s!\n", _ec(char_arr2,0), _ec(char_arr2,3));
	_s(char_arr2,0,3); /* 's'wap index 0 cell with index 3 cell */
	printf("Swap char_arr2 values - index 0, index 3: %s, %s!\n\n", _ec(char_arr2,0), _ec(char_arr2,3));

	/* DEINIT DEFINED DYNAMIC ARRAYS */
	DA_DNIT(int_arr1);
	DA_DNIT(int_arr2);
	DA_DNIT(char_arr1);
	DA_DNIT(char_arr2);
	return 0;
}
