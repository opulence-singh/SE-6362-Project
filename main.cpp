/*------------------------------------------------------------------------------
Name: main.cpp
Description: Implemenation of a Key Word in Context system
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <string>

#include "Master_Control.h"

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 2) {
    Master_Control kwic;
    kwic.inputFileName = argv[1];

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
