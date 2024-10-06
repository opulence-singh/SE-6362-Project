#include <httplib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Master_Control.h"

using namespace std;

void updateKWICIndex()
{
    Master_Control kwic;
    kwic.inputFileName = "../input_test.txt"; // File containing the input data
    kwic.outputFileName = "../output.txt";    // File to store the output data

    ofstream oFile(kwic.outputFileName);
    if (!oFile)
    {
        cerr << "Error opening " << kwic.outputFileName << " for writing." << endl;
        return;
    }

    kwic.Call_Input(oFile);          // Read input data
    kwic.Call_Circular_Shift(oFile); // Apply circular shift
    kwic.Call_Alphabetizer(oFile);   // Alphabetize the data
    kwic.Call_Output(oFile);         // Output the results
    oFile.close();                   // Close the output file to flush all data
}

int main() {
  // Create an HTTP server
  httplib::Server server;

  server.set_base_dir("../public");

  // Handle POST requests from the form
  server.Post("/process_form", [](const httplib::Request &req, httplib::Response &res) {
    string search = req.get_param_value("search");

    cout << "Received Text: " << search << endl;

    // Save the form data to a file (appending)
    ofstream ofs("../input_test.txt", ios::app);  // Changed to input_test.txt for consistency
    if (!ofs) {
      cerr << "Error opening input_test.txt for writing." << endl;
      res.status = 500;
      res.set_content("Internal Server Error", "text/plain");
      return;
    }

    ofs << "$" << search; // Ensure there's a newline after each input
    ofs.close(); // Close the input file to flush data

  // Redirect back to the form with a success query parameter
  res.set_redirect("/home", 303); });

  // Serve the index.html file and inject form data into the page
  server.Get("/home", [](const httplib::Request &req, httplib::Response &res) {
    // Call the function to update the KWIC index
    updateKWICIndex();

    // Load the output.txt file
    ifstream ifs("../output.txt");
    if (!ifs) {
      cerr << "Error opening output.txt for reading." << endl;
      res.status = 500;
      res.set_content("Internal Server Error", "text/plain");
      return;
    }

    stringstream ss;
    string line;
    vector<string> output_lines;

    // Read lines and prepare them for HTML list items
    while (getline(ifs, line)) {
      if (line.empty()) {
        output_lines.push_back("<br>");
      }

      output_lines.push_back(line);
    }

    // Create the HTML for the unordered list
    string output;
    for (const auto& item : output_lines) {
      output += "<li>" + item + "</li>\n";  // Wrap each entry in <li>
    }

    // Load the index.html file
    ifstream ifs_index("../public/index.html");
    if (!ifs_index) {
      cerr << "Error opening index.html for reading." << endl;
      res.status = 500;
      res.set_content("Internal Server Error", "text/plain");
      return;
    }

    stringstream ss_index;
    ss_index << ifs_index.rdbuf();
    string index_html = ss_index.str();

    // Inject the output into the index.html file
    size_t pos = index_html.find("<ul>");
    if (pos != string::npos) {
      index_html.insert(pos + 4, output);  // Insert after the <ul> tag
    }
    else {
      cerr << "<ul> tag not found in index.html!" << endl;
    }

  res.set_content(index_html, "text/html"); });

  // Start the server on localhost:8080
  cout << "Server is running on http://localhost:8080\n";
  server.listen("localhost", 8080);

  return 0;
}
