// AUTHOR: JORDAN RANDLEMAN - color.h - Easier Interface For ANSI Esc Codes
// -:- COLORS/TEXT-DECORATION IN TERMINAL FOR BOTH C & C++ -:-
// -:- OUTPUTTING ASCII ART ALPHABET FOR BOTH C & C++ -:-

// Sources For ANSI Esc Codes: 
// 1) https://www.lihaoyi.com/post/BuildyourownCommandLinewithANSIescapecodes.html\
// 2) http://www.climagic.org/mirrors/VT100_Escape_Codes.html


/*
 * NAMING CONVENTIONS IN COLOR.H:
 *   (1) PRINTING & COLORS (fprinta, magenta, etc): alllowercase
 *   (2) MULTIPLE WORDS (keyUp, showAsciiArt, etc): camelCase
 *   (3) SINGLE NON-COLOR WORD (Reset, Bold, Line): Capitalized
 *
 * => CAPITALIZATION REASONING: 
 *    colors are considered reserved in color.h (shocker), BUT words like 
 *    "clear" and "Reset" have a place in C++'s STL, hence they have been 
 *    given a capital letter to not expand "my_vector.clear()". 
 */


#ifndef COLOR_H_
#define COLOR_H_

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

/******************************************************************************
* PUBLIC INTERFACES: C++ std::endl ALTERNATIVE: "Reset" + "\n"
******************************************************************************/

#ifdef __cplusplus
// color::rendl = std::endl + resets ANSI Esc Keys/Colors
namespace color { const char* rendl = "\033[0m\n"; }
#endif

/******************************************************************************
* PUBLIC INTERFACES: OUTPUT + RESET STYLE
******************************************************************************/

// output macros automatically 'r'esetting STYLE after output
#define rprintf(...) ({printf(__VA_ARGS__);printf("\033[0m");fflush(stdout);})
#define rsprintf(RS_STR, ...)\
  ({sprintf(RS_STR, __VA_ARGS__);sprintf(&RS_STR[strlen(RS_STR)], "\033[0m");})
#define rfprintf(RF_FPTR, ...)({\
  fprintf(RF_FPTR,__VA_ARGS__);fprintf(RF_FPTR,"\033[0m");fflush(RF_FPTR);\
})

/******************************************************************************
* PUBLIC INTERFACES: KEYPAD ARROW MOVEMENTS
******************************************************************************/

// move the cursor up, down, left, & right "MOVE_AMOUNT" positions
#define keyUp(MOVE_AMOUNT)    "\033[" #MOVE_AMOUNT "A"
#define keyDown(MOVE_AMOUNT)  "\033[" #MOVE_AMOUNT "B"
#define keyRight(MOVE_AMOUNT) "\033[" #MOVE_AMOUNT "C"
#define keyLeft(MOVE_AMOUNT)  "\033[" #MOVE_AMOUNT "D"

/******************************************************************************
* PUBLIC INTERFACES: RESET STYLE / CLEAR SCREEN
******************************************************************************/

// reset style settings
#define Reset "\033[0m"

// clear current screen
#define Clear "\033[2J"

/******************************************************************************
* PUBLIC INTERFACES: TEXT DECORATION - BOLD, UNDERLINE, REVERSE BACKGROUND/TEXT COLORS
******************************************************************************/

// bold, underline, & reverse background/text colors
#define Bold  "\033[1m" 
#define Line  "\033[4m"
#define Rev   "\033[7m"
// decoration combinations named alphabetically
#define boldLine    Bold Line
#define boldRev     Bold Rev
#define lineRev     Line Rev
#define boldLineRev Bold Line Rev

/******************************************************************************
* PUBLIC INTERFACES: TEXT COLORS
******************************************************************************/

// basic 8 colors, standard amongst even basic terminals:
#define black    "\033[30m"
#define red      "\033[31m"
#define green    "\033[32m"
#define yellow   "\033[33m"
#define blue     "\033[34m"
#define magenta  "\033[35m"
#define cyan     "\033[36m"
#define white    "\033[37m"

// each of 8 basic colors extended along their own 8 gradients
// from 1 = dark, to 8 = bright
#define black1 "\033[38;5;0m"
#define black2 "\033[38;5;233m"
#define black3 "\033[38;5;234m"
#define black4 "\033[38;5;235m"
#define black5 "\033[38;5;237m"
#define black6 "\033[38;5;238m"
#define black7 "\033[38;5;239m"
#define black8 "\033[38;5;8m"

#define red1 "\033[38;5;52m"
#define red2 "\033[38;5;88m"
#define red3 "\033[38;5;1m"
#define red4 "\033[38;5;124m"
#define red5 "\033[38;5;160m"
#define red6 "\033[38;5;9m"
#define red7 "\033[38;5;196m"
#define red8 "\033[38;5;197m"

#define green1 "\033[38;5;22m"
#define green2 "\033[38;5;28m"
#define green3 "\033[38;5;70m"
#define green4 "\033[38;5;40m"
#define green5 "\033[38;5;82m"
#define green6 "\033[38;5;118m"
#define green7 "\033[38;5;119m"
#define green8 "\033[38;5;156m"

#define yellow1 "\033[38;5;208m"
#define yellow2 "\033[38;5;214m"
#define yellow3 "\033[38;5;220m"
#define yellow4 "\033[38;5;226m"
#define yellow5 "\033[38;5;227m"
#define yellow6 "\033[38;5;228m"
#define yellow7 "\033[38;5;229m"
#define yellow8 "\033[38;5;230m"

#define blue1 "\033[38;5;17m"
#define blue2 "\033[38;5;18m"
#define blue3 "\033[38;5;19m"
#define blue4 "\033[38;5;4m"
#define blue5 "\033[38;5;20m"
#define blue6 "\033[38;5;21m"
#define blue7 "\033[38;5;12m"
#define blue8 "\033[38;5;27m"

#define magenta1 "\033[38;5;54m"
#define magenta2 "\033[38;5;90m"
#define magenta3 "\033[38;5;127m"
#define magenta4 "\033[38;5;164m"
#define magenta5 "\033[38;5;13m"
#define magenta6 "\033[38;5;207m"
#define magenta7 "\033[38;5;213m"
#define magenta8 "\033[38;5;183m"

#define cyan1 "\033[38;5;30m"
#define cyan2 "\033[38;5;6m"
#define cyan3 "\033[38;5;37m"
#define cyan4 "\033[38;5;80m"
#define cyan5 "\033[38;5;14m"
#define cyan6 "\033[38;5;51m"
#define cyan7 "\033[38;5;123m"
#define cyan8 "\033[38;5;159m"

#define white1 "\033[38;5;242m"
#define white2 "\033[38;5;244m"
#define white3 "\033[38;5;248m"
#define white4 "\033[38;5;7m"
#define white5 "\033[38;5;252m"
#define white6 "\033[38;5;15m"
#define white7 "\033[38;5;255m"
#define white8 "\033[38;5;231m"

/******************************************************************************
* PUBLIC INTERFACES: BACKGROUND COLORS - PREFIXED BY "b"
******************************************************************************/

// basic 8 colors, standard amongst even basic terminals:
#define bblack    "\033[40m"
#define bred      "\033[41m"
#define bgreen    "\033[42m"
#define byellow   "\033[43m"
#define bblue     "\033[44m"
#define bmagenta  "\033[45m"
#define bcyan     "\033[46m"
#define bwhite    "\033[47m"

// each of 8 basic colors extended along their own 8 gradients
// from 1 = dark, to 8 = bright
#define bblack1 "\033[48;5;0m"
#define bblack2 "\033[48;5;233m"
#define bblack3 "\033[48;5;234m"
#define bblack4 "\033[48;5;235m"
#define bblack5 "\033[48;5;237m"
#define bblack6 "\033[48;5;238m"
#define bblack7 "\033[48;5;239m"
#define bblack8 "\033[48;5;8m"

