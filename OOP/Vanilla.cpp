//
//  Vanilla.cpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#include "Vanilla.hpp"
#include <iostream>

// Constructor
VanillaOption::VanillaOption(double expiry_, const PayoffBridge& thePayoff_) : expiry(expiry_), thePayoff(thePayoff_){
    //thePayoffPtr = thePayoff_.clone(); the PayoffBridge does that for us
}

// return expiry
double VanillaOption::getExpiry() const {
    return expiry;
}

double VanillaOption::optionPayoff(double spot) const {
    return thePayoff -> operator()(spot); // structure deference operator
}

//VanillaOption::~VanillaOption(){
//    //std::cout << "Vanilla Destructor" << std::endl;
//    delete thePayoffPtr; // destroy the memory allocated when the object goes out of scope.
//}

// copy construction defined
//VanillaOption::VanillaOption(const VanillaOption& original) : expiry(original.expiry),thePayoffPtr(original.thePayoffPtr->clone()){}

//// this "move" copy constructor will be used when the rvalues are passed.
//VanillaOption::VanillaOption(VanillaOption&& original) : expiry(original.expiry), thePayoffPtr(original.thePayoffPtr){
//    original.thePayoffPtr = nullptr; // "nothing" to pointers. We need to leave it in a state to delete, while still not referring to our pointers.
//    std::cout << "Move copy constructor of vanilla" << std::endl;
//}

//VanillaOption& VanillaOption::operator=(const VanillaOption& original){
//    if (this != &original) {
//        expiry = original.expiry;
//        delete thePayoffPtr;
//        thePayoffPtr = original.thePayoffPtr->clone();
//    }
//    return *this;
//}

//
//VanillaOption& VanillaOption::operator=(VanillaOption&& original){
//    if (this != &original) {
//        expiry = original.expiry;
//        delete thePayoffPtr;
//        thePayoffPtr = original.thePayoffPtr; // we take the pointer
//        original.thePayoffPtr = nullptr;
//    }
//    std::cout << "Move assignment operator of vanilla" << std::endl;
//    return *this;
//}
