//
//  MovieOrder.hpp
//  MymovieStore
//
//  Created by PRINCE CLUMSON-EKLU on 5/3/18.
//  Copyright © 2018 PRINCE CLUMSON-EKLU. All rights reserved.
//

#ifndef MovieOrder_hpp
#define MovieOrder_hpp

#include <stdio.h>
#include <ostream>
#include <vector>


#include "StringEnh.hpp"
#include "Movie.hpp"


class MovieOrder {
public:
    // Static function to return movieorder's max number of Movies
    static int getMaxNumberOfMovies();
    
    // static function to return whether the number of movie is valid or not
    static bool isNumberOfMoviesValid(int numberOfMovies);
    
    // Constructor default
    MovieOrder();
    
    // Function to add a movie to the movie order
    void add(Movie movie);
    
    // Function to calculate and return movie order's total cost
    double calculateTotal() const;
    
    // Function to return true/false whether movie order is valid (initialized)
    bool isValid() const;
    
    // Function to return movie order as a string
    std::string toString() const;
    
    // Overloaded insertion operator <<
    friend std::ostream &operator <<(std::ostream &os, const MovieOrder &MovieOrder);
    
private:
    // Instance variables
    bool initialized;
    std::vector<Movie> movies;
};

#endif /* MovieOrder_hpp */