#define bred1 "\033[48;5;52m"
#define bred2 "\033[48;5;88m"
#define bred3 "\033[48;5;1m"
#define bred4 "\033[48;5;124m"
#define bred5 "\033[48;5;160m"
#define bred6 "\033[48;5;9m"
#define bred7 "\033[48;5;196m"
#define bred8 "\033[48;5;197m"

#define bgreen1 "\033[48;5;22m"
#define bgreen2 "\033[48;5;28m"
#define bgreen3 "\033[48;5;70m"
#define bgreen4 "\033[48;5;40m"
#define bgreen5 "\033[48;5;82m"
#define bgreen6 "\033[48;5;118m"
#define bgreen7 "\033[48;5;119m"
#define bgreen8 "\033[48;5;156m"

#define byellow1 "\033[48;5;208m"
#define byellow2 "\033[48;5;214m"
#define byellow3 "\033[48;5;220m"
#define byellow4 "\033[48;5;226m"
#define byellow5 "\033[48;5;227m"
#define byellow6 "\033[48;5;228m"
#define byellow7 "\033[48;5;229m"
#define byellow8 "\033[48;5;230m"

#define bblue1 "\033[48;5;17m"
#define bblue2 "\033[48;5;18m"
#define bblue3 "\033[48;5;19m"
#define bblue4 "\033[48;5;4m"
#define bblue5 "\033[48;5;20m"
#define bblue6 "\033[48;5;21m"
#define bblue7 "\033[48;5;12m"
#define bblue8 "\033[48;5;27m"

#define bmagenta1 "\033[48;5;54m"
#define bmagenta2 "\033[48;5;90m"
#define bmagenta3 "\033[48;5;127m"
#define bmagenta4 "\033[48;5;164m"
#define bmagenta5 "\033[48;5;13m"
#define bmagenta6 "\033[48;5;207m"
#define bmagenta7 "\033[48;5;213m"
#define bmagenta8 "\033[48;5;183m"

#define bcyan1 "\033[48;5;30m"
#define bcyan2 "\033[48;5;6m"
#define bcyan3 "\033[48;5;37m"
#define bcyan4 "\033[48;5;80m"
#define bcyan5 "\033[48;5;14m"
#define bcyan6 "\033[48;5;51m"
#define bcyan7 "\033[48;5;123m"
#define bcyan8 "\033[48;5;159m"

#define bwhite1 "\033[48;5;242m"
#define bwhite2 "\033[48;5;244m"
#define bwhite3 "\033[48;5;248m"
#define bwhite4 "\033[48;5;7m"
#define bwhite5 "\033[48;5;252m"
#define bwhite6 "\033[48;5;15m"
#define bwhite7 "\033[48;5;255m"
#define bwhite8 "\033[48;5;231m"

/******************************************************************************
* PUBLIC INTERFACE: SHOW AVAILABLE COLORS FUNCTION
******************************************************************************/

void showColors() {
  const char *basic_text_colors[8] = {
    "    black", "      red", "    green", "   yellow", 
    "     blue", "  magenta", "     cyan", "    white"
  };
  const char *basic_background_colors[8] = {
    "   bblack", "     bred", "   bgreen", "  byellow", 
    "    bblue", " bmagenta", "    bcyan", "   bwhite"
  };

  const int blacks[8]   = {   0, 233, 234, 235, 237, 238, 239,   8 };
  const int reds[8]     = {  52,  88,   1, 124, 160,   9, 196, 197 };
  const int greens[8]   = {  22,  28,  70,  40,  82, 118, 119, 156 };
  const int yellows[8]  = { 208, 214, 220, 226, 227, 228, 229, 230 };
  const int blues[8]    = {  17,  18,  19,   4,  20,  21,  12,  27 };
  const int magentas[8] = {  54,  90, 127, 164,  13, 207, 213, 183 };
  const int cyans[8]    = {  30,   6,  37,  80,  14,  51, 123, 159 };
  const int whites[8]   = { 242, 244, 248,   7, 252,  15, 255, 231 };
  const int *colors[8]  = {
    blacks,reds,greens,yellows,blues,magentas,cyans,whites
  };

  // OUTPUT BASIC COLORS
  int i, j;
  rprintf("\n%s>> %sBasic 8 Colors:\n%s  bblack ", Bold, Line,
    Reset white8 bblack);
  for(i = 1; i < 8; ++i) // output basic background colors
    rprintf("%s\033[4%dm%s ", black, i, basic_background_colors[i]);
  rprintf("\n%s   black ", Reset black);
  for(i = 1; i < 8; ++i) // output basic text colors
    rprintf("\033[3%dm%s ", i, basic_text_colors[i]);
  

  // OUTPUT COLOR GRADIENTS
  rprintf("\n\n%s>> %sExtended Color Gradients:\n", Bold, Line);
  for(i = 0; i < 8; ++i) { // output background color gradients
    for(j = 0; j < 8; ++j)
      (i == 0)
        ? rprintf("%s\033[48;5;%dm%s%d ",
          white8, colors[i][j], basic_background_colors[i], j + 1)
        : rprintf("%s\033[48;5;%dm%s%d ",
          black, colors[i][j], basic_background_colors[i], j + 1);
    printf("\n");
  }
  for(i = 0; i < 8; ++i) { // output text color gradients
    for(j = 0; j < 8; ++j)
      rprintf("%s\033[38;5;%dm%s%d ", 
        black, colors[i][j], basic_text_colors[i], j + 1);
    printf("\n");
  }
  printf("\n");
}

/******************************************************************************
* PRIVATE INTERFACES: ASCII/WHITESPACE ART PRINTING HELPER FUNCTIONS
******************************************************************************/

// max strlen, ASCII/Whitespace art alphabet length, # rows per alpha art letter, 
// '\b' alpha art idx
static const int MAX_ALPHA_ART_BUFFER_LENGTH = 100001, // 100 Kilobytes + '\0'
                 MAX_ANSI_CMD_LENGTH         = 500,
                 ALPHA_ART_ALPHABET_LENGTH   = 74,
                 TOTAL_ASCII_ART_ROWS        = 3,       // top mid, bot
                 BACKSPACE_ART_IDX           = ALPHA_ART_ALPHABET_LENGTH - 2,
                 ANSI_ESC_ART_IDX            = ALPHA_ART_ALPHABET_LENGTH - 1;


// chars w/ ASCII art equivalents (lowercase letters too, but get uppercased)
static const char *VALID_ALPHA_ART_CHARS     = 
"\t\n !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`{|}~\b";


