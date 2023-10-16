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
       std::vector<int> zipCodeIntegers;

        for (const char* zip : argv) {
        try {
            // Convert each character array to an integer using std::stoi
            int intValue = std::stoi(zip);

            // Add the integer to the vector
            zipCodeIntegers.push_back(intValue);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid argument: " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Out of range: " << e.what() << std::endl;
        }
    }

    }

    return 0;
}
