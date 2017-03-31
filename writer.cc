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
#include "cs111.h"
#include "List.h"
#include <string>
using namespace std;

int main(int argc, char** argv) {
  int prefixLength;
  int textLength;
  string corpus;
  loadCorpus(argc, argv, prefixLength, textLength, corpus);

  //generating prefix
  string prefix = "";
  for (int i = 0; i < prefixLength; i++) {
    prefix = prefix + corpus[i];
  }
  
  //prints out the first prefixLength characters in the corpus
  cout << prefix;

  //this runs until outputText is the same length as textLength
  string outputText = prefix; 

  while (outputText.length() < (size_t)textLength) {

    //find all occurences of the prefix in corpus
    List prefixChars;
    int location = corpus.find(prefix);

    while (location != -1) {

      //build a list of all characters that follows the prefix
      prefixChars.insertAfter(corpus[location + prefixLength]);

      //find all occurences of the prefix in corpus
      location = corpus.find(prefix, location + prefixLength);  

    }

    //if prefixChars is empty, get out of the loop
    if (prefixChars.empty()) {
      break;
    }

    //take a random character from the list and output it
    prefixChars.head();
    for (unsigned int i = 0; i < cs111::random(prefixChars.length()); i++) {
      prefixChars.advance();
    }
    char finalChar = prefixChars.retrieve();
    outputText = outputText + finalChar;
    cout << finalChar;

    /* chop off the first character of the prefix, add the character you just 
    outputted to it */
    prefix = prefix.substr(1);
    prefix = prefix + finalChar;
  }
}