// ASCII art alphabet sorted by ascii code.
// => '\b' char repn is missing as the # of '\b's used is evaluated at run-time
//    as per width of the previously printed char. 
// => each row's last string repns non-lowercase chars also not found in 
//    "VALID_ALPHA_ART_CHARS"
static const char *ASCII_ART_ROW_TOP[ALPHA_ART_ALPHABET_LENGTH] = {"\t\t", "newline",  "      ", "  // ", "(/(/ ", "_||_||_ ", "//=||==\\ ",    "@ // ", "((^))   ",     ")) ", " // ",   "\\\\  ", " \\\\|//  ", "   ||    ", "   ", "      ", "    ", "  // ", "//=\\\\ ", "//|  ", "(==\\\\  ", "/==\\\\ ", " //||  ", " /|===) ",   "//==) ",   "(====) ", "((^)) ",   "//==|\\ ",  "    ", "    ", "   ",   "        ", "   ",   "//^\\\\ ", " //==\\\\ ", " //^\\\\  ", "||^\\\\  ", "//===) ",   "||^\\\\  ", "/|==\\ ", "/===\\ ", "//===\\ ",  "|| || ", "==== ", "(====) ",   "||// ",   "/|    ",  "/\\\\  //\\ ", "/\\\\ || ", "//==\\\\ ", "/|==\\\\ ", "//==\\\\ ",   "||^\\\\ ", " //==) ",   "==== ", "/| |\\ ",  "/|  |\\ ",  "/| /\\ |\\ ",   "\\\\ // ", "(\\  /) ",  "/===)  ", "|=] ", "\\\\   ", "[=| ", "//^\\\\ ", "      ", "\\\\ ", "(( ", "|| ", ")) ", "      ",  "###### "};
static const char *ASCII_ART_ROW_MID[ALPHA_ART_ALPHABET_LENGTH] = {"\t\t", "newline",  "      ", " //  ", "     ", "_||_||_ ", "\\\\=||=\\\\ ", " //  ", "//^\\\\// ",   "   ", "||  ",   " || ",   "<==*==> ",   "[==++==] ", "_  ", "+===+ ", "    ", " //  ", "| + | ",   " ||  ", " __//  ",   "  =|| ",   "((=||) ", " \\|==\\  ", "||/=\\ ",  "   //  ", "//^\\\\ ", "\\\\==|| ", "<*> ", "<*> ", "// ",   "[=====] ", "\\\\ ", "  _// ",   "((  _|| ",   "|/===\\| ",  "||-//_ ",   "||     ",   "||  )) ",   "||=   ",  "|==   ",  "|| ==\\ ",  "|===| ", " ||  ", "_ ||   ",   "|((  ",   "||    ",  "||\\\\//|| ",  "||\\\\|| ", "||  || ",   "||==// ",   "|| _|| ",     "||_// ",   " \\==\\  ", " ||  ", "|| || ",   "\\\\  // ", "\\\\//\\\\// ", " )X(  ",   " \\\\//  ", "  //   ", "|   ", " \\\\  ", "  | ", "      ",   "      ", "   ",   "<< ", "|| ", ">> ", "//\\// ", "###### "};
static const char *ASCII_ART_ROW_BOT[ALPHA_ART_ALPHABET_LENGTH] = {"\t\t", "newline",  "      ", "<*>  ", "     ", " || ||  ", "\\==||=// ",    "// @ ", "\\\\_//\\\\ ", "   ", " \\\\ ", "//  ",   " //|\\\\  ", "   ||    ", ")) ", "      ", "<*> ", "//   ", "\\\\=// ", "==== ", "(====/ ",   "\\==// ",  "   ||  ", "\\====/  ",  "\\\\==/ ", "  //   ", "\\\\_// ", "    \\| ",  "<*> ", " )) ", "\\\\ ", "[=====] ", "// ",   "  @   ",   " \\\\(_|| ", "||   || ",   "||__// ",   "\\\\===) ", "||_//  ",   "\\|==/ ", "||    ",  "\\\\==// ", "|| || ", "==== ", "\\\\//   ", "||\\\\ ", "\\===/ ", "|| \\/ || ",   "|| \\// ",  "\\\\==// ", "||     ",   "\\\\==\\\\ ", "|| \\\\ ", "\\==//  ",  " ||  ", "\\\\=// ", " \\\\//  ", " \\/  \\/  ",   "// \\\\ ", "  ||   ",   " (===/ ", "|=] ", "  \\\\ ", "[=| ", "      ",   "+===+ ", "   ",   "(( ", "|| ", ")) ", "      ",  "###### "};
static const char **ASCII_ART_MATRIX[TOTAL_ASCII_ART_ROWS] = {
  ASCII_ART_ROW_TOP, ASCII_ART_ROW_MID, ASCII_ART_ROW_BOT
};


// rows in WHITESPACE alphabet art matrix
static const int TOTAL_WHITESPACE_ART_ROWS = 5,
                 MAX_WHITESPACE_REVS_PER_LETTER = 4; // number of "%s" w/in each letter to splice in user-defined ANSI cmds
