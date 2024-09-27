/*------------------------------------------------------------------------------
Name: Circular_Shift.cpp
Description:
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

#include "Circular_Shift.h"

using namespace std;


void Circular_Shift::Set_Char(int shift, int word, int chrc, char p) {
  Circular_Shift::shiftedLines[shift][word].push_back(p);
}

char Circular_Shift::Get_Char(int shift, int word, int chrc) {
  return 'P';
}

int Circular_Shift::Get_Word(int shift) {
  return Circular_Shift::numWords[shift];
}

void Circular_Shift::Setup (Line_Storage &readLine) {
  int numWord;
  vector<int> wordLengths;
  char p;

  for (int i = 0; i < readLine.storedLines.size(); i++) {
    string newLine = "";
    numWord = readLine.Get_Word(i);
    Circular_Shift::numWords.push_back(numWord);
    Circular_Shift::shiftedLines.push_back(vector<string>());

    stringstream splitLine(readLine.storedLines[i]);
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
        p = readLine.Get_Char(i, j, wl);
        newLine += p;

        wl++;
      }

      if(j != numWord - 1) {
        newLine += " ";
      }
    }

    for (int j = 0; j < numWord; j++) {
      Circular_Shift::shiftedLines[i].push_back("");
      if (j == 0) {
        for(int k = 0; k < newLine.length(); k++) {
          Circular_Shift::Set_Char(i, j, k, newLine[k]);
        }

        Circular_Shift::shiftedLines[i].push_back("");

        newLine += " ";

        int counter = 1;

        while(counter <= wordLengths[j]) {
          p = newLine[0];
          newLine += p;

          newLine.erase(newLine.begin());

          if(counter == wordLengths[j]) {
            newLine.erase(newLine.begin());
          }

          counter++;
        }

        for(int k = 0; k < newLine.length(); k++) {
          Circular_Shift::Set_Char(i, j + 1, k, newLine[k]);
        }
      }

      else {
        newLine += " ";

        int counter = 1;

        while(counter <= wordLengths[j]) {
          p = newLine[0];
          newLine += p;

          newLine.erase(newLine.begin());

          if(counter == wordLengths[j]) {
            newLine.erase(newLine.begin());
          }

          counter++;
        }

        if (j != numWord) {
          for (int k = 0; k < newLine.length(); k++) {
            Circular_Shift::Set_Char(i, j + 1, k, newLine[k]);
          }
        }
      }
    }
  }
}
