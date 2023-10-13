#ifndef ZIPCODENEWBUFFER_H
#define ZIPCODENEWBUFFER_H

#include <iostream>
#include <map>
using namespace std;


class ZipcodeNewBuffer 
{
    private:
        /// \brief Map to store the header of the CSV file to keep column sorting flexible.
        map<int, string> headerMap;

    public:
        /**
         * \brief Default constructor
         * \pre None
         * \post ZipcodeNewBuffer object is created with default values
        */
        ZipcodeNewBuffer();



        /**
         * \brief Function to set the header map of the CSV file
         * \param headerLine String representing the header line of the CSV file
         * \pre ZipcodeNewBuffer object must exist
         * \post ZipcodeNewBuffer object's headerMap is set to the values in the given string
        */
        void getHeaderMap(const string& headerLine);

        void printHeaderMap();

        bool setHeaderMap(string fileName);
    
};
#include "ZipcodeNewBuffer.cpp"

#endif