/*------------------------------------------------------------------------------
Name: Master_Control.h
Description:
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

class Master_Control {
  private:
    const string outputFileName;

  public:
    string inputFileName;

    Input inputFile;
    Line_Storage readLine;
    Circular_Shift shiftedLine;
    Alphabetizer alphabetizedLine;
    Output outputFile;


    void Call_Input();

    void Call_Circular_Shift();

    void Call_Alphabetizer();

    void Call_Output();
};
