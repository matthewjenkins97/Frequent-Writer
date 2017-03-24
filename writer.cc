/******************************************************************************
 *
 * Name: Matt Jenkins
 *
 * Date: 2 March 2017
 *
 * Assignment: Project 3
 *
 * Purpose: Write a program which when given a body of work emulates its 
 * style of composition.
 *
 *****************************************************************************/

#include <iostream>
//#include "cs111.h"
#include "list.h"
using namespace std;

/*
To generate text, assume a string of characters of prefixLength has been 
defined. 

Find all occurrences of the string in the corpus. 

Build a list of characters that follow the string in the corpus 
(yes, this requires that you find what character follows each occurrence of 
the string in the corpus). 

Once the list has been built, pick one character from the list at random and 
output it. 

Then, add the character to the end of the string and remove the first character
yielding another string of prefixLength. 

Repeat.
*/
int* occurrences(int prefixLength, int textLength, string corpus) {
  return 0;
}

int main(int argc, char** argv) {
  if (argc != 4) {
    cout << "USAGE: writer -count -textLength -corpus" << endl;
    return 1;
  }
  int prefixLength;
  int textLength;
  string corpus;
  //loadCorpus(argc, argv, prefixLength, textLength, corpus);
  occurrences(prefixLength, textLength, corpus);
}