// WHITESPACE art alphabet sorted by ascii code
static const char *WHITESPACE_ART_ROW_CEIL[ALPHA_ART_ALPHABET_LENGTH]  = {"%s%s%s%s\t\t\t", "%s%s%s%snewline", "%s%s%s%s      ", "%s%s%s\033[7m     \033[0m%s ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s   \033[7m \033[0m%s   \033[7m \033[0m%s    ", "%s%s%s  \033[7m       \033[0m%s ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s%s \033[7m    \033[0m%s     ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s  \033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s   ", "%s\033[7m  \033[0m%s \033[7m \033[0m%s \033[7m  \033[0m%s ", "%s%s%s    \033[7m \033[0m%s     ", "%s%s%s%s   ", "%s%s%s%s      ", "%s%s%s%s    ", "%s%s%s    \033[7m  \033[0m%s ", "%s%s%s \033[7m     \033[0m%s  ", "%s%s%s \033[7m   \033[0m%s    ", "%s%s%s \033[7m    \033[0m%s    ", "%s%s%s\033[7m      \033[0m%s ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s%s\033[7m      \033[0m%s ", "%s%s%s \033[7m      \033[0m%s  ", "%s%s%s\033[7m        \033[0m%s ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s%s   ", "%s%s%s%s   ", "%s%s%s%s    ", "%s%s%s%s       ", "%s%s%s%s    ", "%s%s%s \033[7m     \033[0m%s  ", "%s%s%s \033[7m     \033[0m%s  ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s\033[7m    \033[0m%s  ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s\033[7m   \033[0m%s   ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s \033[7m     \033[0m%s ", "%s%s%s \033[7m    \033[0m%s   ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s%s\033[7m   \033[0m%s ", "%s%s%s\033[7m       \033[0m%s ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s  ", "%s%s%s\033[7m  \033[0m%s    ", "%s%s\033[7m   \033[0m%s   \033[7m   \033[0m%s ", "%s%s \033[7m  \033[0m%s   \033[7m   \033[0m%s ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s\033[7m    \033[0m%s ", "%s%s%s \033[7m   \033[0m%s   ", "%s%s%s\033[7m    \033[0m%s   ", "%s%s%s   \033[7m    \033[0m%s  ", "%s%s%s\033[7m     \033[0m%s ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s\033[7m    \033[0m%s \033[7m    \033[0m%s ", "%s%s\033[7m    \033[0m%s     \033[7m    \033[0m%s ", "%s%s\033[7m   \033[0m%s   \033[7m   \033[0m%s ", "%s%s\033[7m  \033[0m%s   \033[7m  \033[0m%s ", "%s%s%s\033[7m      \033[0m%s  ", "%s%s%s\033[7m    \033[0m%s ", "%s%s%s\033[7m  \033[0m%s     ", "%s%s%s\033[7m    \033[0m%s ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s%s       ", "%s%s%s\033[7m  \033[0m%s  ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s%s        ", "%s%s%s\033[7m      \033[0m%s "};
static const char *WHITESPACE_ART_ROW_TOP[ALPHA_ART_ALPHABET_LENGTH]   = {"%s%s%s%s\t\t\t", "%s%s%s%snewline", "%s%s%s%s      ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s\033[7m \033[0m%s  \033[7m \033[0m%s  ", "%s%s%s\033[7m           \033[0m%s ", "%s \033[7m  \033[0m%s \033[7m \033[0m%s   \033[7m \033[0m%s ", "%s%s%s   \033[7m  \033[0m%s  ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s    ", "%s%s%s \033[7m \033[0m%s ", "%s%s%s \033[7m  \033[0m%s  ", "%s%s%s \033[7m  \033[0m%s  ", "%s%s%s \033[7m     \033[0m%s  ", "%s%s%s    \033[7m \033[0m%s     ", "%s%s%s%s   ", "%s%s%s%s      ", "%s%s%s%s    ", "%s%s%s   \033[7m  \033[0m%s  ", "%s%s\033[7m  \033[0m%s   \033[7m  \033[0m%s ", "%s%s\033[7m  \033[0m%s \033[7m \033[0m%s    ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s   ", "%s%s\033[7m \033[0m%s  \033[7m  \033[0m%s  ", "%s%s\033[7m \033[0m%s  \033[7m \033[0m%s  ", "%s%s%s\033[7m \033[0m%s      ", "%s%s\033[7m  \033[0m%s    \033[7m  \033[0m%s ", "%s%s\033[7m  \033[0m%s   \033[7m  \033[0m%s  ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s \033[7m  \033[0m%s ", "%s%s%s\033[7m      \033[0m%s ", "%s%s%s\033[7m  \033[0m%s  ", "%s%s\033[7m  \033[0m%s   \033[7m  \033[0m%s ", "%s%s\033[7m  \033[0m%s   \033[7m  \033[0m%s ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s  ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s  ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s\033[7m \033[0m%s \033[7m  \033[0m%s  ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s \033[7m \033[0m%s   \033[7m \033[0m%s ", "%s%s%s\033[7m  \033[0m%s      ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s  ", "%s%s%s \033[7m \033[0m%s  ", "%s%s   \033[7m \033[0m%s  \033[7m \033[0m%s ", "%s%s \033[7m \033[0m%s \033[7m  \033[0m%s   ", "%s%s%s \033[7m \033[0m%s    ", "%s%s \033[7m   \033[0m%s \033[7m   \033[0m%s  ", "%s%s \033[7m   \033[0m%s  \033[7m \033[0m%s   ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s  ", "%s%s \033[7m \033[0m%s \033[7m  \033[0m%s  ", "%s%s  \033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s\033[7m \033[0m%s \033[7m \033[0m%s \033[7m \033[0m%s ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s  ", "%s%s \033[7m  \033[0m%s   \033[7m  \033[0m%s  ", "%s \033[7m  \033[0m%s   \033[7m \033[0m%s   \033[7m  \033[0m%s  ", "%s%s  \033[7m  \033[0m%s \033[7m  \033[0m%s   ", "%s%s \033[7m  \033[0m%s \033[7m  \033[0m%s  ", "%s%s\033[7m \033[0m%s  \033[7m  \033[0m%s   ", "%s%s%s\033[7m  \033[0m%s   ", "%s%s%s \033[7m  \033[0m%s    ", "%s%s%s  \033[7m  \033[0m%s ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s%s%s       ", "%s%s%s \033[7m  \033[0m%s ", "%s%s%s \033[7m \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m \033[0m%s  ", "%s%s \033[7m   \033[0m%s \033[7m  \033[0m%s ", "%s%s%s\033[7m      \033[0m%s "};
static const char *WHITESPACE_ART_ROW_MID[ALPHA_ART_ALPHABET_LENGTH]   = {"%s%s%s%s\t\t\t", "%s%s%s%snewline", "%s%s%s%s      ", "%s%s%s  \033[7m \033[0m%s   ", "%s%s%s%s      ", "%s%s   \033[7m \033[0m%s   \033[7m \033[0m%s    ", "%s%s%s  \033[7m     \033[0m%s   ", "%s%s%s  \033[7m  \033[0m%s   ", "%s%s \033[7m     \033[0m%s \033[7m  \033[0m%s ", "%s%s%s%s   ", "%s%s%s\033[7m  \033[0m%s   ", "%s%s%s  \033[7m  \033[0m%s ", "%s%s%s\033[7m       \033[0m%s ", "%s%s%s\033[7m         \033[0m%s ", "%s%s%s%s   ", "%s%s%s\033[7m     \033[0m%s ", "%s%s%s%s    ", "%s%s%s  \033[7m  \033[0m%s   ", "%s\033[7m \033[0m%s  \033[7m \033[0m%s  \033[7m \033[0m%s ", "%s%s%s   \033[7m \033[0m%s    ", "%s%s%s   \033[7m  \033[0m%s    ", "%s%s%s  \033[7m  \033[0m%s   ", "%s%s%s\033[7m     \033[0m%s ", "%s%s%s\033[7m    \033[0m%s   ", "%s%s%s\033[7m     \033[0m%s    ", "%s%s%s    \033[7m  \033[0m%s   ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s%s   ", "%s%s%s%s   ", "%s%s%s\033[7m  \033[0m%s  ", "%s%s%s%s       ", "%s%s%s \033[7m  \033[0m%s ", "%s%s%s    \033[7m  \033[0m%s  ", "%s%s\033[7m \033[0m%s  \033[7m    \033[0m%s ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s \033[7m    \033[0m%s ", "%s%s%s\033[7m  \033[0m%s     ", "%s%s\033[7m \033[0m%s  \033[7m  \033[0m%s ", "%s%s%s\033[7m   \033[0m%s    ", "%s%s%s \033[7m   \033[0m%s   ", "%s%s\033[7m  \033[0m%s \033[7m    \033[0m%s ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s \033[7m \033[0m%s  ", "%s%s\033[7m  \033[0m%s \033[7m \033[0m%s    ", "%s%s%s \033[7m   \033[0m%s    ", "%s%s%s \033[7m \033[0m%s    ", "%s \033[7m \033[0m%s \033[7m   \033[0m%s \033[7m \033[0m%s  ", "%s \033[7m \033[0m%s \033[7m  \033[0m%s \033[7m \033[0m%s   ", "%s%s\033[7m \033[0m%s   \033[7m \033[0m%s ", "%s%s%s \033[7m   \033[0m%s ", "%s%s\033[7m \033[0m%s   \033[7m \033[0m%s  ", "%s%s%s \033[7m   \033[0m%s   ", "%s%s%s   \033[7m  \033[0m%s    ", "%s%s%s  \033[7m \033[0m%s   ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s  ", "%s%s  \033[7m  \033[0m%s \033[7m  \033[0m%s   ", "%s  \033[7m  \033[0m%s \033[7m   \033[0m%s \033[7m  \033[0m%s   ", "%s%s%s   \033[7m   \033[0m%s    ", "%s%s%s  \033[7m   \033[0m%s   ", "%s%s%s  \033[7m  \033[0m%s    ", "%s%s%s\033[7m  \033[0m%s   ", "%s%s%s  \033[7m  \033[0m%s   ", "%s%s%s  \033[7m  \033[0m%s ", "%s%s%s%s      ", "%s%s%s%s       ", "%s%s%s%s    ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s\033[7m  \033[0m%s \033[7m   \033[0m%s  ", "%s%s%s\033[7m      \033[0m%s "};
static const char *WHITESPACE_ART_ROW_BOT[ALPHA_ART_ALPHABET_LENGTH]   = {"%s%s%s%s\t\t\t", "%s%s%s%snewline", "%s%s%s%s      ", "%s%s%s%s      ", "%s%s%s%s      ", "%s%s%s\033[7m           \033[0m%s ", "%s\033[7m \033[0m%s   \033[7m \033[0m%s \033[7m  \033[0m%s  ", "%s%s%s \033[7m  \033[0m%s    ", "%s%s\033[7m  \033[0m%s  \033[7m    \033[0m%s  ", "%s%s%s%s   ", "%s%s%s \033[7m  \033[0m%s  ", "%s%s%s \033[7m  \033[0m%s  ", "%s%s%s \033[7m     \033[0m%s  ", "%s%s%s    \033[7m \033[0m%s     ", "%s%s%s \033[7m \033[0m%s ", "%s%s%s%s      ", "%s%s%s%s    ", "%s%s%s \033[7m  \033[0m%s    ", "%s%s\033[7m  \033[0m%s   \033[7m  \033[0m%s ", "%s%s%s   \033[7m \033[0m%s    ", "%s%s  \033[7m  \033[0m%s   \033[7m \033[0m%s ", "%s%s\033[7m \033[0m%s  \033[7m  \033[0m%s  ", "%s%s%s   \033[7m \033[0m%s  ", "%s%s%s   \033[7m  \033[0m%s  ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s   ", "%s%s%s   \033[7m  \033[0m%s    ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s%s    \033[7m \033[0m%s  ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s \033[7m \033[0m%s ", "%s%s%s \033[7m  \033[0m%s ", "%s%s%s\033[7m      \033[0m%s ", "%s%s%s\033[7m  \033[0m%s  ", "%s%s%s   \033[7m \033[0m%s    ", "%s\033[7m \033[0m%s \033[7m  \033[0m%s  \033[7m \033[0m%s ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s  ", "%s%s \033[7m \033[0m%s  \033[7m \033[0m%s ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s\033[7m \033[0m%s \033[7m  \033[0m%s  ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s%s \033[7m \033[0m%s     ", "%s\033[7m  \033[0m%s  \033[7m \033[0m%s \033[7m \033[0m%s ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s  ", "%s%s%s \033[7m \033[0m%s  ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s    ", "%s%s \033[7m \033[0m%s \033[7m  \033[0m%s   ", "%s%s \033[7m \033[0m%s \033[7m  \033[0m%s ", "%s \033[7m \033[0m%s  \033[7m \033[0m%s  \033[7m \033[0m%s  ", "%s%s \033[7m \033[0m%s  \033[7m   \033[0m%s   ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s%s \033[7m \033[0m%s   ", "%s%s\033[7m  \033[0m%s \033[7m   \033[0m%s ", "%s%s \033[7m \033[0m%s \033[7m  \033[0m%s  ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s   ", "%s%s%s  \033[7m \033[0m%s   ", "%s%s \033[7m \033[0m%s \033[7m \033[0m%s  ", "%s%s%s   \033[7m   \033[0m%s    ", "%s%s   \033[7m   \033[0m%s \033[7m   \033[0m%s    ", "%s%s  \033[7m  \033[0m%s \033[7m  \033[0m%s   ", "%s%s%s   \033[7m \033[0m%s    ", "%s%s \033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s   ", "%s%s%s   \033[7m  \033[0m%s  ", "%s%s%s  \033[7m  \033[0m%s ", "%s%s%s%s      ", "%s%s%s%s       ", "%s%s%s%s    ", "%s%s%s \033[7m \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m \033[0m%s  ", "%s%s%s%s        ", "%s%s%s\033[7m      \033[0m%s "};
static const char *WHITESPACE_ART_ROW_FLOOR[ALPHA_ART_ALPHABET_LENGTH] = {"%s%s%s%s\t\t\t", "%s%s%s%snewline", "%s%s%s%s      ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s%s      ", "%s%s   \033[7m \033[0m%s   \033[7m \033[0m%s    ", "%s%s%s\033[7m       \033[0m%s   ", "%s%s\033[7m  \033[0m%s  \033[7m  \033[0m%s ", "%s%s \033[7m    \033[0m%s  \033[7m  \033[0m%s ", "%s%s%s%s   ", "%s%s%s  \033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s   ", "%s\033[7m  \033[0m%s \033[7m \033[0m%s \033[7m  \033[0m%s ", "%s%s%s    \033[7m \033[0m%s     ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s%s      ", "%s%s%s\033[7m   \033[0m%s ", "%s%s%s\033[7m  \033[0m%s     ", "%s%s%s \033[7m     \033[0m%s  ", "%s%s%s\033[7m       \033[0m%s ", "%s%s%s\033[7m        \033[0m%s ", "%s%s%s\033[7m     \033[0m%s  ", "%s%s%s  \033[7m   \033[0m%s ", "%s%s%s\033[7m    \033[0m%s   ", "%s%s%s\033[7m     \033[0m%s    ", "%s%s%s  \033[7m  \033[0m%s     ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s%s   ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s%s    ", "%s%s%s%s       ", "%s%s%s%s    ", "%s%s%s  \033[7m   \033[0m%s   ", "%s%s\033[7m \033[0m%s  \033[7m    \033[0m%s ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s%s\033[7m     \033[0m%s ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s\033[7m   \033[0m%s   ", "%s%s%s \033[7m    \033[0m%s  ", "%s%s%s\033[7m  \033[0m%s     ", "%s%s%s \033[7m    \033[0m%s   ", "%s%s\033[7m  \033[0m%s \033[7m  \033[0m%s ", "%s%s%s\033[7m   \033[0m%s ", "%s%s%s \033[7m   \033[0m%s    ", "%s%s\033[7m  \033[0m%s  \033[7m   \033[0m%s ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s\033[7m  \033[0m%s     \033[7m  \033[0m%s ", "%s%s\033[7m  \033[0m%s   \033[7m  \033[0m%s   ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s \033[7m \033[0m%s   ", "%s%s \033[7m   \033[0m%s \033[7m \033[0m%s ", "%s%s \033[7m \033[0m%s  \033[7m  \033[0m%s ", "%s%s%s \033[7m    \033[0m%s    ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s \033[7m   \033[0m%s  ", "%s%s%s    \033[7m \033[0m%s     ", "%s%s    \033[7m \033[0m%s   \033[7m \033[0m%s     ", "%s%s\033[7m   \033[0m%s   \033[7m   \033[0m%s ", "%s%s%s  \033[7m   \033[0m%s   ", "%s%s%s\033[7m      \033[0m%s  ", "%s%s%s\033[7m    \033[0m%s ", "%s%s%s    \033[7m  \033[0m%s ", "%s%s%s\033[7m    \033[0m%s ", "%s%s%s%s      ", "%s%s%s\033[7m      \033[0m%s ", "%s%s%s%s    ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s\033[7m  \033[0m%s ", "%s%s%s%s        ", "%s%s%s\033[7m      \033[0m%s "};
static const char **WHITESPACE_ART_MATRIX[TOTAL_WHITESPACE_ART_ROWS]   = {
  WHITESPACE_ART_ROW_CEIL, WHITESPACE_ART_ROW_TOP, WHITESPACE_ART_ROW_MID, WHITESPACE_ART_ROW_BOT, WHITESPACE_ART_ROW_FLOOR
};


