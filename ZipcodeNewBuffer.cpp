/**
 * \file ZipcodeNewBuffer.cpp
 * \author Zachary Sunder
 * \version 1.1
 * \brief Implementation file for ZipcodeNewBuffer class.
 */

#include "ZipcodeNewBuffer.h" 
#include <sstream> //For stringstream
#include <string> //For getline
#include <fstream> //for file processing
#include <cstdio> //for updating the csv file
#include <cstring> //convert string to char array


//Default constructor
ZipcodeNewBuffer::ZipcodeNewBuffer() 
{
    filetype = "";
    ver = 1.1;
    len_ind = 0;
    recordByte = 2;
    formatType = "ASCII";
    primaryFileName = "";
    recordCount = 0;
    fieldCount = 0;
    primaryField = "";
    headerMap.clear();
}


//Constructor
ZipcodeNewBuffer::ZipcodeNewBuffer(string fileName, string mainField)
{
    int pos = fileName.find(".");
    filetype = fileName.substr(pos);
    ver = 1.1;
    recordByte = 2;
    formatType = "ASCII";
    primaryFileName = fileName;
    primaryField = mainField;

    ifstream inFile(fileName);
    string line;

    if (!inFile) 
    {
        cout << "Bad file or file name" << endl;
    }

    bool first = true;
    int count = 0;

    // Set the new header of the csv to newHeader and the rest stays the same
    while (getline(inFile, line)) 
    {
        if(first) 
        {
            getHeaderMap(line);
            first = false;
            continue;
        }
        count++;
    }
    recordCount = count;

    
    len_ind = stoi(headerMap[0]);
    fieldCount = headerMap.size()-1;
}


//Setters
void ZipcodeNewBuffer::setFileType(const string& FileType)
{
    filetype = FileType;
}

void ZipcodeNewBuffer::setVer(double Ver)
{
    ver = Ver;
}

void ZipcodeNewBuffer::setLenInd(int Len)
{
    len_ind = Len;
}

void ZipcodeNewBuffer::setRecordByte(int RecordByte)
{
    recordByte = RecordByte;
}

void ZipcodeNewBuffer::setFormatType(const string& FormatType)
{
    formatType = FormatType;
}

void ZipcodeNewBuffer::setPrimaryFileName(const string& FileName)
{
    primaryFileName = FileName;
    int pos = FileName.find(".");
    string FileType = FileName.substr(pos);
    setFileType(FileType);
}

void ZipcodeNewBuffer::setRecordCount(int RecordCount)
{
    recordCount = RecordCount;
}

void ZipcodeNewBuffer::setFieldCount(int FieldCount)
{
    fieldCount = FieldCount;
}

void ZipcodeNewBuffer::setPrimaryField(const string& PrimaryField)
{
    primaryField = PrimaryField;
}

string ZipcodeNewBuffer::getFileType()
{
    return filetype;
}

double ZipcodeNewBuffer::getVer()
{
    return ver;
}

int ZipcodeNewBuffer::getLenInd()
{
    return len_ind;
}

int ZipcodeNewBuffer::getRecordByte()
{
    return recordByte;
}

string ZipcodeNewBuffer::getFormatType()
{
    return formatType;
}

string ZipcodeNewBuffer::getPrimaryFileName()
{
    return primaryFileName;
}

int ZipcodeNewBuffer::getRecordCount()
{
    return recordCount;
}

int ZipcodeNewBuffer::getFieldCount()
{
    return fieldCount;
}

string ZipcodeNewBuffer::getPrimaryField()
{
    return primaryField;
}

string ZipcodeNewBuffer::getFieldx(int position)
{
    return headerMap[position];
}

string ZipcodeNewBuffer::getFieldType(int position)
{
    string Field = headerMap[position];
    if(!(isdigit(Field[0])))
    {
        return "String";
    }
    else if(Field.find("."))
    {
        return "Double";
    }
    else
    {
        return "Integer";
    }
}



// Currently sets headerMap (used for setting the header line in the setHeaderMap function) to headerLine
void ZipcodeNewBuffer::getHeaderMap(const string& headerLine) {
    stringstream ss(headerLine);
    string field;
    int pos = 0;

    headerMap.clear();

    while(getline(ss, field, ',')) {
        if(isdigit(field[0]))
        {
            string length = field.substr(0,2);
            headerMap[0] = length;
            field = field.substr(2, field.size() - 2);
            pos++;
            
            // Checks if the rest of the string has quotes
            if (field.front() == '"' && field.back() == '"')
            {
                field = field.substr(1, field.size() - 2);
                headerMap[pos] = field;
                pos++;

            }
            else
            {
                headerMap[pos] = field;
                pos++;
            }
        }
        // If the CSV contains quoted fields, remove the quotes.
        else if (field.front() == '"' && field.back() == '"') {
            field = field.substr(1, field.size() - 2);
            headerMap[pos] = field;
            pos++;

        }
        else
        {
            headerMap[pos] = field;
            pos++;
        }
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
            if(iter == (count-1) || iter == 0)
            {
                newHeader = newHeader + headerMap[iter];
                iter++;
            }
            else
            {
                newHeader = newHeader + headerMap[iter] + ",";
                iter++;
            }
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
    inFile.close();
    remove(filename);

    char newfile[newFile.size() + 1];
    strcpy(newfile, newFile.c_str());
    file.close();
    rename(newfile, filename);


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
        cout << endl;
    }    
}


ostream& operator<<(ostream& out, const ZipcodeNewBuffer& buffer)
{
    out << "File Type: "  << buffer.filetype << endl;
    out << "Version: " << buffer.ver << endl;
    out << "Length Indicated: " << buffer.len_ind << endl;
    out << "Record Bytes: " << buffer.recordByte << endl;
    out << "Format Type: " << buffer.formatType << endl;
    out << "Primary File Name: " << buffer.primaryFileName << endl;
    out << "Record Count: " << buffer.recordCount << endl;
    out << "Field Count: " << buffer.fieldCount << endl;
    out << "Primary Field: " << buffer.primaryField << endl;
}