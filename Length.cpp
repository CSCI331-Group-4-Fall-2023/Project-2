#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    std::ifstream inFile("us_postal_codes.csv"); // Change this to your input CSV file path
    std::ofstream outFile("Length.txt"); // Output file

    if (!inFile.is_open()) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::string line;
    // Skip the header
    std::getline(inFile, line);

    while (std::getline(inFile, line)) {
        // Write the length of the record followed by a comma and then the record itself
        outFile << line.length()+1 << "," << line << std::endl;
    }

    inFile.close();
    outFile.close();

    std::cout << "Conversion done!" << std::endl;
    return 0;
}
