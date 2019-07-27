// Author: Jordan Randleman - S-p-l-i-t-S-t-r-i-n-g Library

#ifndef SPLIT_H_
#define SPLIT_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// Garbage Collection Structures.
typedef struct jaggedSplit { char **matrix; } JAGGEDSPLIT;
typedef struct splitCpysStruct { 
  int length;
  JAGGEDSPLIT cpys[]; // Flexible Array of Matrices.
} SPLITCPYS_STRUCT;
SPLITCPYS_STRUCT SSGC; // (S)plit (S)tring (G)arbage (C)ollector
int firstCall = -1;

// O(n): Copy 'length' chars from 'ptr' to 'temp'.
#define JR_SUBSTRING(temp, ptr, length) ({ \
  char *q = temp, *r = ptr; \
  for(int i = 0; i < length && *r != '\0'; i++) *q++ = *r++; \
  *q = '\0'; \
})

/******************************************************************************
* A USER'S HOW-TO
******************************************************************************/

void splitHelp() {
  printf("\n\
**************************************************************************************\n\
******************************* -:- A USER'S HOW TO -:- ******************************\n\
**************************************************************************************\n\
*                                                                                    *\n\
*  Using split.h:                                                                    *\n\
*  | L_ char** splitMatrix = split(\"your string\", \"split instance\");                 *\n\
*  | | L_ Matrix rows are \"your string\"'s segments split at every \"split instance\".  *\n\
*  | | L_ Matrix ends when 1st char in row == '\\0' (ie splitMatrix[i][0] == '\\0').   *\n\
*  | | L_ Both literals & variables work for \"your string\" & \"split instance\".       *\n\
*  | L_ splitHelp():  Printf this message.                                           *\n\
*  |                                                                                 *\n\
*  With Respect to Memory Management:                                                *\n\
*    L_ split() does not modify the original string passed to it.                    *\n\
*    L_ Matrices returned by split() have automated garbage collection.              *\n\
*                                                                                    *\n\
**************************************************************************************\n");
}

/******************************************************************************
* GARBAGE COLLECTION FUNCTIONS
******************************************************************************/

// O(n^2): Automated Garbage Collection Frees Matrices returned by 'split()'.
static void rmSSGC() { 
  for(int i = 0, j; i < SSGC.length; i++) {
    for(j = 0; SSGC.cpys[i].matrix[j][0] != '\0'; j++) { // Free each Segment
      free(SSGC.cpys[i].matrix[j]);
    }
    free(SSGC.cpys[i].matrix[j]), free(SSGC.cpys[i].matrix); // Free the Matrix
  }
}

// O(1): Preps Garbage Collector.
static void mkSSGC() { firstCall = 0, SSGC.length = 0, atexit(rmSSGC); }

/******************************************************************************
* SPLIT() HELPER FUNCTION
******************************************************************************/

// O(n^2): Returns # of matrix rows/cols for 'str' split at every 'splitHere' instance.
static void getSplitDimensions(char *str, char *splitHere, int *splitRows, int *splitCols) {
  int row = 0, maxColSize = 0;
  for(int col, splitSize = strlen(splitHere); *str != '\0'; row++) {
    for(col = 0; *str != '\0'; col++, str++) {
      char temp[splitSize + 1]; JR_SUBSTRING(temp, str, splitSize);
      if(strcmp(splitHere, temp) == 0) { str += splitSize; break; }
    }
    if(col > maxColSize) maxColSize = col;
  }
  *splitRows = row + 1, *splitCols = maxColSize + 1; // Extra row & col for '\0''s
}

/******************************************************************************
* MAIN SPLIT() FUNCTION => DOES NOT MODIFY ORIGINAL STRING!
******************************************************************************/

// O(n^2): Returns a Matrix of 'str' split at every 'splitHere' instance.
char** split(char *str, char *splitHere) {
  if(firstCall == -1) mkSSGC();
  int hasSplit = (strlen(splitHere) > 0); // 'splitHere' != ""
  // Allocate memory for the split-string Buffer matrix.
  int splitRows, splitCols;
  if(hasSplit) getSplitDimensions(str, splitHere, &splitRows, &splitCols);
  else splitRows = 2, splitCols = strlen(str) + 1;
  char** buffer = malloc(sizeof(char *) * splitRows);
  assert(buffer != NULL);
  for(int i = 0; i < splitRows; i++) {
    assert((buffer[i] = malloc(sizeof(char) * splitCols)) != NULL);
  }
  buffer[splitRows - 1][0] = '\0';
  // Fill the Buffer matrix with segments of the split 'str'.
  // Buffer ends when 1st char in row == '\0' (ie when buffer[i][0] == '\0').
  if(hasSplit) {
    for(int row = 0, col, splitSize = strlen(splitHere); *str != '\0'; row++) {
      for(col = 0; *str != '\0'; col++, str++) {
        char temp[splitSize + 1]; JR_SUBSTRING(temp, str, splitSize);
        if(strcmp(splitHere, temp) == 0) { str += splitSize; break; }
        buffer[row][col] = *str;
      }
      buffer[row][col] = '\0';
    }
  } else strcpy(buffer[0], str);
  // Point the Garbage Collector at the split-string Buffer.
  SSGC.cpys[SSGC.length++].matrix = buffer;
  return buffer;
}

#endif
