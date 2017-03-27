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
#include <string>
using namespace std;

size_t cs111::random(size_t max);

//two reasons for stopping:
  //text length has been met
  //prefix isn't found anywhere in the corpus.

int main(int argc, char** argv) {
  int prefixLength;
  int textLength;
  string corpus;
  loadCorpus(argc, argv, prefixLength, textLength, corpus);

  string prefix = "";
  //generating prefix
  for (int i = 0; i < prefixLength; i++) {
    prefix = prefix + corpus[i];
  }

  string outputText = ""; 

  while (outputText.length() < textLength) {
    //find all occurences of the prefix in corpus
    List prefixChars;
    int location = corpus.find(prefix);
    while (location != -1) {
      //build a list of all characters that follows the prefix
      prefixChars.insertAfter(corpus[location + prefixLength]);
      //find all occurences of the prefix in corpus
      location = corpus.find(prefix, location + prefixLength);  
    }
    if (prefixChars.empty()) {
      break;
    }
    //take a random character from the list and output it
    prefixChars.head();
    for (int i = 0; i < cs111::random(prefixChars.length()); i++) {
      prefixChars.advance();
    }
    char finalChar = prefixChars.retrieve();
    outputText = outputText + finalChar;
    cout << outputText;

    /* chop off the first character of the prefix, add the character you just 
    outputted to it */
    prefix = prefix.substr(1);
    prefix = prefix + finalChar;
  }
}