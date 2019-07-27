// Author: Jordan Randleman - (C)(S)tring(O)bject(N)otation

#ifndef CSON_H_
#define CSON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// cson Structure.
typedef struct CStringObjectNotation {
  int maxElts, length;
  char **keys, **vals;
} CSON_STRUCT;
CSON_STRUCT *CSON = NULL; // C String Object Notation.

// KVC Garbage-Collection Structure for 'KeyValueCopy' Arrays.
typedef struct myMatrices { char **matrix; } MYMATRICES;
typedef struct keyValCpys { 
  int keyLength, keyMaxElts, valLength, valMaxElts;
  MYMATRICES keysCpy[100], valsCpy[100];
} KEYVALCPYS;
KEYVALCPYS KVC; 

#define cson *csonValueAddress // For UI's sake. 

/******************************************************************************
* A USER'S HOW-TO
******************************************************************************/

void csonHelp() { 
printf("\n\
**************************************************************************************\n\
******************************* -:- A USER'S HOW TO -:- ******************************\n\
**************************************************************************************\n\
*                                                                                    *\n\
*  Using cson.h, C String Object Notation:                                           *\n\
*  | L_ cson(\"yourKey\"): Global 'object' to add, get, & rmv values.                  *\n\
*  | | L_ Add: cson(\"author\") = \"Jordan\";      // Add \"Jordan\" val to \"author\" key.  *\n\
*  | | L_ Get: char *myValue = cson(\"author\"); // Returns \"author\" val (\"Jordan\").   *\n\
*  | | L_ Rmv: cson(\"author\") = NULL;          // Rmv cson \"author\" key-value pair.  *\n\
*  | L_ csonHas(\"yourKey\"): Returns 1/0 if \"yourKey\" does/doesn't exist in cson.     *\n\
*  | L_ csonSize():  Returns cson's current number of key-value pairs.               *\n\
*  | L_ csonKeys() & csonVals(): Returns a matrix of cson's current keys/values.     *\n\
*  | L_ csonPrint(): Printf all of cson's current key-value pairs.                   *\n\
*  | L_ csonHelp():  Printf this message.                                            *\n\
*  |                                                                                 *\n\
*  A Note On Garbage Collection:                                                     *\n\
*    L_ cson() & any arrays from csonKeys/Vals have automated garbage collection.    *\n\
*                                                                                    *\n\
**************************************************************************************\n");
}

/******************************************************************************
* MAKE/RMV GLOBAL 'CSON' (& UNDER-THE-HOOD 'KVC') GARBAGE COLLECTION FUNCTIONS
******************************************************************************/

// O(n): Free cson & KVC's allocated memory.
static void rmCSON() {
  for(int i = 0; i < KVC.keyMaxElts; i++) free(KVC.keysCpy[i].matrix);
  for(int i = 0; i < KVC.valMaxElts; i++) free(KVC.valsCpy[i].matrix);
  free(CSON -> keys), free(CSON -> vals), free(CSON);
}

// O(1): Initialize cson (& KVC for keyValCpy array garbage collection).
static void mkCSON() {
  KVC.keyMaxElts = 100, KVC.valMaxElts = 100, KVC.keyLength = 0, KVC.valLength = 0;
  CSON = malloc(sizeof(CSON_STRUCT *));
  assert(CSON != NULL);
  CSON -> keys = malloc(sizeof(char *) * 100);
  CSON -> vals = malloc(sizeof(char *) * 100);
  assert(CSON -> keys != NULL && CSON -> vals != NULL);
  CSON -> maxElts = 100, CSON -> length = 0;
  atexit(rmCSON); // Garbage collection: automatically frees memory on exit.
}

/******************************************************************************
* 'CSON' RM-NULL-PAIRS, SEARCH, PRINT, SIZE, & EXISTS-IN FUNCTIONS
******************************************************************************/

// O(1): Removes last key-value pair if NULL value.
static void stripCsonNulls() {
  assert(CSON != NULL && CSON -> keys != NULL && CSON -> vals != NULL);
  if(CSON -> length == 0) return;
  char *lastVal = CSON -> vals[CSON -> length - 1];
  char *lastKey = CSON -> keys[CSON -> length - 1];
  if(lastVal == NULL && lastKey != NULL) {
    lastKey = NULL;
    CSON -> length--;
  }
}

// O(n): Returns soughtKey's index in cson or -1 if DNE.
static int csonIndex(char *soughtKey) {
  assert(CSON != NULL && CSON -> keys != NULL);
  stripCsonNulls();
  for(int i = 0; i < CSON -> length; i++) { // Unique keys in cson.
    if(strcmp(CSON -> keys[i], soughtKey) == 0) return i;
  }
  return -1;
}

// O(n): Prints cson's current key-value pairs.
void csonPrint() {
  assert(CSON != NULL && CSON -> keys != NULL && CSON -> vals != NULL);
  stripCsonNulls();
  printf("\n{\n");
  for(int i = 0; i < CSON -> length; i++) {
    printf("\t\"%s\": \"%s\", \n", CSON -> keys[i], CSON -> vals[i]);
  }
  printf("}\n");
}

// O(1): Returns number of non-null cson key-value pairs.
int csonSize() {
  assert(CSON != NULL);
  stripCsonNulls();
  return CSON -> length;
}

// O(n): Returns whether or not soughtKey exists in cson.
int csonHas(char *soughtKey) {
  return (csonIndex(soughtKey) != -1);
} 

/******************************************************************************
* 'CSON' KEY-VAL ARRAY CLONING FUNCTIONS (GARBAGE COLLECTION VIA 'KVC')
******************************************************************************/

// O(n): Return cpy of cson's keys. Garbage collection triggered on program exit.
char **csonKeys() {
  stripCsonNulls();
  assert(KVC.keyLength <= KVC.keyMaxElts); // Caps at 100 copies.
  unsigned long keySize = sizeof(char *) * (sizeof(CSON -> keys));
  char **keysClone = malloc(keySize);
  memcpy(keysClone, CSON -> keys, keySize); // O(n)
  KVC.keysCpy[KVC.keyLength++].matrix = keysClone; // Enables garbage collection.
  return keysClone;
}

// O(n): Return cpy of cson's values. Garbage collection triggered on program exit.
char **csonVals() {
  stripCsonNulls();
  assert(KVC.valLength <= KVC.valMaxElts); // Caps at 100 copies.
  unsigned long valSize = sizeof(char *) * (sizeof(CSON -> vals));
  char **valsClone = malloc(valSize);
  memcpy(valsClone, CSON -> vals, valSize); // O(n)
  KVC.valsCpy[KVC.valLength++].matrix = valsClone; // Enables garbage collection.
  return valsClone;
}

/******************************************************************************
* KEY-ASSOCIATED CSON VALUE ADDRESS RETREIVAL FUNCTION
******************************************************************************/

// O(n): Returns global CSON's value address relative to its key position.
// Can be used to both add and retrieve values from the structure.
char **csonValueAddress(char *soughtKey) {
  if(CSON == NULL) mkCSON();
  if(CSON -> length == CSON -> maxElts) {
    CSON -> maxElts *= 2;
    CSON -> keys = realloc(CSON -> keys, (sizeof(char *) * (CSON -> maxElts)));
    CSON -> vals = realloc(CSON -> vals, (sizeof(char *) * (CSON -> maxElts)));
  }
  int index = csonIndex(soughtKey);
  if(index != -1) {
    return &(CSON) -> vals[index];
  } else {
    CSON -> keys[CSON -> length++] = soughtKey;
    return &(CSON) -> vals[CSON -> length - 1];
  }
}

#endif
