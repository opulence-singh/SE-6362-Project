/*------------------------------------------------------------------------------
Name: KWIC_IMPLEMENTATION.cpp
Description: Implemenation of a Key Word in Context system
Course: SE6362
------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Line_Storage {
  public:
    string fullLine;
    vector<string> storedLines;
    vector<int> numWords;

    void Set_Char(int line, int word, int chrc, char p) {
      Line_Storage::storedLines[line] += p;
    }

    char Get_Char(int line, int word, int chrc) {
      char p;
      int spaces = 1;
      int counter = 0;

      while(spaces < word) {
        p = Line_Storage::storedLines[line - 1][counter];

        if(p == ' ') {
          spaces++;
        }

        counter++;
      }

      while(chrc != 0) {
        p = Line_Storage::storedLines[line - 1][counter];

        chrc--;
        counter++;
      }

      return p;
    }

    int Get_Word(int line) {
      return Line_Storage::numWords[line - 1];
    }
};

class Input {
  public:
    string fileName;

    void Read_File(Line_Storage readLine) {
      // Opens input file
      ifstream file(fileName);

      // Checks if file has been opened
      if (!file.is_open()) {
        cout << "Error opening the file!" << endl;
        exit(1);
      }

      //Read each line of the file and store it in the vector
      string line;

      while (getline(file, line)) {
        readLine.fullLine = line;
      }

      // Close the file
      file.close();
    }

    void Call_Line_Storage_Set_Char(Line_Storage readLine) {
      int word = 1;
      int counter = 0;
      readLine.storedLines.push_back("");

      for (int i = 0; i < readLine.fullLine.length(); i++) {
        if (readLine.fullLine[i] == '$') {
          counter++;
          readLine.storedLines.push_back("");
          readLine.numWords.push_back(word);
          word = 1;
        }
        else {
          readLine.Set_Char(counter, word, i, readLine.fullLine[i]);

          if (i == ' ') {
            word++;
          }
        }
      }

    }
};

class Circular_Shift {
  private:
    void Set_Char(int shift, int word, int chrc, char p) {

    }

  public:
    vector<vector<string> > shiftedLines;

    string Get_Char(int shift, int word, string chrc) {

    }

    int Get_Word(int shift) {

    }

    string Setup (Line_Storage readLine) {

    }
};

class Alphabetizer {
  private:
    void Set_Char(int alpha, int word, int chrc, char p) {

    }

  public:
    vector<vector<string> > alphabetizedLines;

    string Get_Char(int alpha, int word, string chrc) {

    }

    string Get_Word(int alpha) {

    }

    void Merge_Sort() {

    }
};

class Output {
  public:
    void Display_Lines() {

    }
};

class Master_Control {
  private:
    const string outputFileName = "kwic_output.txt";

  public:
    string inputFileName;

    Input inputFile;
    Line_Storage readLine;
    Circular_Shift shiftedLine;
    Alphabetizer alphabetizedLine;
    Output outputFile;


    void Call_Input() {
      inputFile.fileName = Master_Control::inputFileName;

      inputFile.Read_File(readLine);

      inputFile.Call_Line_Storage_Set_Char(readLine);
    }

    void Call_Circular_Shift() {

    }

    void Call_Alphabetizer() {

    }

    void Call_Output() {

    }
};

int main(int argc, char *argv[]) {
  if (argc == 1) {
    Master_Control kwic;

    kwic.inputFileName = argv[0];

    kwic.Call_Input();

    kwic.Call_Circular_Shift();

    kwic.Call_Alphabetizer();

    kwic.Call_Output();
  }
  else
    cout << "More than one argument was input" << endl;

  return 0;
}
