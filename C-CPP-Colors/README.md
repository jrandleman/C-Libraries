# Color.h
## _1) Stylize Terminal Output via Colors & Text Decoration!_
## _2) Generate a String's ASCII/Whitespace Art Equivalent!_
## _3) Generate a String's ASCII/Whitespace Art Raw String for External Use!_
### _Friendlier C & C++ Interface for ANSI Escape Codes!_
-----------
## Using `color.h`:
* _**Note:** font styles are all string literal macros, thus adjacent instances concatenate into a single string!_</br>
### Naming Conventions:
  1) _**Printing Functions & Color Names** (`fprinta`, `magenta`, etc):_ **alllowercase**</br>
  2) _**Multi-Word Functions** (`keyUp`, `showAsciiArt`, etc):_ **camelCase**</br>
  3) _**Single Non-Color Word** (`Reset`, `Bold`, `Line`, etc):_ **Capitalized**
### _Via C:_
```c
#include <stdio.h>
#include <string.h>
#include "color.h"

int main() {
  // print "Hello There" in bold/blue text, then reset the font styles
  printf("%sHello There!%s", Bold blue, Reset); 
  
  // "rprintf" = "printf" but 'r'esets fonts automatically at the end!
  rprintf("%sHello Again!", Bold blue); 
  
  // "printf" but outputting the the string using ASCII art for its characters (in red font)
  // NOTE: ASCII/WHITESPACE ART PRINTING MACROS IMPLICITLY INVOKE "reset" AT '\n's AND AT THEIR END
  printa("%sGood%s!", red6, "bye");
  
  // "printf" but outputting the the string using Whitespace art for its characters (in cyan font)
  printw("%s My%s!", red6, " guy!");
  
  return 0;
}
```
### _Via C++:_
```c++
#include <iostream>
#include "color.h"

int main() {
  // output bold/underlined blue text
  // note that the macros automatically concat w/ the string literal!
  std::cout << Bold Line blue "Hello" Reset " There!" << std::endl;
  
  // compiling as C++ activates the "color" namespace & its "rendl" 
  // alternative to "std::endl" (acts as: reset + "\n")
  std::cout << Bold Line blue "Hello" << color::rendl << " Again!\n";
  
  // "printf" but outputting the the string using ASCII art for its characters (in red font)
  // NOTE: ASCII/WHITESPACE ART PRINTING MACROS IMPLICITLY INVOKE "reset" AT '\n's AND AT THEIR END
  printa("%sGood%s!", red6, "bye");
  
  // "printf" but outputting the the string using Whitespace art for its characters (in cyan font)
  printw("%s My%s!", red6, " guy!");
  
  return 0;
}
```
-----------
## `color.h` Coloring & Decoration (_All Macros_*):
### O/P:
**1)** `rprintf(...)` _=_ `printf(...); printf(reset);`</br>
**2)** `rsprintf(str, ...)` _=_ `sprintf(str, ...); sprintf(&str[strlen(str)], reset);`</br>
**3)** `rfprintf(filename, ...)` _=_ `fprintf(filename, ...); fprintf(filename, reset);`
* _**Note:** when compiled as C++,_ `color.h` _activates its_ `color` _namespace's_ `rendl` _alternative to_ `std::endl` _!_

### Cursor Movement (_Creates a String Literal_):
**1)** `keyUp(MOVE_AMOUNT)`_: Moves cursor_ `MOVE_AMOUNT` _lines up_</br>
**2)** `keyDown(MOVE_AMOUNT)`_: Moves cursor_ `MOVE_AMOUNT` _lines down_</br>
**3)** `keyRight(MOVE_AMOUNT)`_: Moves cursor_ `MOVE_AMOUNT` _spaces right_</br>
**4)** `keyLeft(MOVE_AMOUNT)`_: Moves cursor_ `MOVE_AMOUNT` _spaces left_</br>
* _**Note:** passed to any means of output (ie_ `printf()` _,_ `std::cout` _, etc.) as if a color or decoration!_

### Resetting Styles & Clearing Terminal's Screen:
**1)** `Reset`_: String literal resetting Terminal's font styles_</br>
**2)** `Clear`_: String literal clearing Terminal's screen (exactly like_ `clear` _in the cmd line)_</br>
* _**Note:** colors/decoration remain active in Terminal until passed_ `Reset` _!_

