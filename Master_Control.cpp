/*------------------------------------------------------------------------------
Name: Master_Control.cpp
Description:
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
}

void Master_Control::Call_Circular_Shift() {
  shiftedLine.Setup(readLine);
}

void Master_Control::Call_Alphabetizer() {
  alphabetizedLine.Alpha(shiftedLine);
}

void Master_Control::Call_Output() {

}
