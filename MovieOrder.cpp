//
//  MovieOrder.cpp
//  MymovieStore
//
//  Created by PRINCE CLUMSON-EKLU on 5/3/18.
//  Copyright © 2018 PRINCE CLUMSON-EKLU. All rights reserved.
//

#include "MovieOrder.hpp"
#include "Movie.hpp"
#include <cstdio>
#include <ostream>
#include <iostream>
#include <vector>

/**
 *  STATIC CONSTANT NUMBER OF MOVIE
 */
static const int MAX_NUMBER_OF_MovieS = 3;

/**
 * FUNCTION TO ACCOMODATE THE MAX MOVIE ORDER.
 */
int MovieOrder::getMaxNumberOfMovies()
{
    return MAX_NUMBER_OF_MovieS;
}

/**
 * FUNCTION TO VALIDATE THE NUMBER OF MOVIES
 */
bool MovieOrder::isNumberOfMoviesValid(int numberOfMovies) {
    bool isValid = false;
    
    if (numberOfMovies >= 1 && numberOfMovies <= getMaxNumberOfMovies())
        isValid = true;
    
    return isValid;
}

/**
 * DEFAULT CONSTRUCTOR
 */
MovieOrder::MovieOrder()
{
    // MovieOrder now initialized
    this->initialized = true;
}

/**
 * FUNCTION TO ADD MOVIES WITH A VECTOR
 */
void MovieOrder::add(Movie movie)
{
    if ((int) movies.size() < MAX_NUMBER_OF_MovieS && movie.isValid())
        movies.push_back(movie);
}

/**
 * THIS FUNCTION CALCULATE AND RETURN THE TOTAL COST OF MOVIE ORDER.
 */
double MovieOrder::calculateTotal() const
{
    double total = 0.0;
    
    // Compute total based on accumulating cost of each MOVIE
    for (int i = 0; i < (int) movies.size(); i++) {
        total += movies[i].calculateCost();
    }
    
    return total;
}

/**
 * Function to return true/false whether MOVIE order is valid (initialized)
 */
bool MovieOrder::isValid() const
{
    return initialized;
}

/**
 * Function to return movie order as a string
 */
std::string MovieOrder::toString() const
{
    
    std::string receipt = "Thank you for your order.\n\n";
    
    // Generate a string based on the order placed
    bool firstTime = true;
    for (int i = 0; i < (int) movies.size(); i++) {
        if (firstTime) {
            firstTime = false;
            receipt += "Your order includes:\n\n";
        }
        receipt += movies[i].toString() + "\n\n";
    }
    if (firstTime) {
        receipt += "You haven't ordered any movies.";
    } else {
        char str[200];
        sprintf(str, "Total due: $%.2f", calculateTotal());
        
        receipt += str;
    }
    
    return receipt;
}

/**
 * Overloaded insertion operator <<
 */
std::ostream &operator <<(std::ostream &os, const MovieOrder &MovieOrder)
{
    // Output formatted string
    os << MovieOrder.toString();
    
    return os;
}