### Text Decoration (_Creates a String Literal_):
**1)** `Bold`_: Bold text_</br>
**2)** `Line`_: Underlined text_</br>
**3)** `Rev`_: Reverse the current background & text colors_

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
`showColors()`_: printf's all of_ `color.h`_'s basic/gradient text & background colors!_</br>
```c
showColors();
```
![image of "showColors()" function output](https://github.com/jrandleman/C-Libraries/blob/master/C-CPP-Colors/showColors_fcn_C_CPP_Colors_Demo.png)

-----------
## `color.h` ASCII Art Output Replacements:
 * ***NOTE: ASCII/Whitespace art printing macros implicitly invoke `reset` at any `\n` & the end of the string!***</br>
 * ***NOTE: NEVER use `Rev` Text Deco. w/ Whitespace art (as whitespace IS the background)!***
### printf, sprintf, fprintf:
* _Use_ `printa`_,_ `sprinta`_, &_ `fprinta` _instead to output the ASCII-Art Equivalent String_</br>
* _Use_ `printa_raw`_,_ `sprinta_raw`_, &_ `fprinta_raw` _to output the **RAW** ASCII-Art Equivalent String_</br>
  * _"Raw Strings" are Art strings too, BUT w/ their control chars escaped!_
  * _Thus "Raw Strings" can be cpy/pasted into any other program to use styled messages w/o `color.h`!_
```c
printa("enjoy color.h!");
/*
 * OUTPUT:
 *
 * /|==\ /\\ || (====) //==\\ (\  /)       //===) //==\\ /|    //==\\ ||^\\     || ||   // 
 * ||=   ||\\|| _ ||   ||  ||  \\//        ||     ||  || ||    ||  || ||_//     |===|  // 
 * \|==/ || \// \\//   \\==//   ||         \\===) \\==// \===/ \\==// || \\ <*> || || <*>  
 *
 */
```


### strlen
* _Use_ `asciiArtStrlen` _instead to see the length that the string's ASCII art equivalent_

### Outputting `color.h`'s ASCII Art Alphabet:
`showAsciiArt()`_: printf's all of_ `color.h`_'s supported ASCII art characters!_
```c
showAsciiArt();
/*
 * OUTPUT:
 *
 *     // (/(/ _||_||_ //=||==\ @ // ((^))   ))  // \\   \\|//     ||             
 *    //       _||_||_ \\=||=\\  //  //^\\//    ||   || <==*==> [==++==] _  +===+ 
 *   <*>        || ||  \==||=// // @ \\_//\\     \\ //   //|\\     ||    ))       
 *
 *         // //=\\ //|  (==\\  /==\\  //||   /|===) //==) (====) ((^)) //==|\     
 *        //  | + |  ||   __//    =|| ((=||)  \|==\  ||/=\    //  //^\\ \\==|| <*> 
 *   <*> //   \\=// ==== (====/ \==//    ||  \====/  \\==/   //   \\_//     \| <*> 
 *
 *                     //^\\  //==\\  //^\\  ||^\\  //===) ||^\\  /|==\ /===\ //===\ 
 *   <*> // [=====] \\   _// ((  _|| |/===\| ||-//_ ||     ||  )) ||=   |==   || ==\ 
 *    )) \\ [=====] //   @    \\(_|| ||   || ||__// \\===) ||_//  \|==/ ||    \\==// 
 *
 *   || || ==== (====) ||// /|    /\\  //\ /\\ || //==\\ /|==\\ //==\\ ||^\\  //==) ==== 
 *   |===|  ||  _ ||   |((  ||    ||\\//|| ||\\|| ||  || ||==// || _|| ||_//  \==\   ||  
 *   || || ==== \\//   ||\\ \===/ || \/ || || \// \\==// ||     \\==\\ || \\ \==//   ||  
 *
 *   /| |\ /|  |\ /| /\ |\ \\ // (\  /) /===)  |=] \\   [=| //^\\       \\ (( || ))       
 *   || || \\  // \\//\\//  )X(   \\//    //   |    \\    |                << || >> //\// 
 *   \\=//  \\//   \/  \/  // \\   ||    (===/ |=]   \\ [=|       +===+    (( || ))       
 *
 */
```
-----------
## `color.h` Whitespace Art Output Replacements:

### printf, sprintf, fprintf:
* _Use_ `printw`_,_ `sprintw`_, &_ `fprintw` _instead to output the Whitespace-Art Equivalent String_
* _Use_ `printw_raw`_,_ `sprintw_raw`_, &_ `fprintw_raw` _to output the **RAW** Whitespace-Art Equivalent String_</br>
  * _"Raw Strings" are Art strings too, BUT w/ their control chars escaped!_
  * _Thus "Raw Strings" can be cpy/pasted into any other program to use styled messages w/o `color.h`!_
```c
printw("enjoy color.h!");
```
![image of "enjoy color.h!" in whitespace art](https://github.com/jrandleman/C-Libraries/blob/master/C-CPP-Colors/ENJOY_COLOR_H_whitespaceArt.png)

### strlen
* _Use_ `whitespaceArtStrlen` _instead to see the length that the string's Whitespace art equivalent_

### Outputting `color.h`'s Whitespace Art Alphabet:
`showWhitespaceArt()`_: printf's all of_ `color.h`_'s supported Whitespace art characters!_
```c
showWhitespaceArt();
```
![image of "showWhitespaceArt()" output](https://github.com/jrandleman/C-Libraries/blob/master/C-CPP-Colors/SHOW_WHITESPACE_ART_whitespaceArt.png)

-----------
## `color.h` ASCII & Whitespace Art Supported Characters:
### Lower-Case Letters Are Converted To Upper-Case!
```c
"hello!" // becomes: "HELLO!"
```
### Valid Characters:
```c
"!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`{|}~"
```
### Also Supports 'Space' & 3 Control Characters:
```c
"\b\t\n"
```
### As Well As All Colors/Text Decorations This Library Has To Offer!
```c
printa("%shello!\n", cyan6 Rev Bold);
printw("%slater!\n", green5);
```