// initialize array with zero's (wipes garbage memory)
#define FLOOD_ZEROS(FZ_ARR, FZ_ARR_LEN)({\
  int FLOOD_Z_i=0;\
  for(; FLOOD_Z_i<FZ_ARR_LEN; ++FLOOD_Z_i) FZ_ARR[FLOOD_Z_i]=0;\
})


// given char ARRAY (not literal) converts all lowercase to uppercase
static void mk_string_uppercase(char *p) {
  while(*p != '\0') {
    // don't uppercase any letters in ANSI Esc Sequences,
    // must keep as is for proper terminal style formatting
    if(*p == '\033') {
      while(*p != '\0' && !isalpha(*p)) ++p;
      ++p; // skip last char in ANSI Esc sequence
      continue;
    }
    *p = toupper(*p), ++p;
  }
}


// skips over ANSI Escape sequences (formats terminal output, each start w/ '\033')
// returns ANSI Escape sequence's length
static int skip_over_ANSI_Esc_sequence(const char non_art_buffer[], int idx, int ANSI_ESC_IDXS[], int *TOTAL_ANSI_ESC_SEQUENCES) {
  ANSI_ESC_IDXS[*TOTAL_ANSI_ESC_SEQUENCES] = idx; // save ANSI esc idx in string
  *TOTAL_ANSI_ESC_SEQUENCES += 1;
  while(non_art_buffer[idx] != '\0' && !isalpha(non_art_buffer[idx])) ++idx;
  return idx;
}


// returns hashed idx of Alpha-Art letter position in rows of ASCII_ART_MATRIX/WHITESPACE_ART_MATRIX
static int ascii_art_idx_hash_function(const char c) {
  // idx of ASCII-art-unknown char repn & total prefixing cntrl chars '\t\n' 
  const int UNKNOWN_ART_IDX = ALPHA_ART_ALPHABET_LENGTH - 3,
            TOTAL_CNTRL_CHARS = 2; // '\t', '\n'
  // check if char has an equivalent repn in the ASCII art alphabet
  if(strrchr(VALID_ALPHA_ART_CHARS, c) == NULL)
    return UNKNOWN_ART_IDX;
  // return valid ASCII-Art char's hashed idx 
  if(c == '\b') return BACKSPACE_ART_IDX;
  return (c == '\t' || c == '\n')
    ? c - '\t'
    : TOTAL_CNTRL_CHARS + c - ' ' - ((c >= 'a') * 26);
}


