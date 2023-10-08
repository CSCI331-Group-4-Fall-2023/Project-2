// Authors: Tristan Adams and Preston Betz

#include "StateRow.h"

#include <string> // for the states ID
#include <iostream>

using namespace std;

/**
 * @brief Default constructor for StateRow.
 * Initializes a StateRow object with default values.
 * - State ID: "TEMP"
 * - Easternmost longitude: 00.00
 * - Westernmost longitude: 00.00
 * - Northernmost latitude: 00.00
 * - Southernmost latitude: 00.00
 */
StateRow::StateRow(){
    fresh = true;
    ID = "TEMP";
    eastmost = 00.00;
    westmost = 00.00;
    northmost = 00.00;
    southmost = 00.00;
    eastmostZ = 0;
    westmostZ = 0;
    northmostZ = 0;
    southmostZ = 0;
}

/**
 * @brief Parameterized constructor for StateRow.
 * Initializes a StateRow object with the specified values.
 * @param id The state's ID.
 * @param e Easternmost longitude.
 * @param w Westernmost longitude.
 * @param n Northernmost latitude.
 * @param s Southernmost latitude.
 */
StateRow::StateRow(string id, double e, double w, double n, double s, int eZ, int wZ, int nZ, int sZ){
    this->fresh = true;
    this->ID = id;
    this->eastmost = e;
    this->westmost = w;
    this->northmost = n;
    this->southmost = s;
    this->eastmostZ = eZ;
    this->westmostZ = wZ;
    this->northmostZ = nZ;
    this->southmostZ = sZ;
}

/**
 * @brief Get the fresh boolean.
 * @return The fresh bool.
 */
bool StateRow::getFresh() const {
    return fresh;
}

/**
 * @brief Get the easternmost longitude of the state.
 * @return The easternmost longitude.
 */
double StateRow::getEast(){
    return eastmost;
}

/**
 * @brief Get the westernmost longitude of the state.
 * @return The westernmost longitude.
 */
double StateRow::getWest(){
    return westmost;
}

/**
 * @brief Get the northernmost latitude of the state.
 * @return The northernmost latitude.
 */
double StateRow::getNorth(){
    return northmost;
}

/**
 * @brief Get the southernmost latitude of the state.
 * @return The southernmost latitude.
 */
double StateRow::getSouth(){
    return southmost;
}

/**
 * @brief Get the easternmost longitude Zipcode of the state.
 * @return The easternmost longitude Zipcode.
 */
int StateRow::getEastZ(){
    return eastmostZ;
}

/**
 * @brief Get the westernmost longitude Zipcode of the state.
 * @return The westernmost longitude Zipcode.
 */
int StateRow::getWestZ(){
    return westmostZ;
}

/**
 * @brief Get the northernmost latitude Zipcode of the state.
 * @return The northernmost latitude Zipcode.
 */
int StateRow::getNorthZ(){
    return northmostZ;
}

/**
 * @brief Get the southernmost latitude Zipcode of the state.
 * @return The southernmost latitude Zipcode.
 */
int StateRow::getSouthZ(){
    return southmostZ;
}

/**
 * @brief Get the state's ID.
 * @return The state's ID.
 */
string StateRow::getID(){
    return ID;
}

/**
 * @brief Set the easternmost longitude of the state.
 * @param e The easternmost longitude to set.
 */
void StateRow::setEast(double e){
    this->eastmost = e;
}

/**
 * @brief Set the westernmost longitude of the state.
 * @param w The westernmost longitude to set.
 */
void StateRow::setWest(double w){
    this->westmost = w;
}

/**
 * @brief Set the northernmost latitude of the state.
 * @param n The northernmost latitude to set.
 */
void StateRow::setNorth(double n){
    this->northmost = n;
}

/**
 * @brief Set the southernmost latitude of the state.
 * @param s The southernmost latitude to set.
 */
void StateRow::setSouth(double s){
    this->southmost = s;
}

/**
 * @brief Set the easternmost longitude Zipcode of the state.
 * @param e The easternmost longitude Zipcode to set.
 */
void StateRow::setEastZ(int eastZ){
    this->eastmostZ = eastZ;
}

/**
 * @brief Set the westernmost longitude Zipcode of the state.
 * @param w The westernmost longitude Zipcode to set.
 */
void StateRow::setWestZ(int westZ){
    this->westmostZ = westZ;
}

/**
 * @brief Set the northernmost latitude Zipcode of the state.
 * @param n The northernmost latitude Zipcode to set.
 */
void StateRow::setNorthZ(int northZ){
    this->northmostZ = northZ;
}

/**
 * @brief Set the southernmost latitude Zipcode of the state.
 * @param s The southernmost latitude Zipcode to set.
 */
void StateRow::setSouthZ(int southZ){
    this->southmostZ = southZ;
}

/**
 * @brief Set the state's ID.
 * @param id The state's ID to set.
 */
void StateRow::setID(string id){
    this->ID = id;
}

/**
 * @brief Set the fresh boolean.
 * @param b bool to set fresh to.
 */
void StateRow::setFresh(bool b){
    this->fresh = b;
}


/**
 * @brief Overloaded operator to print StateRow objects.
 * @param out Output stream.
 * @param row StateRow object to print.
 * @return Reference to the output stream.
 */
ostream& operator<<(ostream& out, const StateRow& row){
    out << row.ID << " | " 
        << row.eastmostZ << " | " 
        << row.westmostZ << " | " 
        << row.northmostZ << " | " 
        << row.southmostZ;
    return out;
}