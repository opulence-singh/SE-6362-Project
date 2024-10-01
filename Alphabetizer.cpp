/*------------------------------------------------------------------------------
Name: Alphabetizer.cpp
Description: Definition of the Alphabetizer class
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>
#include <cctype>

#include "Alphabetizer.h"

using namespace std;

void merge(vector<string> &shiftedLines, int left, int mid, int right) {
    int size1;
    int size2;

    size1 = mid - left + 1;
    size2 = right - mid;

    vector<string> leftShiftedLines(size1);
    vector<string> rightShiftedLines(size2);

    for (int i = 0; i < size1; i++) {
      leftShiftedLines[i] = shiftedLines[left + i];
    }

    for (int j = 0; j < size2; j++) {
      rightShiftedLines[j] = shiftedLines[mid + 1 + j];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int pointer = left;

    while (leftIndex < size1 && rightIndex < size2) {
      string temp1 = "";
      string temp2 = "";

      for(int i = 0; i < leftShiftedLines[leftIndex].length(); i++) {
        temp1 += toupper(leftShiftedLines[leftIndex][i]);
      }

      for(int i = 0; i < rightShiftedLines[rightIndex].length(); i++) {
        temp2 += toupper(rightShiftedLines[rightIndex][i]);
      }

      if (temp1 <= temp2) {
        shiftedLines[pointer] = leftShiftedLines[leftIndex];
        leftIndex++;
      }

      else {
        shiftedLines[pointer] = rightShiftedLines[rightIndex];
        rightIndex++;
      }

      pointer++;
    }

    while (leftIndex < size1) {
        shiftedLines[pointer] = leftShiftedLines[leftIndex];
        leftIndex++;
        pointer++;
    }

    while (rightIndex < size2) {
        shiftedLines[pointer] = rightShiftedLines[rightIndex];
        rightIndex++;
        pointer++;
    }
}

void mergeSort(vector<string> &shiftedLines, int left, int right) {
    if (left < right) {
        int mid;
        mid = left + (right - left) / 2;

        mergeSort(shiftedLines, left, mid);
        mergeSort(shiftedLines, mid + 1, right);

        merge(shiftedLines, left, mid, right);
    }
}

void Alphabetizer::Set_Char(int alpha, int word, int chrc, char p) {
  Alphabetizer::alphabetizedLines[alpha].push_back(p);
}

char Alphabetizer::Get_Char(int alpha, int word, int chrc) {
  char p;
  string token = " ";
  vector<string> words;
  stringstream splitLine(Alphabetizer::alphabetizedLines[alpha]);

  while (splitLine >> token) {
    words.push_back(token.c_str());
  }

  p = words[word][chrc - 1];

  return p;
}

int Alphabetizer::Get_Word(int alpha) {
  return Alphabetizer::numWords[alpha];
}

void Alphabetizer::Alpha(Circular_Shift &shiftedLine) {
  vector<vector<string> > temp1;
  int numWord;
  char p;

  cout << "Alphabetization By Line:" << endl;


  for(int i = 0; i < shiftedLine.shiftedLines.size(); i++) {
    temp1.push_back(vector<string>());
    numWord = shiftedLine.Get_Word(i);

    for (int j = 0; j < shiftedLine.shiftedLines[i].size(); j++) {
      temp1[i].push_back("");

      vector<int> wordLengths;
      string newLine = "";

      stringstream splitLine(shiftedLine.shiftedLines[i][j]);
      string token = " ";
      vector<string> words;

      while (splitLine >> token) {
        words.push_back(token.c_str());
      }

      for (int k = 0; k < words.size(); k++) {
        wordLengths.push_back(words[k].length());
      }

      for (int k = 0; k < numWord; k++) {
        int wl = 0;

        while(wl < wordLengths[k]) {
          p = shiftedLine.Get_Char(i, j, k, wl);
          temp1[i][j] += p;

          wl++;
        }

        if(k != numWord - 1) {
          temp1[i][j] += " ";
        }
      }
    }
  }

  int totalSize = 0;

  for (int i = 0; i < temp1.size(); i++) {
    int numShiftedLines = temp1[i].size();

    totalSize += numShiftedLines;

    mergeSort(temp1[i], 0, numShiftedLines - 1);

    for(int j = 0; j < temp1[i].size(); j++) {
      cout << temp1[i][j] << endl;
    }

    cout << " " << endl;
  }

  vector<string> temp2;

  for (int i = 0; i < temp1.size(); i++) {
    for (int j = 0; j < temp1[i].size(); j++) {
        if (i == 0) {
          temp2.push_back(temp1[i][j]);
        }

        else {
          temp2.push_back(temp1[i][j]);
        }
    }
  }

  mergeSort(temp2, 0, totalSize - 1);

  for(int i = 0; i < temp2.size(); i++) {
    stringstream splitLine(temp2[i]);
    string token = " ";
    vector<string> words;

    while (splitLine >> token) {
      words.push_back(token.c_str());
    }

    Alphabetizer::numWords.push_back(words.size());
  }

  for(int i = 0; i < temp2.size(); i++) {
    int word = 1;
    Alphabetizer::alphabetizedLines.push_back("");

    for(int j = 0; j < temp2[i].length(); j++) {
      Alphabetizer::Set_Char(i, word, j, temp2[i][j]);
      word++;
    }
  }
}
