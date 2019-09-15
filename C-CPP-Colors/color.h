// AUTHOR: JORDAN RANDLEMAN - color.h - Easier Interface For ANSI Esc Codes
// -:- COLORS/TEXT-DECORATION IN TERMINAL FOR BOTH C & C++ -:-

// Sources For ANSI Esc Codes: 
// 1) http://www.lihaoyi.com/post/BuildyourownCommandlinewithANSIescapecodes.html
// 2) http://www.climagic.org/mirrors/VT100_Escape_Codes.html

#ifndef COLOR_H_
#define COLOR_H_

#include <stdio.h>
#include <string.h>

/******************************************************************************
* C++ std::endl ALTERNATIVE: "reset" + "\n"
******************************************************************************/

#ifdef __cplusplus
namespace color { const char* rendl = "\033[0m\n"; }
#endif

/******************************************************************************
* OUTPUT + RESET SYNTAX
******************************************************************************/

// output macros automatically 'r'esetting SYNTAX after output
#define rprintf(...) ({printf(__VA_ARGS__);printf("\033[0m");})
#define rsprintf(STR, ...)\
  ({sprintf(STR, __VA_ARGS__);sprintf(&STR[strlen(STR)], "\033[0m");})
#define rfprintf(FILENAME, ...)\
  ({fprintf(FILENAME, __VA_ARGS__);fprintf(FILENAME, "\033[0m");})

/******************************************************************************
* KEYPAD ARROW MOVEMENTS
******************************************************************************/

// move the cursor up, down, left, & right "MOVE_AMOUNT" positions
#define keyup(MOVE_AMOUNT)    "\033[" #MOVE_AMOUNT "A"
#define keydown(MOVE_AMOUNT)  "\033[" #MOVE_AMOUNT "B"
#define keyright(MOVE_AMOUNT) "\033[" #MOVE_AMOUNT "C"
#define keyleft(MOVE_AMOUNT)  "\033[" #MOVE_AMOUNT "D"

/******************************************************************************
* RESET SYNTAX / CLEAR SCREEN
******************************************************************************/

// reset syntax settings
#define reset "\033[0m"

// clear current screen
#define clear "\033[2J"

/******************************************************************************
* DECORATIONS - BOLD, UNDERLINE, REVERSE BACKGROUND/TEXT COLORS
******************************************************************************/

// bold, underline, & reverse background/text colors
#define bold  "\033[1m" 
#define line  "\033[4m"
#define rev   "\033[7m"
// decoration combinations named alphabetically
#define boldline    bold line
#define boldrev     bold rev
#define linerev     line rev
#define boldlinerev bold line rev

/******************************************************************************
* TEXT COLORS
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
#define red6 "\033[38;5;196m"
#define red7 "\033[38;5;9m"
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
* BACKGROUND COLORS - PREFIXED BY "b"
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
#define bred6 "\033[48;5;196m"
#define bred7 "\033[48;5;9m"
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
* SHOW AVAILABLE COLORS FUNCTION
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
  const int reds[8]     = {  52,  88,   1, 124, 160, 196,   9, 197 };
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
  rprintf("\n%s>> %sBasic 8 Colors:\n%s  bblack ", bold, reset bold line,
    reset white8 bblack);
  for(i = 1; i < 8; ++i) // output basic background colors
    rprintf("%s\033[4%dm%s ", black, i, basic_background_colors[i]);
  rprintf("\n%s   black ", reset black);
  for(i = 1; i < 8; ++i) // output basic text colors
    rprintf("\033[3%dm%s ", i, basic_text_colors[i]);
  

  // OUTPUT COLOR GRADIENTS
  rprintf("\n\n%s>> %sExtended Color Gradients:\n", bold, reset bold line);
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
#endif
