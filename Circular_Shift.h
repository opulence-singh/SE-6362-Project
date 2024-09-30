/*------------------------------------------------------------------------------
Name: Circular_Shift.h
Description:
Course: SE6362
------------------------------------------------------------------------------*/
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <sstream>

#include "Line_Storage.h"

using namespace std;

class Circular_Shift {
  private:
    void Set_Char(int shift, int word, int chrc, char p);

  public:
    vector<vector<string> > shiftedLines;
    vector<int> numWords;

    char Get_Char(int line, int shift, int word, int chrc);

    int Get_Word(int shift);

    void Setup (Line_Storage &readLine);
};
