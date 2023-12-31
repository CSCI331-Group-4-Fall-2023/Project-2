/**
 * \file ZipcodeRecordBuffer.h
 * \author Zachary Sunder
 * \version 1.1
 * \brief This header file defines the ZipcodeRecordBuffer class, which is used to read and write the data file header record.
 * 
 * ZipcodeRecordBuffer class: File to create and edit the data file header record
 * - Function to modify the data file header record created
 * - Overloaded output operator
 * - 
 * \note A valid CSV line must be provided to set the attributes correctly if not using the default constructor
 */

#ifndef ZipcodeRecordBuffer_H
#define ZipcodeRecordBuffer_H

#include <iostream>
#include <map>
using namespace std;

/**
 * \class ZipcodeRecordBuffer
 * \brief Class to hold the information of a data file header record.
 */
class ZipcodeRecordBuffer 
{
    private:
        // \brief filetype as a string
        string filetype;

        // \brief ver as a double
        double ver;

        // \brief len_ind as a int
        int len_ind;

        // \brief recordByte as a int
        int recordByte;

        // \brief formatType as a string
        string formatType;

        // \brief primaryFileName as a string
        string primaryFileName;

        // \brief recordCount as a int
        int recordCount;

        // \brief fieldCount as a int
        int fieldCount;

        // \brief primaryField as a string
        string primaryField;

        /// \brief Map to store the header of the CSV file to keep column sorting flexible.
        map<int, string> headerMap;

    public:
        /**
         * \brief Default constructor
         * \pre None
         * \post ZipcodeRecordBuffer object is created with default values
        */
        ZipcodeRecordBuffer();

        /**
         * \brief Parameterized constructor to initialize the object with given values.
         * \param fileName string representing the name of the CSV file
         * \param mainField string representing the main field of the header record data file
         * \pre None
         * \post ZipcodeRecordBuffer object is created with given values and values pulled from the CSV file.
         */
        ZipcodeRecordBuffer(string fileName, string mainField);    
    

        // Setters

        /**
         * \brief Setter for fileType
         * \param FileType string value of fileType
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's fileType attribute is set to the given value
        */
        void setFileType(const string& FileType);

        /**
         * \brief Setter for ver
         * \param Ver double value of ver
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's ver attribute is set to the given value
        */
        void setVer(double Ver);
        
        /**
         * \brief Setter for len_ind
         * \param Len integer value of len_ind
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's len_ind attribute is set to the given value
        */
        void setLenInd(int Len);

        /**
         * \brief Setter for recordByte
         * \param RecordByte integer value of recordByte
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's recordByte attribute is set to the given value
        */
        void setRecordByte(int RecordByte);

        /**
         * \brief Setter for formatType
         * \param FormatType string value of formatType
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's formatType attribute is set to the given value
        */
        void setFormatType(const string& FormatType);

        /**
         * \brief Setter for primaryFileName
         * \param FileName string value of primaryFileName
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's primaryFileName attribute is set to the given value
        */
        void setPrimaryFileName(const string& FileName);

        /**
         * \brief Setter for recordCount
         * \param RecordCount string value of recordCount
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's recordCount attribute is set to the given value
        */
        void setRecordCount(int RecordCount);

        /**
         * \brief Setter for fieldCount
         * \param FieldCount string value of fieldCount
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's fieldCount attribute is set to the given value
        */
        void setFieldCount(int FieldCount);

        /**
         * \brief Setter for primaryField
         * \param PrimaryField string value of primaryField
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's primaryField attribute is set to the given value
        */
        void setPrimaryField(const string& PrimaryField);


        // Getters

        /**
         * \brief Getter for fileType
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return String value of fileType
        */
        string getFileType();

        /**
         * \brief Getter for ver
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return double value of ver
        */
        double getVer();

        /**
         * \brief Getter for len_ind
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return Integer value of len_ind
        */
        int getLenInd();

        /**
         * \brief Getter for recordByte
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return Integer value of recordByte
        */
        int getRecordByte();

        /**
         * \brief Getter for formatType
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return String value of formatType
        */
        string getFormatType();

        /**
         * \brief Getter for primaryFileName
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return String value of primaryFileName
        */
        string getPrimaryFileName();

        /**
         * \brief Getter for recordCount
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return Integer value of recordCount
        */
        int getRecordCount();

        /**
         * \brief Getter for fieldCount
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return Integer value of fieldCount
        */
        int getFieldCount();

        /**
         * \brief Getter for primaryField
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
         * \return String value of primaryField
        */
        string getPrimaryField();

        /**
         * \brief Function to get the field specified by position
         * \param position integer representing the field number in the header
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
        */
        string getFieldx(int position);

        /**
         * \brief Function to get the field type of specified field
         * \param position integer representing the field number in the header
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
        */
        string getFieldType(int position);

        /**
         * \brief Function to set the header map of the CSV file
         * \param headerLine String representing the header line of the CSV file
         * \pre ZipcodeRecordBuffer object must exist
         * \post ZipcodeRecordBuffer object's headerMap is set to the values in the given string
        */
        void getHeaderMap(const string& headerLine);



        //Other Functions
        
        /**
         * \brief Function to print the header of the CSV file
         * \pre ZipcodeRecordBuffer object must exist
         * \post None
        */
        void printHeaderMap();

        /**
         * \brief Function to set the header of the CSV file
         * \param fileName String representing the name of the CSV file
         * \pre ZipcodeRecordBuffer object must exist
         * \post The CSV file with name fileName has its header rewritten to what what stored in the ZipcodeRecordBuffer
        */
        bool setHeaderMap(string fileName);




        //OVERLOADED OPERATORS
        /**
         * \brief Overloaded output operator for ZipcodeRecordBuffer
         * \param out Output stream
         * \param a ZipcodeRecordBuffer to display
         * \pre None
         * \post The the header record is displayed
         * \return Updated output stream
         */
        friend ostream& operator<<(ostream& out, const ZipcodeRecordBuffer& buffer);
};
#include "ZipcodeRecordBuffer.cpp"

#endif