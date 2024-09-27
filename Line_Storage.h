/*------------------------------------------------------------------------------
Name: Line_Storage.h
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

using namespace std;

class Line_Storage {
  public:
    string fullLine;
    vector<string> storedLines;
    vector<int> numWords;

    void Set_Char(int line, int word, int chrc, char p);

    char Get_Char(int line, int word, int chrc);

    int Get_Word(int line);
};
