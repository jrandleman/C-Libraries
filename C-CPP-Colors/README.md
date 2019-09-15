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
  rprintf("%sHello Again!", bold blue); 
  
  return 0;
}
```
### _Via C++:_
```c++
#include <iostream>
#include "color.h"

int main() {
  // output bold/underlined blue text
  std::cout << bold line blue << "Hello There!" << reset << std::endl;
  return 0;
}
```
-----------
## `color.h` Features (_All Macros_*):
### O/P:
**1)** `rprintf(...)` _=_ `printf(...); printf(reset);`</br>
**2)** `rsprintf(str, ...)` _=_ `sprintf(str, ...); sprintf(&str[strlen(str)], reset);`</br>
**3)** `rfprintf(filename, ...)` _=_ `fprintf(filename, ...); fprintf(filename, reset);`

### Cursor Movement (_Creates a String Literal_):
**1)** `keyup(MOVE_AMOUNT)`_: Moves cursor_ `MOVE_AMOUNT` _lines up_</br>
**2)** `keydown(MOVE_AMOUNT)`_: Moves cursor_ `MOVE_AMOUNT` _lines down_</br>
**3)** `keyright(MOVE_AMOUNT)`_: Moves cursor_ `MOVE_AMOUNT` _spaces right_</br>
**4)** `keyleft(MOVE_AMOUNT)`_: Moves cursor_ `MOVE_AMOUNT` _spaces left_</br>
* _**Note:** passed to any means of output (ie_ `printf()` _,_ `std::cout` _, etc.) as if a color or decoration!_

### Resetting Syntax & Clearing Terminal's Screen:
**1)** `reset`_: String literal resetting Terminal's syntax styles_</br>
**2)** `clear`_: String literal clearing Terminal's screen (exactly like_ `clear` _in the cmd line)_</br>
* _**Note:** colors/decoration remain active in Terminal until passed_ `reset` _!_

### Text Decoration (_Creates a String Literal_):
**1)** `bold`_: Bold text_</br>
**2)** `line`_: Underlined text_</br>
**3)** `rev`_: Reverse the current background & text colors_

### Text Colors (_8 Basic Colors (headers) & 8 Gradients Each (columns)!_):
* _**Note:** gradients go from darkest (1) to brightest (8)!_</br>

| black  | red  | green  | yellow  | blue  |  magenta | cyan  | white  | 
|:------:|:----:|:------:|:-------:|:-----:|:--------:|:-----:|:------:|
| black1 | red1 | green1 | yellow1 | blue1 | magenta1 | cyan1 | white1 |
| black2 | red2 | green2 | yellow2 | blue2 | magenta2 | cyan2 | white2 |
| black3 | red3 | green3 | yellow3 | blue3 | magenta3 | cyan3 | white3 |
| black4 | red4 | green4 | yellow4 | blue4 | magenta4 | cyan4 | white4 |
| black5 | red5 | green5 | yellow5 | blue5 | magenta5 | cyan5 | white5 |
| black6 | red6 | green6 | yellow6 | blue6 | magenta6 | cyan6 | white6 |
| black7 | red7 | green7 | yellow7 | blue7 | magenta7 | cyan7 | white7 |
| black8 | red8 | green8 | yellow8 | blue8 | magenta8 | cyan8 | white8 |

### Background Colors (_8 Basic Colors (headers) & 8 Gradients Each (columns)!_):
* _**Note:** gradients go from darkest (1) to brightest (8)!_</br>
* _**Note:** exactly like text colors but prefixed w/_ `'b'` _!_</br>

| bblack  | bred  | bgreen  | byellow  | bblue  |  bmagenta | bcyan  | bwhite  | 
|:-------:|:-----:|:-------:|:--------:|:------:|:---------:|:------:|:-------:|
| bblack1 | bred1 | bgreen1 | byellow1 | bblue1 | bmagenta1 | bcyan1 | bwhite1 |
| bblack2 | bred2 | bgreen2 | byellow2 | bblue2 | bmagenta2 | bcyan2 | bwhite2 |
| bblack3 | bred3 | bgreen3 | byellow3 | bblue3 | bmagenta3 | bcyan3 | bwhite3 |
| bblack4 | bred4 | bgreen4 | byellow4 | bblue4 | bmagenta4 | bcyan4 | bwhite4 |
| bblack5 | bred5 | bgreen5 | byellow5 | bblue5 | bmagenta5 | bcyan5 | bwhite5 |
| bblack6 | bred6 | bgreen6 | byellow6 | bblue6 | bmagenta6 | bcyan6 | bwhite6 |
| bblack7 | bred7 | bgreen7 | byellow7 | bblue7 | bmagenta7 | bcyan7 | bwhite7 |
| bblack8 | bred8 | bgreen8 | byellow8 | bblue8 | bmagenta8 | bcyan8 | bwhite8 |


### \*Outputting All of `color.h`'s Text & Background Colors (function):
`showColors()`_: printf's all of_ `color.h`_'s basic & gradient text & background colors!_
