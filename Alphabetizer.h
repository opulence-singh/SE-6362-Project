/*------------------------------------------------------------------------------
Name: Alphabetizer.h
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

#include "Circular_Shift.h"

using namespace std;

class Alphabetizer {
  private:
    void Set_Char(int alpha, int word, int chrc, char p);

  public:
    vector<vector<string> > alphabetizedLines;

    char Get_Char(int alpha, int word, string chrc);

    string Get_Word(int alpha);

    void Alpha(Circular_Shift &shiftedLine);
};
