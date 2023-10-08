#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::string processLine(const std::string &line) {
    std::istringstream iss(line);
    std::string token;
    std::string result = "";
    
    // Count the number of characters in this line (not including commas)
    int len = 0;
    while (std::getline(iss, token, ',')) {
        len += token.size();
    }

    // Add the length to the result without a comma
    result += std::to_string(len);
    result += line;

    return result;
}

int main() {
    std::ifstream infile("us_postal_codes.csv");
    std::ofstream outfile("length_indicated.txt");

    if (!infile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    if (!outfile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(infile, line);  // Skip header

    while (std::getline(infile, line)) {
        outfile << processLine(line) << std::endl;
    }

    infile.close();
    outfile.close();

    std::cout << "Conversion complete!" << std::endl;
    return 0;
}
