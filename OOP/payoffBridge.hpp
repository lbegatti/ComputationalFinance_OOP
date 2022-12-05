//
//  payoffBridge.hpp
//  OOP
//
//  Created by Luca Begatti on 05/12/2022.
//

#ifndef payoffBridge_hpp
#define payoffBridge_hpp

#include <stdio.h>
#include "Payoff.hpp"

#endif /* payoffBridge_hpp */

class PayoffBridge{
public:
    
    // structure de-reference operator
    Payoff* operator ->() const;
    
    //the constructor
    PayoffBridge(const Payoff& thePayoff);
    
    //rule of three
    ~PayoffBridge(); // Destructor
    PayoffBridge(const PayoffBridge& original); // Copy
    PayoffBridge& operator=(const PayoffBridge& original); // Assignment
private:
    Payoff* thePayoffPtr;
};
