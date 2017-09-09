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
#include "List.h"
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
  if (argc != 4) {
    cout << "USAGE: prefixLength textLength corpus" << endl;
    return 1;
  }
  int prefixLength;
  int textLength;
  string corpus;
  string line;

  prefixLength = atoi(argv[1]);
  textLength = atoi(argv[2]);

  ifstream myfile;
  myfile.open(argv[3]);
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      corpus = corpus + line;
    }
  }
  myfile.close();

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
    int randNum = rand() % prefixChars.length();
    for (unsigned int i = 0; i < randNum; i++) {
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
  cout << endl;
}
