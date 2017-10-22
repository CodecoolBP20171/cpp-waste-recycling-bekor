//
// Created by Joe Bekor on 19/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_DUSTBINCONTENTERROR_HPP
#define CPP_WASTE_RECYCLING_BEKOR_DUSTBINCONTENTERROR_HPP

#include <exception>

class DustbinContentError: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: The dustbin content is not well formatted!";
    }
};


#endif //CPP_WASTE_RECYCLING_BEKOR_DUSTBINCONTENTERROR_HPP
