#include <iostream>
#include <map>
#include "ZipcodeBuffer.h"
#include "StateRow.h"
#include <sstream> // for string stream
#include <string> // for getline
#include <fstream> // for file reading
#include <unordered_map>
#include <vector>

/**
 * \file ZipApp2.cpp
 * \author Andrew Clayton
 * \brief This is the file for Project 2 Part 2, giving zipcode information given a zipcode in the command line arguments.
 */

using namespace std;

int main(int argc, char* argv[]) {
    // Buffer to extract CSV data
    ZipcodeBuffer zipHolder; 

    // Read the entire file into memory
    ifstream inFile("Length_R.txt");
    if (!inFile) {
        cerr << "Error opening file" << endl;
        return EXIT_FAILURE;
    }

    stringstream buffer;
    buffer << inFile.rdbuf();
    string fileContents = buffer.str();

    // Split the file contents into lines
    vector<string> lines;
    size_t pos = 0;
    while ((pos = fileContents.find('\n')) != string::npos) {
        lines.push_back(fileContents.substr(0, pos));
        fileContents.erase(0, pos + 1);
    }
    if (!fileContents.empty()) {
        lines.push_back(fileContents);  // Add the last line if not empty
    }

    // Process the header line
    zipHolder.setHeaderMap(lines[0]);

    // Makes a hashmap to hold zipcodes and the RRN (relative record number) that go with them
    unordered_map<int, long> indexMap;

    // Index Creation
    for (size_t i = 1; i < lines.size(); ++i) {
        zipHolder.setFromFile(lines[i]);
        indexMap[zipHolder.getZipcode()] = i;
    }

    // Creating new file for Index file (assuming there is not already one)
    ofstream indexFile("indexFile.txt");
    for (const auto& pair : indexMap) {
        indexFile << pair.first << " " << pair.second << endl;
    }

    // Display whatever zipcodes are indicated in the command line arguments
    if (argc <= 1) {
        cout << "No zipcodes given\n";
    } else {
        vector<int> zipCodeIntegers;
        for (int i = 1; i < argc; ++i) {
            try {
                int intValue = atoi(argv[i]);
                zipCodeIntegers.push_back(intValue);
            } catch (const invalid_argument& e) {
                cerr << "Invalid argument: " << e.what() << endl;
            }
        }

        // Data Lookup
        for (int i = 0; i < zipCodeIntegers.size(); ++i) {
            auto it = indexMap.find(zipCodeIntegers[i]);
            if (it != indexMap.end()) {
                cout << lines[it->second] << endl;
            } else {
                cout << "Zipcode not found: " << zipCodeIntegers[i] << endl;
            }
        }
    }

    return 0;
}
