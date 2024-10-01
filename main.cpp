/*------------------------------------------------------------------------------
Name: main.cpp
Description: Implemenation of a Key Word in Context system. It is compose of the
following classes
1) Master_Control
2) Input
3) Line_Storage
4) Circular_Shift
5) Alphabetizer
6) Output
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <string>

#include "Master_Control.h"

using namespace std;

int main(int argc, char *argv[]) {
  // Checks if it has receiving two inputs from the user
  if (argc == 2) {
    Master_Control kwic;
    kwic.inputFileName = argv[1]; // Second input is the name of the file

    kwic.Call_Input();
    kwic.Call_Circular_Shift();
    kwic.Call_Alphabetizer();
    kwic.Call_Output();
  }

  else {
    cout << "Please provide the input file name." << endl;
  }

  return 0;
}
