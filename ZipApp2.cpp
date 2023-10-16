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
    unordered_map<int, int> indexMap; 

    // Buffer to extract CSV data
    ZipcodeBuffer zipHolder; 

    // ifstream inFile("us_postal_codes_ROWS_RANDOMIZED.csv");
    ifstream inFile("us_postal_codes.csv");
    if (!inFile) {
        cout << "Error opening file" << endl;
        return -1;
    }

    bool first = true;
    string line;

    // Creating new file for Index file (assuming there is not already one)
    ofstream indexFile("indexFile.txt");

    int rrn = 0; 
    while (getline(inFile, line)) {
        // Skip header line
        if(first) {
            zipHolder.setHeaderMap(line);
            first = false;
            continue;
        }

        // Set values from the current CSV line
        zipHolder.setFromFile(line);

        indexMap[zipHolder.getZipcode()] = rrn;

        // Write the key and value to an index file
        indexFile << zipHolder.getZipcode() << " " << rrn << endl;

        //updating the rrn will be the last step of the loop
        rrn += zipHolder.getLength() + rrn;
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
          int rnn = indexMap[zipCodeIntegers[i]];
           inFile.clear();
           inFile.seekg(rnn, ios::beg);
           string line_temp;
           getline(inFile, line_temp);
                ZipcodeBuffer temp;
                temp.setFromFile(line_temp);
                cout << temp;
           }
           


    }

    return 0;
}
