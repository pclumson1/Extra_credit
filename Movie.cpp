//
//  Movie.cpp
//  MymovieStore
//
//  Created by PRINCE CLUMSON-EKLU on 5/3/18.
//  Copyright © 2018 PRINCE CLUMSON-EKLU. All rights reserved.
//

#include "Movie.hpp"
#include <cstdlib>
#include <cstdio>
#include <ostream>
#include <vector>

/**
 * MOVIE TYPE  constants
 */
static const std::string SIZE_REGULAR = "Regular";
static const std::string SIZE_CHILDREN = "Children";
static const std::string SIZE_NEW_RELEASE = "New release";

/**
 * Pricing constants
 */
static const double PRICE_REGULAR = 6.0;
static const double PRICE_CHILDREN = 8.0;
static const double PRICE_NEW_RELEASE = 10.0;
static const double PRICE_ADDITIONAL_RENTING_DAYS = 1.0;

/**
 * ADDITIONAL RENTING DAYS
 */
static const int MAX_NUMBER_OF_RENTING_DAYS = 3;

/**
 * Function to return Movie's price for a regular
 */
double Movie::getPriceRegular()
{
    return PRICE_REGULAR;
}

/**
 * Function to return Movie's price for children
 */
double Movie::getPriceChildren()
{
    return PRICE_CHILDREN;
}

/**
 * Function to return Movie's price for a new releases
 */
double Movie::getPriceNewRelease()
{
    return PRICE_NEW_RELEASE;
}

/**
 * Function to return Movie's max number of additional renting days
 */
int Movie::getMaxNumberOfRentingDays()
{
    return MAX_NUMBER_OF_RENTING_DAYS;
}

/**
 * Function to cast Movie's  from type char to MovieType
 */
Movie::MovieType Movie::stringToMovieType(std::string str) {
    MovieType movieType = UNKNOWN;
    
    char c = toupper(str[0]);
    if (c == SIZE_REGULAR[0])
        movieType = REGULAR;
    else if (c == SIZE_CHILDREN[0])
        movieType = CHILDREN;
    else if (c == SIZE_NEW_RELEASE[0])
        movieType = NEW_RELEASE;
    
    return movieType;
}

/**
 * Function to return Movie's type as a string
 */
std::string Movie::movieTypeToString(MovieType movieType)
{
    std::string str;
    
    if (movieType == REGULAR)
        str = SIZE_REGULAR;
    else if (movieType == CHILDREN)
        str = SIZE_CHILDREN;
    else if (movieType == NEW_RELEASE)
        str = SIZE_NEW_RELEASE;
    
    return str;
}

/**
 * Function to validate Movie's type
 */
bool Movie::isMovieTypeValid(char c)
{
    bool isValid = false;
    
    c = toupper(c);
    if (c == SIZE_REGULAR[0])
        isValid = true;
    else if (c == SIZE_CHILDREN[0])
        isValid = true;
    else if (c == SIZE_NEW_RELEASE[0])
        isValid = true;
    
    return isValid;
}

/**
 * Function to validate Movie's pan size
 */
bool Movie::isMovieTypeValid(std::string movieType)
{
    bool isValid = false;
    
    if (!movieType.empty())
        isValid = isMovieTypeValid(movieType[0]);
    
    return isValid;
}

/**
 * Function to validate Movie's number renting days
 */
bool Movie::isNumberOfRentingDaysValid(int numberOfRentingDays)
{
    bool isValid = false;
    
    if (numberOfRentingDays >= 0 && numberOfRentingDays <=MAX_NUMBER_OF_RENTING_DAYS)
        isValid = true;
    
    return isValid;
}

/**
 * Constructor default
 */
Movie::Movie()
{
    initialized = false;
    
    movieType = REGULAR;
    numberOfRentingDays = 0;
}

/**
 * Constructor allowing caller to specify a Movie's type and renting days
 */
Movie::Movie(MovieType movieType, int numberOfRentingDays)
{
    this->initialized = false;
    
    // Init other Movie's attributes
    this->movieType = movieType;
    this->numberOfRentingDays = numberOfRentingDays + 1;
    
    // Movie now initialized
    this->initialized = true;
}

/**
 * Accessor to return Movie's sizmovieType*/
Movie::MovieType Movie::getMovieType() const
{
    return movieType;
}

/**
 * Accessor to return Movie's number of cheese toppings
 */
int Movie::getNumberOfRentingDays() const
{
    return numberOfRentingDays;
}

/**
 * Function to calculate and return Movie's cost
 */
double Movie::calculateCost() const {
    double cost = 0.0;
    
    // Compute cost based on pan size
    switch (movieType) {
        case REGULAR:
            cost = getPriceRegular();
            break;
        case CHILDREN:
            cost = getPriceChildren();
            break;
        case NEW_RELEASE:
            cost = getPriceNewRelease();
            break;
        default:
            break;
    }
    
    // Add cost of additional days
    cost += (numberOfRentingDays - 1) * PRICE_ADDITIONAL_RENTING_DAYS;
    
    return cost;
}

/**
 * Returns true/false whether Movie is valid (initialized)
 */
bool Movie::isValid() const
{
    return initialized;
}

/**
 * Function to return Movie as a string
 */
std::string Movie::toString() const
{
    char str[200];
    
    // Format string
    sprintf(str, "%s Your Movie with:\n   %d Additional days of renting\t\t%6.2f", movieTypeToString(movieType).c_str(), numberOfRentingDays, calculateCost());
    
    return std::string(str);
}

/**
 * Overloaded insertion operator <<
 */
std::ostream &operator <<(std::ostream &os, const Movie &Movie)
{
    // Output formatted string
    os << Movie.toString();
    
    return os;
}
