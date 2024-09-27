/*------------------------------------------------------------------------------
Name: Input.h
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

class Input {
  public:
    string fileName;

    void Read_File(Line_Storage &readLine);

    void Call_Line_Storage_Set_Char(Line_Storage &readLine);
};
