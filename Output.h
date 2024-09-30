/*------------------------------------------------------------------------------
Name: Output.h
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

#include "Alphabetizer.h"

using namespace std;

class Output {
  public:
  void Display_Lines(Alphabetizer alphabetizedLine);
};
