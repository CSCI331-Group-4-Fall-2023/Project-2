#include <iostream>
#include <map>
#include "ZipcodeBuffer.h"
#include "StateRow.h"
#include <sstream> // for string stream
#include <string> // for getline
#include <fstream> // for file reading

// Authors: Tristan Adams, Andrew Clayton, Preston Betz, and Zachary Sunder
using namespace std;

/**
 * @brief Project 2 Part 2: Main function to populate and display a table of StateRow objects using a map.
 * 
 * The main function reads from a CSV file, populates a map with StateRow objects
 * indexed by state ID, and displays the final table of states with their easternmost, 
 * westernmost, northernmost, and southernmost zip codes.
 * 
 * @return 0 on successful execution, -1 on error.
 */
int main() {
    // Makes a hashmap to hold state IDs
    map<string, StateRow> stateMap;

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

        // Always apply comparisons, whether the state is encountered for the first time or not
        if (currentRow.getEast() > zipHolder.getLongitude() || currentRow.getFresh()) {
            currentRow.setID(stateId);
            currentRow.setEast(zipHolder.getLongitude());
            currentRow.setEastZ(zipHolder.getZipcode());
        }
        if (currentRow.getWest() < zipHolder.getLongitude() || currentRow.getFresh()) {
            currentRow.setWest(zipHolder.getLongitude());
            currentRow.setWestZ(zipHolder.getZipcode());
        }
        if (currentRow.getNorth() < zipHolder.getLatitude() || currentRow.getFresh()) {
            currentRow.setNorth(zipHolder.getLatitude());
            currentRow.setNorthZ(zipHolder.getZipcode());
        }
        if (currentRow.getSouth() > zipHolder.getLatitude() || currentRow.getFresh()) {
            currentRow.setSouth(zipHolder.getLatitude());
            currentRow.setSouthZ(zipHolder.getZipcode());
        }

        // Update the fresh flag after processing the entry
        currentRow.setFresh(false);
    }

    // Display the final table
    cout << "StateID, East Zip, West Zip, North Zip, South Zip" << endl;
    for (const auto& pair : stateMap) {
        if(!pair.second.getFresh()) {
            cout << pair.second << endl;
        }
    }

    return 0;
}
