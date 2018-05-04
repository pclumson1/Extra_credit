//
//  main.cpp
//  MymovieStore
//
//  Created by PRINCE CLUMSON-EKLU on 5/3/18.
//  Copyright © 2018 PRINCE CLUMSON-EKLU. All rights reserved.
//

#include <iostream>

#include <time.h>
#include <vector>
#include "Movie.hpp"
#include "MovieOrder.hpp"
#include "StringEnh.hpp"

void printTime();
using namespace std;

// Constants
static const string NO = "No";
static const string YES = "Yes";

/**
 * Prompt user for number of movies in order
 */
static int askForNumberOfMovies()
{
    int numberOfMovies = 0;
    string input;
    cout<<"*************************************************************************"<<endl;
    cout<<"**************************************************************************"<<endl;
    cout << "How many movies would you like to order ? (0-" << MovieOrder::getMaxNumberOfMovies() << ") [0]: ";
    getline(cin, input);
    if (!input.empty()) {
        int tempNumberOfMovies = stoi(input);
        if (MovieOrder::isNumberOfMoviesValid(tempNumberOfMovies))
            numberOfMovies = tempNumberOfMovies;
    }
    
    return numberOfMovies;
}

/**
 * Prompt user for Movie's pan size
 */
static Movie::MovieType askForMovieType(int MovieNumber)
{
    static const string INVALID = "Unrecognized movie type selected, try again.";
    static const string TRY_AGAIN = "No movie type  selected, do you want to try again? (Y/N) [Y]: ";
    
    Movie::MovieType movieType = Movie::UNKNOWN;
    string input;
    
    while (true) {
        cout << endl << "For movie " << MovieNumber << ", what type would you like? <r>egular, <c>hildren, <n>ew release: ";
        getline(cin, input);
        if (!input.empty()) {
            Movie::MovieType tempMovieType = Movie::stringToMovieType(input);
            if (tempMovieType != Movie::UNKNOWN) {
                movieType = tempMovieType;
                break;
            }
            cout << INVALID << endl;
        } else {
            cout << TRY_AGAIN;
            getline(cin, input);
            if (!input.empty()) {
                if (toupper(input[0]) == NO[0])
                    break;
            }
        }
    }
    
    return movieType;
}

/**
 * Prompt user for number of additional days for rental.
 */
static int askForNumberOfCheeseToppings(int MovieNumber)
{
    static const string INVALID = "Invalid number of additional days of renting, try again.";
    
    int numberOfToppings = 0;
    string input;
    
    while (true) {
        cout << endl;
        cout << "For movie" << MovieNumber  << ", how many additional days of renting  would you like? (0-" << (Movie::getMaxNumberOfRentingDays() - 2) << ") [0]: ";
        getline(cin, input);
        if (!input.empty()) {
            int tempNumberOfToppings = std::stoi(input);
            if (Movie::isNumberOfRentingDaysValid(tempNumberOfToppings)) {
                numberOfToppings = tempNumberOfToppings;
                break;
            }
            cout << INVALID << endl;
        } else {
            if (Movie::isNumberOfRentingDaysValid(numberOfToppings))
                break;
            cout << INVALID << endl;
        }
    }
    
    return numberOfToppings;
}

/**
 * Prompt user for a Movie order
 */
static MovieOrder askForOrder()
{
    // Prompt for number of Movies for this Movie order (limmited to the max allowed for an order)
    int numberOfMovies = askForNumberOfMovies();
    if (numberOfMovies == 0)
    {
        exit(0);
    }
    
    
    // Start a new Movie order
    MovieOrder order;
    
    // Prompt for each Movie's pan size and number of cheese toppings
    for (int i = 0; i < numberOfMovies; i++) {
        // Compute which Movie this is
        int MovieNumber = (i + 1) ;
        
        // Prompt for pan size
        Movie::MovieType movieType = askForMovieType(MovieNumber);
        if (movieType == Movie::UNKNOWN)
            break;
        
        // Create Movie based on pan size and number of cheese toppings
        int numberOfToppings = askForNumberOfCheeseToppings(MovieNumber);
        Movie movie = Movie(movieType, numberOfToppings);
        
        // Add Movie to order
        order.add(movie);
    }
    
    string costomer;
    cout<<"please enter your Name"<<endl;
    cin >> costomer;
    
    cout<<"***************************************************************"<<endl;
    printTime();
    cout<<"***************************************************************"<<endl;
    cout<<"***************************************************************"<<endl;
    cout<< costomer << " here is your movie rental receipt :"<<endl;
    printTime();
    cout<<"***************************************************************"<<endl;
    return order;
    //cout<<"***************************************************************"<<endl;
}

/**
 * Print a receipt for the movie order
 */
static void printReceipt(const MovieOrder &order) {
    cout << order << endl;
}
int main(int argc, const char * argv[])
{
    
    // Prompt for a movie order
    MovieOrder order = askForOrder();
    
    // Print the movie order receipt
    printReceipt(order);
    
    
    return 0;
}

void printTime()
{
    
    
    std::cout << "MOVIE RENTAL RECEIPT:!\n";
    
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    
    strftime (buffer, 80,"%Y-%m-%d at %H:%M:%S",timeinfo);
    puts (buffer);
    
    
}

