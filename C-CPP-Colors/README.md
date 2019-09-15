# Color.h
## _Color Text & Background, Decorate Text, & Manipulate the Cursor in Terminal!_
### _Friendlier C & C++ Interface for ANSI Escape Codes!_
-----------
## Using `color.h`:
* _**Note:** syntax styles are all string literal macros, thus adjacent instances concatenate into a single string!_
### _Via C:_
```c
#include <stdio.h>
#include <string.h>
#include "color.h"

int main() {
  // print "Hello There" in bold/blue text, then reset the font styles
  printf("%sHello There!%s", bold blue, reset); 
  
  // "rprintf" = "printf" but 'r'esets fonts automatically at the end!
  rprintf("%sHello Again!%s", bold blue, reset); 
  
  return 0;
}
```
### _Via C++:_
```c++
#include <iostream>
#include "color.h"

int main() {
  std::cout << bold blue << "Hello There!" << reset << std::endl;
  return 0;
}
```
