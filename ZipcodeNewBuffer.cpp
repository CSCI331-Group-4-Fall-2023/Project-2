// Code from Zachary

#include "ZipcodeNewBuffer.h" 
#include <sstream> //For stringstream
#include <string> //For getline
#include <fstream> //for file processing
#include <cstdio> //for updating the csv file
#include <cstring> //convert string to char array


//Default constructor
ZipcodeNewBuffer::ZipcodeNewBuffer() 
{

}


// Currently sets headerMap (used for setting the header line in the setHeaderMap function) to headerLine
void ZipcodeNewBuffer::getHeaderMap(const string& headerLine) {
    stringstream ss(headerLine);
    string field;
    int pos = 0;

    while(getline(ss, field, ',')) {
        // If the CSV contains quoted fields, remove the quotes.
        if (field.front() == '"' && field.back() == '"') {
            field = field.substr(1, field.size() - 2);
        }

        headerMap[pos] = field;
        pos++;
    }
}


// Function to overwrite the header line of the csv file
bool ZipcodeNewBuffer::setHeaderMap(string fileName) 
{
    ifstream inFile(fileName);
    string line;

    if (!inFile) 
    {
        cout << "Bad file or file name" << endl;
        return false;
    }

    
    string newFile = "new" + fileName;
    ofstream file(newFile);


    // Get the header line string
    int count = headerMap.size();
    int iter = 0;
    string newHeader;

    if(count == 0)
    {
        cout << "No set header line" << endl;
        return false;
    }

    else
    {
        while(iter < count)
        {
            newHeader = newHeader + headerMap[iter];
            iter++;
        }
    }


    bool first = true;
    // Set the new header of the csv to newHeader and the rest stays the same
    while (getline(inFile, line)) 
    {
        if(first) 
        {
            file << newHeader << "\n";
            first = false;
            continue;
        }
        file << line << "\n";
    }


    // Below not working correctly, supposed to replace the fileName csv file
    // with the newHeader csv file and delete the old newHeader csv file
    char filename[fileName.size() + 1];
    strcpy(filename, fileName.c_str());
    remove(filename);

    char newheader[newHeader.size() + 1];
    strcpy(newheader, newHeader.c_str());
    rename(newheader, filename);
    remove(newheader);


    // try to find a method to overwrite the fileName csv file with the newFile csv file
    // or find a method to simply overwrite the header row (couldn't find one myself)
}


// Function to show the currently stored header line
void ZipcodeNewBuffer::printHeaderMap()
{
    int count = headerMap.size();
    int iter = 0;

    if(count == 0)
    {
        cout << "No set header line" << endl;
    }

    else
    {
        while(iter < count)
        {
            cout << headerMap[iter] << " ";
            iter++;
        }
    }
    
}