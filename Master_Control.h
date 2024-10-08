/*------------------------------------------------------------------------------
Name: Master_Control.h
Description: Declaration of the class Master_Control
Course: SE6362
------------------------------------------------------------------------------*/
#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "Input.h"
#include "Line_Storage.h"
#include "Circular_Shift.h"
#include "Alphabetizer.h"
#include "Output.h"

using namespace std;

class Master_Control
{
public:
  string outputFileName;
  string inputFileName;

  // Create objects of all the classes that Master_Control need to invoke
  Input inputFile;
  Line_Storage readLine;
  Circular_Shift shiftedLine;
  Alphabetizer alphabetizedLine;
  Output outputFile;

  void Call_Input(ofstream &oFile); // Calls Read_File in Input

  void Call_Circular_Shift(ofstream &oFile); // Calls Setup in Circular_Shift

  void Call_Alphabetizer(ofstream &oFile); // Calls Alpha in Alphabetizer

  void Call_Output(ofstream &oFile); // Calls Display_Lines in Output
};
