//
//  Movie.hpp
//  MymovieStore
//
//  Created by PRINCE CLUMSON-EKLU on 5/3/18.
//  Copyright © 2018 PRINCE CLUMSON-EKLU. All rights reserved.
//

#ifndef Movie_hpp
#define Movie_hpp

#include <stdio.h>
#include <vector>
#include <ostream>
#include <string>
#include "StringEnh.hpp"


/**
 * The Movie class identifies properties of a movie.
 **/
class Movie {
public:
    // Enumerated type of Movie available for the customer.
    enum MovieType { UNKNOWN, REGULAR, CHILDREN, NEW_RELEASE };
    
    // Static function to return Movie's price for a small
    static double getPriceRegular();
    
    // Static function to return Movie's price for a medium
    static double getPriceChildren();
    
    // Static function to return Movie's price for a large
    static double getPriceNewRelease();
    
    // Static function to return Movie's max number of renting days
    static int getMaxNumberOfRentingDays();
    
    // Function to cast Movie's TYPE from type string to MovieType
    static MovieType stringToMovieType(std::string str);
    
    // Static function to return Movie's type as a string
    static std::string movieTypeToString(MovieType movieType);
    
    // Static function to validate Movie's type
    static bool isMovieTypeValid(char c);
    
    // Static function to validate Movie's type
    static bool isMovieTypeValid(std::string movieType);
    
    // Static function to validate Movie's number of additional renting days.
    static bool isNumberOfRentingDaysValid(int numberRentingDays);
    
    // Constructor default
    Movie();
    
    // Constructor allowing caller to specify a Movie's type and number of additional days
    Movie(MovieType movieType, int numberOfRentingDays);
    
    // Accessor to return Movie's type
    MovieType getMovieType() const;
    
    // Accessor to return Movie's number of additional renting days.
    int getNumberOfRentingDays() const;
    
    // Function to calculate and return Movie's cost
    double calculateCost() const;
    
    // Function to return true/false whether Movie is valid (initialized)
    bool isValid() const;
    
    // Function to return Movie as a string
    std::string toString() const;
    
    // Overloaded insertion operator <<
    friend std::ostream &operator <<(std::ostream &os, const Movie &movie);
    
private:
    // Instance variables
    bool initialized;
    MovieType movieType;
    int numberOfRentingDays;
};


#endif /* Movie_hpp */
