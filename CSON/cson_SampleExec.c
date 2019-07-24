// Author: Jordan Randleman - CSON SAMPLE USE DEMONSTRATION.

#include "cson.h"

/******************************************************************************
* CSON SAMPLE DEMO EXECUTION FUNCTION
******************************************************************************/

int main() {

  csonHelp();

  // Add key-value pair. First call inits creation/deletion garbage collection.
  cson("author") = "Jordan";  
  char* elt = cson("author"); // Get value at key.
  printf("%s\n", elt);

  cson("delete Me") = "temp";
  cson("delete Me") = NULL; // Delete key-value pair.

  cson("bestAirPurifier") = "Wynd";
  elt = cson("bestAirPurifier");
  printf("%s\n", elt);

  cson("bro") = "Will";
  elt = cson("bro");
  printf("%s\n", elt);

  char** keyCloneMatrix = csonKeys();
  char** valCloneMatrix = csonVals();

  for(int i = 0, size = csonSize(); i < size; i++) {
    printf("\n%s: %s", keyCloneMatrix[i], valCloneMatrix[i]);
  }

  if(csonHas("author")) printf("\nauthor exists!");
  if(csonHas("fakeKey")) printf("\nfakeKey exists!");

  csonPrint();
}
