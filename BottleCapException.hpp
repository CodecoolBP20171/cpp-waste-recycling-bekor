//
// Created by bekor on 10/22/17.
//

#ifndef CPP_WASTE_RECYCLING_BEKOR_BOTTLECAPEXCEPTION_HPP
#define CPP_WASTE_RECYCLING_BEKOR_BOTTLECAPEXCEPTION_HPP

#include <exception>

class BottleCapException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: The bottle cap is not purple!";
    }
};
#endif //CPP_WASTE_RECYCLING_BEKOR_BOTTLECAPEXCEPTION_HPP
