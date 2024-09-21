/*------------------------------------------------------------------------------
Name: KWIC_IMPLEMENTATION.cpp
Description: Implemenation of a Key Word in Context system
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include<list>

using namespace std;

class Master_Control {
  private:
    string inputFileName;
    string outputFileName = "kwic_output.txt";

  public:
    Input inputFile;
    Line_Storage readLine;
    Circular_Shift shiftedLine;
    Alphabetizer alphabetizedLine;
    Output outputFile;


    void Call_Input() {
      inputFile.fileName = Master_Control::inputFileName;

      inputFile.Read_File(readLine);
    }

    void Call_Line_Storage() {

    }

    void Call_Circular_Shift() {

    }

    void Call_Alphabetizer() {

    }

    void Call_Output() {

    }
};

class Input {
  public:
    string fileName;

    Read_File(readLine) {
      // Opens input file
      ifstream file(fileName);

      // Checks if file has been opened
      if (!file.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
      }

      //Read each line of the file and store it in the vector
      string line;

      while (getline(file, line)) {
        readLine = line;
      }

      // Close the file
      readLine.storedLines = file.close();
    }
};

class Line_Storage {
  public:
    string storedLines;

    Set_Char(line, word, char, p) {

    }

    Get_Char(line, word, p) {

    }

    Get_Word(line) {

    }
};

class Circular_Shift {
  public:
    Setup () {

    }

    Set_Char(shift, word, char, p) {

    }

    Get_Char(shift, word, char) {

    }

    Get_Word(shift) {

    }
};

class Alphabetizer {
  public:
    Set_Char(line, word, char, p) {

    }

    Get_Char(line, word, char) {

    }

    Get_Word(line, word, char) {

    }
};

class Output {
  public:
    Display_Lines(line) {

    }
};

int main(int argc, string argv) {
  if (argc == 1) {
    Master_Control kwic;

    kwic.inputFileName = argv;

    kwic.Call_Input();

    kwic.Call_Line_Storage();

    kwic.Call_Circular_Shift();

    kwic.Call_Alphabetizer();

    kwic.Call_Output();
  }
  else
    cout << "More than one argument was input" << endl;

  return 0;
}
