/* AUTHOR: JORDAN RANDLEMAN -:- DEMO PROGRAM FOR DYNAMIC ARRAY C LIBRARY */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "dynarr.h" /* DYNAMIC ARRAY C LIBRARY */

int main() {
	/* USER-DEFINED DYNAMIC ARRAY */
	DYN_ARR int_arr1[2], int_arr2[2], char_arr1[2], char_arr2[2];

	/* INITIALIZE DEFINED DYNAMIC ARRAYS */
	I_DYN_ARR_INIT(int_arr1); /* int array */
	I_DYN_ARR_INIT(int_arr2); /* int array */
	C_DYN_ARR_INIT(char_arr1); /* char array */
	C_DYN_ARR_INIT(char_arr2); /* char array */

	/**************************************************************************
	* INT DYNAMIC ARRAY
	**************************************************************************/
	_ai(int_arr1,0,6); /* 'a'dd 6 to index 0 in array int_arr1 */
	_ai(int_arr1,1,5); /* 'a'dd 5 to index 1 */
	_di(int_arr1,0); /* 'd'elete index 0 */
	printf("\nint_arr1 index 0: %d\n", _ei(int_arr1,0)); /* get index 0 'e'lement */
	_ai(int_arr1,3,9); /* 'a'dd 9 to index 3 */
	printf("int_arr1 index 3: %d\n", _ei(int_arr1,3)); /* get index 3 'e'lement */
	_pi(int_arr1,3,4); /* 'p'ut value 4 in index 3 */
	printf("int_arr1 index 3: %d\n", _ei(int_arr1,3)); /* get index 3 'e'lement */
	_di(int_arr1,3); /* 'd'elete index 3 */
	printf("int_arr1 length: %d\n", _li(int_arr1)); /* array 'l'ength */

	_pi(int_arr1,0,6); /* 'a'dd 6 to index 0 */
	printf("int_arr1 index 0: %d\n", _ei(int_arr1,0)); /* get 'e'lement at index 0 */
	printf("int_arr1 index w/ value 6: %d\n", _ii(int_arr1,6)); /* return 'i'ndex w/ 6, or -1 DNE */

	_ai(int_arr2,0,8); /* 'a'dd 8 to index 0 in array int_arr2 */
	_ai(int_arr2,5,7); /* 'a'dd 7 to index 5 */
	_pi(int_arr2,3,4); /* 'p'ut 4 to index 3 */
	printf("\nSwap int_arr2 values: index 0: %d - index 3: %d\n", _ei(int_arr2,0), _ei(int_arr2,3));
	_si(int_arr2,0,3); /* 's'wap index 0 cell with index 3 cell */
	printf("Swap int_arr2 values: index 0: %d - index 3: %d\n\n", _ei(int_arr2,0), _ei(int_arr2,3));

	/**************************************************************************
	* CHAR DYNAMIC ARRAY
	**************************************************************************/
	_ac(char_arr1,0,"hello"); /* 'a'dd 'dude' to index 0 in char_arr1 */
	_ac(char_arr1,2,"my"); /* 'a'dd 'my' to index 2 */
	printf("index 0: %s - index 2: %s\n", _ec(char_arr1,0), _ec(char_arr1,2));
	printf("char_arr1 length: %d\n", _lc(char_arr1));
	_dc(char_arr1,2); /* 'd'elete index 2 */
	_ac(char_arr1,2,"guy"); /* 'a'dd 'guy' to index 2 */
	printf("index 2: %s\n",_ec(char_arr1,2)); /* get 'e'lement at index 2 */

	printf("indices of 'guy' - 'hello': %d - %d\n", _ic(char_arr1,"guy"), _ic(char_arr1,"hello"));

	_ac(char_arr2,0,"hello"); /* 'a'dd '' to index 0 */
	_ac(char_arr2,3,"bob"); /* 'a'dd '' to index 3 */
	printf("\nSwap char_arr2 values - index 0, index 3: %s, %s!\n", _ec(char_arr2,0), _ec(char_arr2,3));
	_sc(char_arr2,0,3); /* 's'wap index 0 cell with index 3 cell */
	printf("Swap char_arr2 values - index 0, index 3: %s, %s!\n\n", _ec(char_arr2,0), _ec(char_arr2,3));

	/* WIPE DEFINED DYNAMIC ARRAYS */
	I_DYN_ARR_WIPE(int_arr1);
	I_DYN_ARR_WIPE(int_arr2);
	C_DYN_ARR_WIPE(char_arr1);
	C_DYN_ARR_WIPE(char_arr2);
	return 0;
}