// fills "idxs_container[]" with the hashed idx of each char in "output[]"
// returns length of filled "idxs_container" array
static int get_hashed_art_idxs(int idxs_container[], const char non_art_buffer[], int ANSI_ESC_IDXS[], int *TOTAL_ANSI_ESC_SEQUENCES) {
  int idx = 0, i = 0;
  const int non_art_length = strlen(non_art_buffer);
  for(; idx < non_art_length; ++idx) {
    if(non_art_buffer[idx] == '\033') { // skip ANSI esc sequences
      idx = skip_over_ANSI_Esc_sequence(non_art_buffer, idx, ANSI_ESC_IDXS, TOTAL_ANSI_ESC_SEQUENCES);
      idxs_container[i++] = ANSI_ESC_ART_IDX; // store denote idx instance to read from string later on output
      continue;
    }
    idxs_container[i++] = ascii_art_idx_hash_function(non_art_buffer[idx]);
  }
  return i;
}


// returns whether 'str' points to the particular substring 'substr'
bool is_at_substring(const char *p, const char *substr) {
  while(*substr != '\0' && *p != '\0' && *p == *substr) ++p, ++substr;
  return (*substr == '\0');
}


// fills "art_buffer" with "non_art_string"'s chars in ASCII/Whitespace Art
static void convert_non_art_string_to_alpha_art(char non_art_string[], char art_buffer[], const int TOTAL_ROWS, const char **ALPHA_ART_MATRIX[TOTAL_ROWS]) {
  const int NEWLINE_ART_IDX = 1; // idx (hash value) of '\n' ASCII art repn
  bool is_ascii_art = (TOTAL_ROWS == TOTAL_ASCII_ART_ROWS);

  // array of hashed letter idxs for ASCII/Whitespace-art variant's row positions
  int alpha_art_letter_idxs[MAX_ALPHA_ART_BUFFER_LENGTH];
  FLOOD_ZEROS(alpha_art_letter_idxs, MAX_ALPHA_ART_BUFFER_LENGTH);

  // convert lowercase letters to uppercase, non_art_buffer holds 
  // uppercased/formatted "non_art_string" & "art_buffer" holds ascii/whitespace art
  char non_art_buffer[MAX_ALPHA_ART_BUFFER_LENGTH], *p = art_buffer, *ansi_ptr;
  FLOOD_ZEROS(non_art_buffer, MAX_ALPHA_ART_BUFFER_LENGTH); 
  strcpy(non_art_buffer, non_art_string), mk_string_uppercase(non_art_buffer);

  // Idxs of ANSI Esc key instances (ie from using the colors/text-deco above) 
  // in the client's non-art string
  int ANSI_ESC_IDXS[ALPHA_ART_ALPHABET_LENGTH], TOTAL_ANSI_ESC_SEQUENCES = 0;
  FLOOD_ZEROS(ANSI_ESC_IDXS, ALPHA_ART_ALPHABET_LENGTH);
  char whitespace_art_ANSI_cmd_buffer[MAX_ANSI_CMD_LENGTH], *last_cmd;

  // get hashed idxs of letter ASCII/Whitespace-art variant positions in the "ALPHA_ART_MATRIX"
  const int total_idxs = get_hashed_art_idxs(alpha_art_letter_idxs, non_art_buffer, ANSI_ESC_IDXS, &TOTAL_ANSI_ESC_SEQUENCES);

  // ANSI buffer to hold user-defined ansi cmds passed for whitespaces (requires special means of splicing them in)
  FLOOD_ZEROS(whitespace_art_ANSI_cmd_buffer, MAX_ANSI_CMD_LENGTH);
  strcpy(whitespace_art_ANSI_cmd_buffer, "\033[0m");

  // get each row for the alpha art letters, sprintf'ing each until '\0' or '\n' is reached (if '\n' 
  // reached, restart the process of getting rows but ONLY for chars AFTER the '\n' in "non_art_buffer")
  int prior_char_idx = -1, prior_char_length, string_start, newline_or_end, PRIOR_NEWLINE_ANSI_IDX = 0, ASNI_IDX = 0, idx, row, i;

  for(string_start = 0; string_start < total_idxs; ++string_start) {
    // for each alpha art row
    // PRIOR_NEWLINE_ANSI_IDX = 0;
    for(row = 0; row < TOTAL_ROWS; ++row) { 
      ASNI_IDX = PRIOR_NEWLINE_ANSI_IDX;
      FLOOD_ZEROS(whitespace_art_ANSI_cmd_buffer, MAX_ANSI_CMD_LENGTH); // reset ANSI codes
      // up until '\0' or '\n' is reached
      for(idx = string_start; idx < total_idxs && alpha_art_letter_idxs[idx] != NEWLINE_ART_IDX; ++idx) {
        
        // sprintf ANSI esc sequences directly from the non-art string
        if(alpha_art_letter_idxs[idx] == ANSI_ESC_ART_IDX) {
          ansi_ptr = &non_art_buffer[ANSI_ESC_IDXS[ASNI_IDX++]];
          // sprintf the ANSI Esc sequence (text deco/coloring) to the string
          // => ENABLES USING THIS LIBRARY'S COLORS/TEXT-DECO W/ ALPHA ART!
          // save ANSI commands passed by user to sprintf for each Whitespace art letter
          if(is_at_substring(ansi_ptr, Reset))
            FLOOD_ZEROS(whitespace_art_ANSI_cmd_buffer, MAX_ANSI_CMD_LENGTH);
          last_cmd = &whitespace_art_ANSI_cmd_buffer[strlen(whitespace_art_ANSI_cmd_buffer)];

          // copy ANSI cmds from user into the "whitespace_art_ANSI_cmd_buffer" & the "art_buffer" strings
          while(*ansi_ptr != '\0' && !isalpha(*ansi_ptr)) *p++ = *ansi_ptr, *last_cmd++ = *ansi_ptr++;
          *p++ = *ansi_ptr, *last_cmd++ = *ansi_ptr++; // sprintf last char in ANSI Esc Sequence
          *last_cmd = '\0';

        // if at a backspace, move back the width of the preceding character
        } else if(alpha_art_letter_idxs[idx] == BACKSPACE_ART_IDX) {
          if(prior_char_idx > -1) {
            prior_char_length = strlen(ALPHA_ART_MATRIX[row][alpha_art_letter_idxs[prior_char_idx]]);
            for(i = 0; i < prior_char_length; ++i) sprintf(p, "\b"), p += strlen(p);
            --prior_char_idx;
          }
        } else { // non-backspace & non-ANSI cmd
          prior_char_idx = idx;
          if(is_ascii_art) // don't sprintf ANSI codes into letter for ASCII
            strcpy(p, ALPHA_ART_MATRIX[row][alpha_art_letter_idxs[idx]]);
          else
            sprintf(p, ALPHA_ART_MATRIX[row][alpha_art_letter_idxs[idx]], 
              whitespace_art_ANSI_cmd_buffer, whitespace_art_ANSI_cmd_buffer, 
              whitespace_art_ANSI_cmd_buffer, whitespace_art_ANSI_cmd_buffer);
          p += strlen(p);
        }
      }
      if(row == TOTAL_ROWS - 1) 
        PRIOR_NEWLINE_ANSI_IDX = ASNI_IDX; // store the last ANSI cmd index to invoke after a '\n'
      strcpy(p, "\033[0m\n"), // IMPLICIT "RESET" BEFORE '\n' WRT TO ASCII/WHITESPACE ART PRINTING!
      p += strlen(p), newline_or_end = idx;
    }
    string_start = newline_or_end;
  }
  strcpy(p, "\033[0m");
}


