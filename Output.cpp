/*------------------------------------------------------------------------------
Name: Output.cpp
Description: Definition of the Output class
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

#include "Output.h"

using namespace std;

void Output::Display_Lines(Alphabetizer alphabetizedLine, ofstream &oFile) {
  int numWord;
  char p;

  oFile << "Alphabetizes Lines:" << endl;

  for (int i = 0; i < alphabetizedLine.alphabetizedLines.size(); i++){
    vector<int> wordLengths;
    string newLine = "";
    numWord = alphabetizedLine.Get_Word(i);

    stringstream splitLine(alphabetizedLine.alphabetizedLines[i]);
    string token = " ";
    vector<string> words;

    while (splitLine >> token) {
      words.push_back(token.c_str());
    }

    for (int j = 0; j < words.size(); j++) {
      wordLengths.push_back(words[j].length());
    }

    for (int j = 0; j < numWord; j++) {
      int wl = 1;

      while(wl <= wordLengths[j]) {
        p = alphabetizedLine.Get_Char(i, j, wl);
        newLine += p;

        wl++;
      }

      if(j != numWord - 1) {
        newLine += " ";
      }
    }

    oFile << newLine << endl;
  }
}
