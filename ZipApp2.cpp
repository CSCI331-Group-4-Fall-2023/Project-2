#include <iostream>
#include <map>
#include "ZipcodeBuffer.h"
#include "StateRow.h"
#include <sstream> // for string stream
#include <string> // for getline
#include <fstream> // for file reading

// Authors: Tristan Adams and Andrew Clayton
using namespace std;

/**
 * @brief Main function to populate and display a table of StateRow objects using a map.
 * 
 * The main function reads from a CSV file, populates a map with StateRow objects
 * indexed by state ID, and displays the final table of states with their easternmost, 
 * westernmost, northernmost, and southernmost zip codes.
 * 
 * @return 0 on successful execution, -1 on error.
 */
int main() {
    // Makes a hashmap to hold zipcodes and the RRN (relative reference number) that go with them
    map<int, int> indexMap; 

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
    while (getline(inFile, line)) {
        // Skip header line
        if(first) {
            zipHolder.setHeaderMap(line);
            first = false;
            continue;
        }

        // Set values from the current CSV line
        zipHolder.setFromFile(line);
        string stateId = zipHolder.getState();

        // Initialize or get reference to the StateRow object for the current state
        StateRow& currentRow = stateMap[stateId];
        indexMap.put(zipHolder.getZipcode(), /* RRN*/ );



    }

    // Display whatever zipcodes are indicated in the command line arguments
    // also make sure that command line arguments are accommodated 

    return 0;
}