// fprintf alpha art (ascii or whitespace as per "is_ascii_art" bool) for "non_art_string" to "fptr"
static void alpha_art_fprintf_non_art_string(FILE *fptr, char non_art_string[], bool is_ascii_art) {
  // string to hold ascii/whitespace art variants of chars in client's "non_art_string"
  char alpha_art_buffer[MAX_ALPHA_ART_BUFFER_LENGTH];
  FLOOD_ZEROS(alpha_art_buffer, MAX_ALPHA_ART_BUFFER_LENGTH);
  if(is_ascii_art)
    convert_non_art_string_to_alpha_art(non_art_string, alpha_art_buffer, TOTAL_ASCII_ART_ROWS, ASCII_ART_MATRIX);
  else
    convert_non_art_string_to_alpha_art(non_art_string, alpha_art_buffer, TOTAL_WHITESPACE_ART_ROWS, WHITESPACE_ART_MATRIX);
  fprintf(fptr, "%s", alpha_art_buffer), fflush(fptr);
}

/******************************************************************************
* PRIVATE INTERFACES: ASCII/WHITESPACE ART PRINTING/STRLEN MAIN FUNCTIONS
******************************************************************************/

// fprintf the Alpha Art equivalent of the string to "FPRINTF_ART_FILEPTR",
// sprintf's 1st to splice in any "%s" (or other) substitutions prior 
// to converting string to ASCII/Whitespace Art (as per FPRINTF_ART_PRINTING_ASCII bool)
#define fprintf_art(FPRINTF_ART_PRINTING_ASCII, FPRINTF_ART_FILEPTR, ...) ({\
  char fprintf_art_non_art_string[MAX_ALPHA_ART_BUFFER_LENGTH];\
  FLOOD_ZEROS(fprintf_art_non_art_string, MAX_ALPHA_ART_BUFFER_LENGTH);\
  sprintf(fprintf_art_non_art_string, __VA_ARGS__);\
  alpha_art_fprintf_non_art_string(FPRINTF_ART_FILEPTR, fprintf_art_non_art_string, FPRINTF_ART_PRINTING_ASCII);\
})


// sprintf the Alpha Art equivalent of the string into "SPRINTF_ART_STR",
// sprintf's 1st to splice in any "%s" (or other) substitutions prior 
// to converting string to Alpha Art
#define sprintf_art(SPRINTF_ART_PRINTING_ASCII, SPRINTF_ART_STR, ...) ({\
  char sprintf_art_non_art_string[MAX_ALPHA_ART_BUFFER_LENGTH];\
  FLOOD_ZEROS(sprintf_art_non_art_string, MAX_ALPHA_ART_BUFFER_LENGTH);\
  sprintf(sprintf_art_non_art_string, __VA_ARGS__);\
  if(SPRINTF_ART_PRINTING_ASCII)\
    convert_non_art_string_to_alpha_art(sprintf_art_non_art_string, SPRINTF_ART_STR, TOTAL_ASCII_ART_ROWS, ASCII_ART_MATRIX);\
  else\
    convert_non_art_string_to_alpha_art(sprintf_art_non_art_string, SPRINTF_ART_STR, TOTAL_WHITESPACE_ART_ROWS, WHITESPACE_ART_MATRIX);\
})


// "strlen" for Alpha art: returns the length needed to contain 
// "non_art_string"'s Alpha-art (ascii or whitespace) equivalent
static int alphaArtStrlen(bool is_ascii_art, char *non_art_string) {
  char alpha_art_buffer[MAX_ALPHA_ART_BUFFER_LENGTH];
  FLOOD_ZEROS(alpha_art_buffer, MAX_ALPHA_ART_BUFFER_LENGTH);
  if(is_ascii_art)
    convert_non_art_string_to_alpha_art(non_art_string, alpha_art_buffer, TOTAL_ASCII_ART_ROWS, ASCII_ART_MATRIX);
  else
    convert_non_art_string_to_alpha_art(non_art_string, alpha_art_buffer, TOTAL_WHITESPACE_ART_ROWS, WHITESPACE_ART_MATRIX);
  return strlen(alpha_art_buffer);
}


// printf's an entire Alpha art alphabet (demo for library info, like showColors() above)
static void showAlphaArt(bool is_ascii_art, const int TOTAL_ROWS, const char **ALPHA_ART_MATRIX[TOTAL_ROWS]) {
  int row, letter, cluster, remaining_letters,
      cluster_length = (is_ascii_art) ? 13 : 8; // # of letters to print at once
  if(is_ascii_art)
    printf("\n\033[1m>> \033[4mASCII Art Alphabet\033[0m\033[1m:\033[0m");
  else
    printf("\n\033[1m>> \033[4mWhitespace Art Alphabet\033[0m\033[1m:\033[0m");
  printf("\n\033[1m   >> \033[4mLower-Case Letters Are Upper-Cased!\033[0m");
  printf("\n\033[1m   >> \033[4mCharacters Supported\033[0m\033[1m:\033[0m ");
  printf("!\"#$%%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`{|}~");
  printf("\n\033[1m   >> \033[4m'Space' & 3 Control Chars Supported\033[0m\033[1m:\033[0m ' ', '\\b', '\\t', '\\n'\033[0m\n\n");
  // "cluster = 3" to skip ' ', '\t' & '\n',
  // "ALPHA_ART_ALPHABET_LENGTH - 3" to skip unknown char repn && '\b' && '\033'
  for(cluster = 3; cluster < ALPHA_ART_ALPHABET_LENGTH - 3; cluster += cluster_length) {
    // combine the last row of 3 slim chars w/ the 2nd to last row
    if(cluster + 2 * cluster_length > ALPHA_ART_ALPHABET_LENGTH - 3) cluster_length = 16;
    remaining_letters = (cluster + cluster_length > ALPHA_ART_ALPHABET_LENGTH - 3)
                        ? (ALPHA_ART_ALPHABET_LENGTH - 3)
                        : (cluster + cluster_length);
    for(row = 0; row < TOTAL_ROWS; ++row) {
      printf("   ");
      for(letter = cluster; letter < remaining_letters; ++letter) {
        if(is_ascii_art)
          printf("%s", ALPHA_ART_MATRIX[row][letter]);
        else
          printf(ALPHA_ART_MATRIX[row][letter], "", "", "", "");
      }
      printf("\n");
    }
    printf("\n");
  }
}

/******************************************************************************
* PRIVATE INTERFACES: ASCII/WHITESPACE ART RAW STRING GENERATION
******************************************************************************/

// Generates a raw-string version of the art that can be copied/output anywhere
// => Hence ALL of color.h need not be #include'd just to print out a single
//    stylized message, simply use the library to generate the message then 
//    cpy/paste it into your other program.
static void get_raw_art_string(const char *non_art_string, char *raw_art_string_buffer, bool print_ascii) {
  // Copy const char arg to a char buffer
  char non_art_buffer[MAX_ALPHA_ART_BUFFER_LENGTH];
  FLOOD_ZEROS(non_art_buffer, MAX_ALPHA_ART_BUFFER_LENGTH); 
  strcpy(non_art_buffer, non_art_string), mk_string_uppercase(non_art_buffer);

  // Declare & prep buffer to hold raw art string
  char alpha_art_buffer[MAX_ALPHA_ART_BUFFER_LENGTH];
  FLOOD_ZEROS(alpha_art_buffer, MAX_ALPHA_ART_BUFFER_LENGTH);

  // Get ASCII or Whitespace art string (as needed)
  sprintf_art(print_ascii, alpha_art_buffer, "%s", non_art_buffer);

  // Pointers to read the art buffer & write the raw version to the 
  // raw-art-string buffer
  char *write_to = raw_art_string_buffer, *read_from = alpha_art_buffer;

  while(*read_from != '\0') {
    // Escape ANSI escape character in charge of formatting terminal font
    if(*read_from == '\033') {
      *write_to++ = '\\';
      *write_to++ = '0';
      *write_to++ = '3';
      *write_to++ = '3';
      ++read_from;
    } 

    // Escape Back-slashes
    if(*read_from == '\\') *write_to++ = '\\';

    // Escape the designated cntrl characters allowed by the ASCII & Whitespace
    // art printing fcns
    if(*read_from == '\n' || *read_from == '\t' || *read_from == '\b') {
      *write_to++ = '\\';
      switch(*read_from) {
        case '\n': *write_to++ = 'n'; break;
        case '\t': *write_to++ = 't'; break;
        case '\b': *write_to++ = 'b'; break;
      }
      ++read_from;
      continue;
    }

    *write_to++ = *read_from++; // Copy the char
  }
  *read_from = '\0';
}


