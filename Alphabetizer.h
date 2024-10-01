/*------------------------------------------------------------------------------
Name: Alphabetizer.h
Description: Declaration of the class Alphabetizer
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
    void Set_Char(int alpha, int word, int chrc, char p); // Stores in a vector each alphabetized line read character by character

  public:
    vector<string> alphabetizedLines;
    vector<int> numWords;

    char Get_Char(int alpha, int word, int chrc); // Returns a character from a specific alphabetized line and word

    int Get_Word(int alpha); // Returns the number of words a specific alphabetized line has

    void Alpha(Circular_Shift &shiftedLine); // Calls the function Get_Char & Get_Word from the Circular Shifte class to get the shifted lines and alphabetized them
};
