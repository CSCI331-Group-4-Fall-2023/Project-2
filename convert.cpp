/**
 * @file convert.cpp
 * @brief Convert CSV data into length-indicated format.
 * @author Andrew Clayton
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

/**
 * @brief Converts a given string to a length-indicated format.
 *
 * If the length of the provided string is more than 99 characters, 
 * an error is output and the program exits. Otherwise, the string is 
 * prepended with its 2-digit length.
 *
 * @param line String to be converted.
 * @return Length-indicated formatted string.
 */
std::string convertToLengthIndicated(const std::string &line) {
    // Calculate the total length of the string excluding the length field
    int totalLength = line.size();

    if (totalLength > 99) {
        std::cerr << "Error: Record too long to fit in 2-digit length field." << std::endl;
        exit(1);
    }

    // Convert the length to a string with leading zeros (2-digit width)
    std::ostringstream lengthStream;
    lengthStream << std::setw(2) << std::setfill('0') << totalLength;

    // Return the length-indicated string
    return lengthStream.str() + line;
}

/**
 * @brief Main function to process the CSV data.
 *
 * Reads from "us_postal_codes_ROWS_RANDOMIZED.csv", converts each line to 
 * length-indicated format and writes the result to "LI_R.csv".
 *
 * @return Returns 0 on success, 1 on file open error.
 */
int main() {
    std::ifstream inFile("us_postal_codes_ROWS_RANDOMIZED.csv");
    std::ofstream outFile("LI_R.csv");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening files." << std::endl;
        return 1;
    }

    std::string line;
    // Skip header line
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        // Convert to length-indicated format
        std::string convertedLine = convertToLengthIndicated(line);

        // Write to the output file
        outFile << convertedLine << std::endl;
    }

    inFile.close();
    outFile.close();
    return 0;
}
