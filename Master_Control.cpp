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

void Master_Control::Call_Input(ofstream &oFile) {
  inputFile.fileName = Master_Control::inputFileName;

  inputFile.Read_File(readLine);

  inputFile.Call_Line_Storage_Set_Char(readLine);

  oFile << "Read Lines: " << endl;

  for(int i = 0; i < readLine.storedLines.size(); i++) {
    oFile << readLine.storedLines[i] << endl;
  }
  oFile << "" << endl;
}

void Master_Control::Call_Circular_Shift(ofstream &oFile) {
  shiftedLine.Setup(readLine);

  oFile << "Shifted Lines: " << endl;
  for(int i = 0; i < shiftedLine.shiftedLines.size(); i++) {
    for(int j = 0; j < shiftedLine.shiftedLines[i].size(); j++) {
      oFile << shiftedLine.shiftedLines[i][j] << endl;
    }
    oFile << "" << endl;
  }
}

void Master_Control::Call_Alphabetizer(ofstream &oFile) {
  alphabetizedLine.Alpha(shiftedLine, oFile);
}

void Master_Control::Call_Output(ofstream &oFile) {
  outputFile.Display_Lines(alphabetizedLine, oFile);
}
