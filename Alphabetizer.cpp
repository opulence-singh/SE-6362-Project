/*------------------------------------------------------------------------------
Name: Alphabetizer.cpp
Description:
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

#include "Alphabetizer.h"

using namespace std;

void Alphabetizer::Set_Char(int alpha, int word, int chrc, char p) {

}

char Alphabetizer::Get_Char(int alpha, int word, string chrc) {

}

string Alphabetizer::Get_Word(int alpha) {

}

void Alphabetizer::Alpha(Circular_Shift &shiftedLine) {
  int numWord;

  for (int i = 0; i < shiftedLine.shiftedLines.size(); i++) {
    numWord = shiftedLine.Get_Word(i);

    for (int j = 0; j < shiftedLine.shiftedLines[i].size(); j++) {

      stringstream splitLine(shiftedLine.shiftedLines[i][j]);
      string word;
      string newLine;
      char p;
      vector<int> wordLengths;
      int wl;

      while (splitLine >> word) {
        wordLengths.push_back(word.length());
      }

      for (int k = 0; k < numWord; k++){
        while(wl <= wordLengths[j]) {
          p = shiftedLine.Get_Char(j, k, wl);
          newLine += p;

          wl++;
        }
      }
    }
  }
}
