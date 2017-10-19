//
// Created by Joe Bekor on 19/10/2017.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_DUSTBINCONTENTERROR_H
#define CPP_WASTE_RECYCLING_BEKOR_DUSTBINCONTENTERROR_H

#include <exception>

class DustbinContentError: public std::exception {
public:
    virtual const char* what() const noexcept{
        return "Error: The dustbin is content is not well formatted!";
    }
};


#endif //CPP_WASTE_RECYCLING_BEKOR_DUSTBINCONTENTERROR_H
