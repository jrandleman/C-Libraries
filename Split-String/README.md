# Str/ing!
## _Simulate .split() in JS via Matrices in C!_

### Include Library:
```c
#include "split.h"
```
### Outline:
```c
/*************************************************************************************
******************************* -:- A USER'S HOW TO -:- ******************************
**************************************************************************************
*                                                                                    *
*  Using split.h:                                                                    *
*  | L_ char** splitMatrix = split("your string", "split instance");                 *
*  | | L_ Matrix rows are "your string"'s segments split at every "split instance".  *
*  | | L_ Matrix ends when 1st char in row == '\0' (ie splitMatrix[i][0] == '\0').   *
*  | | L_ Both literals & variables work for "your string" & "split instance".       *
*  | L_ splitHelp():  Printf this message.                                           *
*  |                                                                                 *
*  With Respect to Memory Management:                                                *
*    L_ split() does not modify the original string passed to it.                    *
*    L_ Matrices returned by split() have automated garbage collection.              *
*                                                                                    *
*************************************************************************************/
```
--------------------------------
## _Automated Garbage Collection For split()'s Returned Matrices!_
### .split() from JavaScript:
```javascript
var splitStrArray = "your string".split("split instance");
```
### Becomes split() in C!
```c
char** splitMatrix = split("your string", "split instance");
```
### Additional Notes:
 * `split()` does ___not___ modify the original `"your string"` or `"split instance"` arguments
 * Matrix ends when 1st char in row == '\0' (ie when `splitMatrix[i][0] == '\0'`)
