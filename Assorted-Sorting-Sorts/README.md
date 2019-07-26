# Assorted-Sorting-Sorts
_Selection, Insertion, Bubble, Heap, Shell, Quick, Merge, &amp; Hash Sorting!_</br>
-------------------------------------------------------------------------
***SORT FUNCTION NAMES:***</br>
	***(1)*** SELECT ***(2)*** INSERT ***(3)*** BUBBLE ***(4)*** HEAP ***(5)*** SHELL ***(6)*** QUICK ***(7)*** MERGE ***(8)*** HASH

</br>***SORT NAME EXTENSIONS:***</br>
=> "_sort" (integers) && "_ssort" (string's words)

</br>***SORT ARGUMENTS:***</br>
=> (`int`/`char array[], int size, int (*your_Compare_Function)()`)</br>
=> SIZE: only for integers</br>
=> COMPARE FUNCTION: if desired, pre-made functions available:
* `loW8`/`hiW8` (ascending/descending) functions for biased int sorting:
  * bias: towards multiples of the global `__W8__` value (assign pre-sort)
* `cmpstr` function for ascending string sorting (opposite `strcmp`)

</br>***SORT EXAMPLES:***
```c
// To prioritize (bias) multiples of 2, for example:
// __W8__ = 2;

int x[] = {23, 4, 8, 13, 3, 45, 89, 7};
heap_sort(x, 8, &loW8); // __W8__ defaults to 1, sorting in ascending order

char y[] = "cherry lime apple lemon orange banana pear";
heap_ssort(y, &strcmp); // sorts words in y[] in descending order
```

</br>***ALSO OFFERS BINARY SEARCH:***
```c
int idx = bin_search(int findMe, int arr[], int len, bool *found, int (*yourCmpFcn)()); // integers
int idx = bin_ssearch(char *findMe, char arr[], bool *found, int (*yourCmpFcn)()); // words in a string
```
