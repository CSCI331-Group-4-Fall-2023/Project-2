#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

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