// Handles raw string generation, THE MAIN CONTROLLER as to whether the raw str
// ought to be printed to a file or to another str, and whether to use ASCII or
// Whitespace art.
static void handle_raw_string(char *styled_non_art_string, char *write_to, FILE *fptr, bool print_ascii, bool print_to_file) {
  char raw_art_string_buffer[MAX_ALPHA_ART_BUFFER_LENGTH];
  FLOOD_ZEROS(raw_art_string_buffer, MAX_ALPHA_ART_BUFFER_LENGTH);
  get_raw_art_string(styled_non_art_string,raw_art_string_buffer,print_ascii);
  if(print_to_file)
    fprintf(fptr,"%s\n",raw_art_string_buffer), fflush(fptr);
  else
    sprintf(write_to, "%s", raw_art_string_buffer);
}


// fprintf the RAW ASCII/WHITESPACE Art equivalent of the string to "FPRINT_RAW_FILEPTR"
#define fprint_raw_art(FPRINT_RAW_FILEPTR,FPRINT_ASCII,...)({\
  char fprint_raw_styled_non_art_string[MAX_ALPHA_ART_BUFFER_LENGTH];\
  FLOOD_ZEROS(fprint_raw_styled_non_art_string, MAX_ALPHA_ART_BUFFER_LENGTH);\
  sprintf(fprint_raw_styled_non_art_string, __VA_ARGS__);\
  handle_raw_string(fprint_raw_styled_non_art_string,NULL,FPRINT_RAW_FILEPTR,FPRINT_ASCII,true);\
})


// sprintf the RAW ASCII/WHITESPACE Art equivalent of the string to "SPRINT_RAW_STR"
#define sprintf_raw_art(SPRINT_RAW_STR,SPRINT_ASCII,...)({\
  char sprint_raw_styled_non_art_string[MAX_ALPHA_ART_BUFFER_LENGTH];\
  FLOOD_ZEROS(sprint_raw_styled_non_art_string, MAX_ALPHA_ART_BUFFER_LENGTH);\
  sprintf(sprint_raw_styled_non_art_string, __VA_ARGS__);\
  handle_raw_string(sprint_raw_styled_non_art_string,SPRINT_RAW_STR,stdout,SPRINT_ASCII,false);\
})

/******************************************************************************
* PUBLIC INTERFACES: ASCII ART PRINTING MACROS & "STRLEN" FOR ASCII ART
******************************************************************************/


// NOTE: ASCII/WHITESPACE ART PRINTING MACROS IMPLICITLY INVOKE "Reset" AT '\n's AND AT THEIR END


// fprintf the ASCII Art equivalent of the string to "FPRINTA_FILEPTR"
#define fprinta(FPRINTA_FILEPTR, ...) fprintf_art(true, FPRINTA_FILEPTR, __VA_ARGS__)
// sprintf the ASCII Art equivalent of the string into "SPRINTA_STR"
#define sprinta(SPRINTA_STR, ...) sprintf_art(true, SPRINTA_STR, __VA_ARGS__)
// printf the ASCII Art equivalent of the given string
#define printa(...) fprintf_art(true, stdout, __VA_ARGS__)


// fprintf the RAW ASCII Art equivalent of the string to "FPRINTA_FILEPTR"
#define fprinta_raw(FPRINTA_FILEPTR, ...) fprint_raw_art(FPRINTA_FILEPTR,true,__VA_ARGS__)
// sprintf the RAW ASCII Art equivalent of the string into "SPRINTA_STR"
#define sprinta_raw(SPRINTA_STR, ...) sprintf_raw_art(SPRINTA_STR,true,__VA_ARGS__)
// printf the RAW ASCII Art equivalent of the given string
#define printa_raw(...) fprint_raw_art(stdout,true,__VA_ARGS__)


// return strlen needed to contain "non_art_string" in ASCII art
int asciiArtStrlen(const char *non_art_string) {
  char sprintf_art_non_art_string[MAX_ALPHA_ART_BUFFER_LENGTH];
  FLOOD_ZEROS(sprintf_art_non_art_string, MAX_ALPHA_ART_BUFFER_LENGTH);
  strcpy(sprintf_art_non_art_string, non_art_string);
  return alphaArtStrlen(true, sprintf_art_non_art_string);
}

// printf's entire ASCII art alphabet (demo for library info, like showColors() above)
void showAsciiArt() {
  showAlphaArt(true, TOTAL_ASCII_ART_ROWS, ASCII_ART_MATRIX);
}

/******************************************************************************
* PUBLIC INTERFACES: WHITESPACE ART PRINTING MACROS/"STRLEN" FOR WHITESPACE ART
******************************************************************************/


// NOTE: ASCII/WHITESPACE ART PRINTING MACROS IMPLICITLY INVOKE "Reset" AT '\n's AND AT THEIR END
// NOTE: NEVER USER "Rev" WITH WHITESPACE ART !!!


// fprintf the Whitespace Art equivalent of the string to "FPRINTW_FILEPTR"
#define fprintw(FPRINTW_FILEPTR, ...) fprintf_art(false, FPRINTW_FILEPTR, __VA_ARGS__)
// sprintf the Whitespace Art equivalent of the string into "SPRINTW_STR"
#define sprintw(SPRINTW_STR, ...) sprintf_art(false, SPRINTW_STR, __VA_ARGS__)
// printf the Whitespace Art equivalent of the given string
#define printw(...) fprintf_art(false, stdout, __VA_ARGS__)


// fprintf the RAW Whitespace Art equivalent of the string to "FPRINTW_FILEPTR"
#define fprintw_raw(FPRINTW_FILEPTR, ...) fprint_raw_art(FPRINTW_FILEPTR,false,__VA_ARGS__)
// sprintf the RAW Whitespace Art equivalent of the string into "SPRINTW_STR"
#define sprintw_raw(SPRINTW_STR, ...) sprintf_raw_art(SPRINTW_STR,false,__VA_ARGS__)
// printf the RAW Whitespace Art equivalent of the given string
#define printw_raw(...) fprint_raw_art(stdout,false,__VA_ARGS__)


// return strlen needed to contain "non_art_string" in Whitespace art
int whitespaceArtStrlen(const char *non_art_string) {
  char sprintf_art_non_art_string[MAX_ALPHA_ART_BUFFER_LENGTH];
  FLOOD_ZEROS(sprintf_art_non_art_string, MAX_ALPHA_ART_BUFFER_LENGTH);
  strcpy(sprintf_art_non_art_string, non_art_string);
  return alphaArtStrlen(false, sprintf_art_non_art_string);
}

// printf's entire Whitespace art alphabet (demo for library info, like showColors() above)
void showWhitespaceArt() {
  showAlphaArt(false, TOTAL_WHITESPACE_ART_ROWS, WHITESPACE_ART_MATRIX);
}

#endif
