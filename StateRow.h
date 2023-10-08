/**
 * @file StateRow.h
 * @brief Declaration of the StateRow class.
 * @authors Tristan Adams and Preston Betz
 */

#ifndef STATEROW_H
#define STATEROW_H

#include <string> // for the states ID
#include <iostream>

using namespace std;

/**
 * @class StateRow
 * @brief A class representing a state with geographic data.
 */
class StateRow {
private:
    bool fresh;
    string ID; ///< State ID
    double eastmost; ///< Easternmost longitude
    double westmost; ///< Westernmost longitude
    double northmost; ///< Northernmost latitude
    double southmost; ///< Southernmost latitude

    int eastmostZ; ///< Easternmost longitude Zipcode
    int westmostZ; ///< Westernmost longitude Zipcode
    int northmostZ; ///< Northernmost latitude Zipcode
    int southmostZ; ///< Southernmost latitude Zipcode

public:
    /**
     * @brief Default constructor.
     * Initializes a StateRow object with default values.
     * - State ID: "TEMP"
     * - Easternmost longitude: 00.00
     * - Westernmost longitude: 00.00
     * - Northernmost latitude: 00.00
     * - Southernmost latitude: 00.00
     */
    StateRow();

    /**
     * @brief Parameterized constructor.
     * Initializes a StateRow object with the specified values.
     * @param id The state's ID.
     * @param e Easternmost longitude.
     * @param w Westernmost longitude.
     * @param n Northernmost latitude.
     * @param s Southernmost latitude.
     */
    StateRow(string id, double e, double w, double n, double s, int eZ, int wZ, int nZ, int sZ);

    /**
     * @brief Get the state's ID.
     * @return The state's ID.
     */
    string getID();
     
    bool getFresh() const;
    // Getter methods
    double getEast(); ///< Get the easternmost longitude.
    double getWest(); ///< Get the westernmost longitude.
    double getNorth(); ///< Get the northernmost latitude.
    double getSouth(); ///< Get the southernmost latitude.


    int getEastZ(); ///< Get the easternmost longitude Zipcode.
    int getWestZ(); ///< Get the westernmost longitude Zipcode.
    int getNorthZ(); ///< Get the northernmost latitude Zipcode.
    int getSouthZ(); ///< Get the southernmost latitude Zipcode.

    // Setter methods
    void setFresh(bool b);
    void setID(string id); ///< Set the state's ID.
    void setEast(double east); ///< Set the easternmost longitude.
    void setWest(double west); ///< Set the westernmost longitude.
    void setNorth(double north); ///< Set the northernmost latitude.
    void setSouth(double south); ///< Set the southernmost latitude.

    void setEastZ(int eastZ); ///< Set the easternmost longitude Zipcode.
    void setWestZ(int westZ); ///< Set the westernmost longitude Zipcode.
    void setNorthZ(int northZ); ///< Set the northernmost latitude Zipcode.
    void setSouthZ(int southZ); ///< Set the southernmost latitude Zipcode.

    /**
     * @brief Overloaded operator to print StateRow objects.
     * @param out Output stream.
     * @param row StateRow object to print.
     * @return Reference to the output stream.
     */
    friend ostream& operator<<(ostream& out, const StateRow& row);
};
#include "StateRow.cpp"
#endif