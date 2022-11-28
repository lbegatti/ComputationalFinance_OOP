//
//  Vanilla.hpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#ifndef Vanilla_hpp
#define Vanilla_hpp

#include <stdio.h>

#endif /* Vanilla_hpp */

#pragma once
#include "Payoff.hpp"

class VanillaOption
{
public:
    VanillaOption(double expiry,Payoff& thePayoff);
    double getExpiry() const; //getter
    double optionPayoff(double spot) const;
    ~VanillaOption(); // Destructor
    VanillaOption(const VanillaOption& original); // copy constructor
    VanillaOption& operator=(const VanillaOption& original); // Assignment operator
private:
    double expiry; // holds expiry
    Payoff* thePayoffPtr; //reference variable to a payoff.
    
};
