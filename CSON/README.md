# CSON!
## (C)(S)tring(O)bject(N)otation Library _=> Simulates JSON for Strings!_

### Include Library:
```c
#include "cson.h"
```
### Outline:
```c
/*************************************************************************************
******************************* -:- A USER'S HOW TO -:- ******************************
**************************************************************************************
*                                                                                    *
*  Using cson.h, C String Object Notation:                                           *
*  | L_ cson("yourKey"): Global 'object' to add, get, & rmv values.                  *
*  | | L_ Add: cson("author") = "Jordan";      // Add "Jordan" val to "author" key.  *
*  | | L_ Get: char *myValue = cson("author"); // Returns "author" val ("Jordan").   *
*  | | L_ Rmv: cson("author") = NULL;          // Rmv cson "author" key-value pair.  *
*  | L_ csonHas("yourKey"): Returns 1/0 if "yourKey" does/doesn't exist in cson.     *
*  | L_ csonSize():  Returns cson's current number of key-value pairs.               *
*  | L_ csonKeys() & csonVals(): Returns a matrix of cson's current keys/values.     *
*  | L_ csonPrint(): Printf all of cson's current key-value pairs.                   *
*  | L_ csonHelp():  Printf this message.                                            *
*  |                                                                                 *
*  A Note On Garbage Collection:                                                     *
*    L_ cson() & any arrays from csonKeys/Vals have automated garbage collection.    *
*                                                                                    *
*************************************************************************************/
```
--------------------------------
## Automated Garbage Collection!
### Adding a Key-Value Pair:
```c
cson("author") = "Jordan"; 
```
### Getting a Key's Value:
```c
char* elt = cson("author"); // "Jordan"
```
### Removing a Key-Value Pair:
```c
cson("author") = NULL;
```
### Returning Matrix of cson's Keys or Values:
```c
char** keysCopyMatrix = csonKeys();
char** valsCopyMatrix = csonVals();
```
### Returning cson's Current Number of Key-Value Pairs:
```c
int size = csonSize();
```
### Check if cson Has a Key-Value Pair:
```c
cson("author") = "Jordan"; 
if(csonHas("author")) printf("author exists!"); // true
if(csonHas("fakeKey")) printf("fakeKey exists!"); // false
```
