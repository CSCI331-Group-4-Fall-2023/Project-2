/**
 * \file ZipcodeBuffer.cpp
 * \author Andrew Clayton
 * \version 1.4
 * \brief Implementation file for ZipcodeBuffer class.
 */


#include "ZipcodeBuffer.h" 
#include <sstream> //For stringstream
#include <string> //For getline

//Default constructor
ZipcodeBuffer::ZipcodeBuffer() {
    zipcode = 0;
    city = "";
    state = "";
    county = "";
    latitude = 0.0;
    longitude = 0.0;
}

//Constructor
ZipcodeBuffer::ZipcodeBuffer(int zipcode, string city, string state, string county, double latitude, double longitude) {
    this->zipcode = zipcode;
    this->city = city;
    this->state = state;
    this->county = county;
    this->latitude = latitude;
    this->longitude = longitude;
}


//Getters
int ZipcodeBuffer::getZipcode() const {
    return zipcode;
}

string ZipcodeBuffer::getCity() const {
    return city;
}

string ZipcodeBuffer::getState() const {
    return state;
}

string ZipcodeBuffer::getCounty() const {
    return county;
}

double ZipcodeBuffer::getLatitude() const {
    return latitude;
}

double ZipcodeBuffer::getLongitude() const {
    return longitude;
}

//Setters
void ZipcodeBuffer::setZipcode(int zipcode) {
    this->zipcode = zipcode;
}

void ZipcodeBuffer::setCity(string city) {
    this->city = city;
}

void ZipcodeBuffer::setState(string state) {
    this->state = state;
}

void ZipcodeBuffer::setCounty(string county) {
    this->county = county;
}

void ZipcodeBuffer::setLatitude(double latitude) {
    this->latitude = latitude;
}

void ZipcodeBuffer::setLongitude(double longitude) {
    this->longitude = longitude;
}

//Other functions

void ZipcodeBuffer::setFromFile(string fileLine) {
    // Extract the first two characters and convert them to an integer
    if (fileLine.size() >= 2) {
        length = std::stoi(fileLine.substr(0, 2));
    } else {
        // Handle the case where the fileLine is shorter than 2 characters
        // For now, I'll set length to 0, but you may want to handle this differently
        length = 0;
    }

    // Picks up after the first two characters (after the length indication)
    stringstream ss(fileLine.substr(2));
    string field;
    int pos = 0;

    while (getline(ss, field, ',')) {
        string columnName = headerMap[pos];

        if (columnName == "ZipCode") {
            zipcode = std::stoi(field);
        } else if (columnName == "PlaceName") {
            city = field;
        } else if (columnName == "State") {
            state = field;
        } else if (columnName == "County") {
            county = field;
        } else if (columnName == "Lat") {
            latitude = std::stod(field);
        } else if (columnName == "Long") {
            longitude = std::stod(field);
        } 
        // You can add more else-if conditions if there are other columns in the CSV.

        pos++;
    }
}


void ZipcodeBuffer::setHeaderMap(const string& headerLine) {
    // Picks up after the length indication
    stringstream ss(headerLine.substr(2));
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

int ZipcodeBuffer::getLength() const {
    return length;
}

int ZipcodeBuffer::setLength(int len) {
    length = len;
}


//OVERLOADED OPERATORS
//Overloaded input operator
istream& operator>>(istream& in, ZipcodeBuffer& buffer) {
    string fileLine;
    getline(in, fileLine);
    buffer.setFromFile(fileLine);
    return in;
}

//Overloaded output operator
ostream& operator<<(ostream& out, const ZipcodeBuffer& buffer) {
    out << buffer.zipcode << ", " << buffer.city << ", " << buffer.state << ", " << buffer.county << ", " << buffer.latitude << ", " << buffer.longitude;
    return out;
}

