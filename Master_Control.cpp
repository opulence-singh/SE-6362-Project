/*------------------------------------------------------------------------------
Name: Master_Control.cpp
Description: Definition of the Master_Control class
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

#include "Master_Control.h"

using namespace std;

void Master_Control::Call_Input() {
  inputFile.fileName = Master_Control::inputFileName;

  inputFile.Read_File(readLine);

  inputFile.Call_Line_Storage_Set_Char(readLine);

  cout << "Read Lines: " << endl;
  for(int i = 0; i < readLine.storedLines.size(); i++) {
    cout << readLine.storedLines[i] << endl;
  }
  cout << "" << endl;
}

void Master_Control::Call_Circular_Shift() {
  shiftedLine.Setup(readLine);

  cout << "Shifted Lines: " << endl;
  for(int i = 0; i < shiftedLine.shiftedLines.size(); i++) {
    for(int j = 0; j < shiftedLine.shiftedLines[i].size(); j++) {
      cout << shiftedLine.shiftedLines[i][j] << endl;
    }
    cout << "" << endl;
  }
}

void Master_Control::Call_Alphabetizer() {
  alphabetizedLine.Alpha(shiftedLine);
}

void Master_Control::Call_Output() {
  outputFile.Display_Lines(alphabetizedLine);
}
