//
//  StringEnh.hpp
//  MymovieStore
//
//  Created by PRINCE CLUMSON-EKLU on 5/3/18.
//  Copyright © 2018 PRINCE CLUMSON-EKLU. All rights reserved.
//

#ifndef StringEnh_hpp
#define StringEnh_hpp

#include <stdio.h>



#include <string>
#include <vector>

/**
 * The StringEnh class provides enhanced string functionality not available in the Standard Library string class
 */
class StringEnh {
public:
    // Trim string of leading and trailing whitespace
    static std::string trim(const std::string &str);
    
    // Tokenize string (break into vector of strings based on token/delimiter)
    static std::vector<std::string> tokenize(const std::string &str, const char *tokens);
    static std::vector<std::string> tokenize(const std::string &str, const std::string &tokens);
    
private:
    // Constructor default (use private to prevent creation)
    StringEnh();
};

#endif /* StringEnh_hpp */
