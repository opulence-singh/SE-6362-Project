/*------------------------------------------------------------------------------
Name: Input.cpp
Description:
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

#include "Input.h"

using namespace std;

void Input::Read_File(Line_Storage &readLine) {
  // Opens input file
  ifstream file(fileName);

  // Checks if file has been opened
  if (!file.is_open()) {
    cout << "Error opening the file!" << endl;
    exit(1);
  }

  //Read each line of the file and store it in the vector
  string line;

  getline(file, line);
  readLine.fullLine = line;

  // Close the file
  file.close();
}

void Input::Call_Line_Storage_Set_Char(Line_Storage &readLine) {
  int word = 1;
  int counter = 0;
  readLine.storedLines.push_back("");

  for (int i = 0; i < readLine.fullLine.length(); i++) {
    if (readLine.fullLine[i] == '$') {
      counter++;

      readLine.storedLines.push_back("");

      readLine.numWords.push_back(word);

      word = 1;
    }

    else {
      readLine.Set_Char(counter, word, i, readLine.fullLine[i]);

      if (readLine.fullLine[i] == ' ') {
        word++;
      }
    }
  }
}
