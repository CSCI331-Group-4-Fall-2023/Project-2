#include <iostream>
#include <map>
#include "ZipcodeBuffer.h"
#include "StateRow.h"
#include <sstream> // for string stream
#include <string> // for getline
#include <fstream> // for file reading
#include <unordered_map>
#include <vector>

// Authors: Tristan Adams and Andrew Clayton
using namespace std;

/**
 * @brief Main function to populate and display a table of StateRow objects using a map.
 * 
 * -----------------------------------------------------------------------------------------------------
 * 
 * @return 0 on successful execution, -1 on error.
 */
int main(int argc, char* argv[]) {
    // Makes a hashmap to hold zipcodes and the RRN (relative reference number) that go with them
    unordered_map<int, long> indexMap; 
    unordered_map<int, ZipcodeBuffer> zipMap;

    // Buffer to extract CSV data
    ZipcodeBuffer zipHolder; 

    // ifstream inFile("us_postal_codes_ROWS_RANDOMIZED.csv");
    ifstream inFile("Length_R.csv");
    if (!inFile) {
        cout << "Error opening file" << endl;
        return -1;
    }

    bool first = true;
    string line;

    // Creating new file for Index file (assuming there is not already one)
    // Open an output file stream to write the index
    ofstream indexFile("indexFile.txt");
    if (!indexFile) {
        cout << "Error: Unable to open index file for writing." << endl;
        return -1;  // This might need adjustment based on your main() function structure
    }

    long rrn = inFile.tellg();  // Start by getting the current position of the file

    while (getline(inFile, line)) {
        // If it's the first line, consider it as a header and skip
        if (first) {
            zipHolder.setHeaderMap(line);
            first = false;
            continue;
        }

        // Populate the ZipcodeBuffer from the line
        zipHolder.setFromFile(line);
        zipMap[zipHolder.getZipcode()] = zipHolder;

        // Store the current rrn into the hashmap
        indexMap[zipHolder.getZipcode()] = rrn;

        // Write the zipcode and its rrn to the index file
        indexFile << zipHolder.getZipcode() << " " << rrn << endl;

        // Update rrn to point to the start of the next line/record
        rrn = inFile.tellg();
    }

    // Display whatever zipcodes are indicated in the command line arguments
    // also make sure that command line arguments are accommodated 
    if (argc <= 1) {
        cout << "No zipcodes given\n";
    } else {
       vector<int> zipCodeIntegers;
        int count = 0;
        for (int i = 1; i < argc; ++i) {
            try {
                // Convert each command line argument (C-string) to an integer using atoi
             int intValue = atoi(argv[i]);

             // Add the integer to the vector
                zipCodeIntegers.push_back(intValue);
                count++;
            } catch (const invalid_argument& e) {
                cerr << "Invalid argument: " << e.what() << endl;
            }
        }
        //once the vector is made we can search through the whole vector and display the record that the zipcode grabs from the index
        for (int i = 0; i < count; ++i) {
            // long rnn = indexMap[zipCodeIntegers[i]];

            // inFile.clear();
            // inFile.seekg(0, ios::beg); //resetting the pointer to the start of the file


            // inFile.seekg(rnn, ios::beg);
            // string line_temp;
            // getline(inFile, line_temp);
            // // ZipcodeBuffer temp;
            // // temp.setFromFile(line_temp);
            // // cout << temp;
            // cout << line_temp << "\n";

            // cout << "Zip: " << zipCodeIntegers[i] << ", RRN: " << rnn << endl;
            cout << zipMap[zipCodeIntegers[i]] << endl;
            if 
           }
    }

    return 0;
}
