/**
 * \file ZipcodeBuffer.h
 * \author Andrew Clayton
 * \version 1.4
 * \brief This header file defines the ZipcodeBuffer class, which is used to take in and store data from a Zipcode CSV file.
 * 
 * ZipcodeBuffer class: File to work with Zipcode CSV file
 * - Function to take in a line of the CSV file as a string and set the attributes of the object
 * - Overloaded input and output operators
 * - 
 * \note A valid CSV line must be provided to set the attributes correctly
 */

#ifndef ZIPCODEBUFFER_H
#define ZIPCODEBUFFER_H

#include <iostream>
#include <map>
using namespace std;

/**
 * \class ZipcodeBuffer
 * \brief Class to represent a Zipcode and its related attributes.
 */
class ZipcodeBuffer {
    private:
        /// @brief  The length of the line in the CSV file.
        int length;

        /// \brief Zipcode as an integer.
        int zipcode;
        
        /// \brief City name as a string.
        string city;
        
        /// \brief State abbreviation as a string.
        string state;
        
        /// \brief County name as a string.
        string county;
        
        /// \brief Latitude as a double.
        double latitude;
        
        /// \brief Longitude as a double.
        double longitude;

        /// \brief Map to store the header of the CSV file to keep column sorting flexible.
        map<int, string> headerMap;


    public:
        /**
         * \brief Default constructor
         * \pre None
         * \post ZipcodeBuffer object is created with default values
        */
        ZipcodeBuffer();

        /**
         * \brief Parameterized constructor to initialize the object with given values.
         * \param zipcode Integer value representing the Zipcode.
         * \param city String representing the city.
         * \param state String representing the state.
         * \param county String representing the county.
         * \param latitude Double representing the latitude.
         * \param longitude Double representing the longitude.
         * \pre None
         * \post ZipcodeBuffer object is created with given values.
         */
        ZipcodeBuffer(int zipcode, string city, string state, string county, double latitude, double longitude);


        //Getters

        /**
         * \brief Getter for zipcode
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return Integer value of zipcode
        */
        int getZipcode() const;

        /**
         * \brief Getter for city
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return String value of city
        */
        string getCity() const;

        /**
         * \brief Getter for state
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return String value of state
        */
        string getState() const;

        /**
         * \brief Getter for county
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return String value of county
        */
        string getCounty() const;

        /**
         * \brief Getter for latitude
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return Double value of latitude
        */
        double getLatitude() const;

        /**
         * \brief Getter for longitude
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return Double value of longitude
        */
        double getLongitude() const;

        /**
         * \brief Getter for length
         * \pre ZipcodeBuffer object must exist
         * \post None
         * \return Integer value of length
        */
        int getLength() const;

        

        //Setters
        /**
         * \brief Setter for zipcode
         * \param zipcode Integer value of zipcode
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's zipcode attribute is set to the given value
        */
        void setZipcode(int zipcode);

        /**
         * \brief Setter for city
         * \param city String value of city
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's city attribute is set to the given value
        */
        void setCity(string city);

        /**
         * \brief Setter for state
         * \param state String value of state
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's state attribute is set to the given value
        */
        void setState(string state);

        /**
         * \brief Setter for county
         * \param county String value of county
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's county attribute is set to the given value
        */
        void setCounty(string county);

        /**
         * \brief Setter for latitude
         * \param latitude Double value of latitude
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's latitude attribute is set to the given value
        */
        void setLatitude(double latitude);

        /**
         * \brief Setter for longitude
         * \param longitude Double value of longitude
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's longitude attribute is set to the given value
        */
        void setLongitude(double longitude);

        /**
         * \brief Function to take in a line of the CSV file as a string and set the attributes of the object
         * \param fileLine String representing a line of the CSV file
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's attributes are set to the values in the given string
        */
        void setFromFile(string fileLine);

        /**
         * \brief Setter for length
         * \param length Integer value of length
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's length attribute is set to the given value
        */
        void setLength(int length);



        /**
         * \brief Function to set the header map of the CSV file
         * \param headerLine String representing the header line of the CSV file
         * \pre ZipcodeBuffer object must exist
         * \post ZipcodeBuffer object's headerMap is set to the values in the given string
        */
        void setHeaderMap(const string& headerLine);


        //OVERLOADED OPERATORS
        /**
         * \brief Overloaded input operator for ZipcodeBuffer to read in a line of a CSV file as a string
         * \param in Input stream
         * \param a ZipcodeBuffer to fill
         * \pre A ZipcodeBuffer object must exist
         * \post The first a.size elements of a.ptr are filled with integers read from input
         * \return Updated input stream
         */
        friend istream& operator>>(istream& in, ZipcodeBuffer& buffer);

        /**
         * \brief Overloaded output operator for ZipcodeBuffer
         * \param out Output stream
         * \param a ZipcodeBuffer to display
         * \pre None
         * \post The first a.size elements of a.ptr are displayed to output
         * \return Updated output stream
         */
        friend ostream& operator<<(ostream& out, const ZipcodeBuffer& buffer);

    
};

#include "ZipcodeBuffer.cpp"

#endif