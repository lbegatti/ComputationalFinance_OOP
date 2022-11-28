//
//  Vanilla.cpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#include "Vanilla.hpp"
#include <iostream>

// Constructor
VanillaOption::VanillaOption(double expiry_, Payoff& thePayoff_) : expiry(expiry_){
    thePayoffPtr = thePayoff_.clone();
}

// return expiry
double VanillaOption::getExpiry() const {
    return expiry;
}

double VanillaOption::optionPayoff(double spot) const {
    return (*thePayoffPtr)(spot); // dereference
}

VanillaOption::~VanillaOption(){
    std::cout << "Vanilla Destructor" << std::endl;
    delete thePayoffPtr; // destroy the memory allocated when the object goes out of scope.
}

// copy construction defined
VanillaOption::VanillaOption(const VanillaOption& original) : expiry(original.expiry),thePayoffPtr(original.thePayoffPtr->clone()){}

VanillaOption& VanillaOption::operator=(const VanillaOption& original){
    if (this != &original) {
        expiry = original.expiry;
        delete thePayoffPtr;
        thePayoffPtr = original.thePayoffPtr->clone();
    }
    return *this;
}
