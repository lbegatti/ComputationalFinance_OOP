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
#include "payoffBridge.hpp"
#include "Wrapper.h"

class VanillaOption
{
public:
    VanillaOption(double expiry, const Wrapper<Payoff>& thePayoff);
    double getExpiry() const; //getter
    double optionPayoff(double spot) const;
    
    // The rule of 5 --> the PayoffBridge memory takes care of this memory management.
//    ~VanillaOption(); // Destructor
//    VanillaOption(const VanillaOption& original); // copy constructor
//    VanillaOption& operator=(const VanillaOption& original); // Assignment operator
//    VanillaOption(VanillaOption&& original); // Move Copy Constructor -> rvalue reference
//    VanillaOption& operator=(VanillaOption&& original); // Move Assignment Operator
private:
    double expiry; // holds expiry
    Wrapper<Payoff> thePayoff; // General memory mgmt -> PayoffBridge via templating
    
};
