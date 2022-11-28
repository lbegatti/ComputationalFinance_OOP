//
//  Payoff.cpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#include "Payoff.hpp"
#include "maxfunction.hpp"

// initialization list for strike
PayoffCall::PayoffCall(double strike_) : strike(strike_){
    
}

double PayoffCall::operator()(double spot) const{
    return max(spot - strike, 0.0);
}

Payoff* PayoffCall::clone() const {
    /*Payoff* ptr;
    ptr = new PayoffCall(*this);
    return ptr;*/
    return new PayoffCall(*this); // "this" is a pointer to the object calling the method
}

PayoffPut::PayoffPut(double strike_) : strike(strike_){
    
}

double PayoffPut::operator()(double spot) const{
    return max(strike-spot, 0.0);
}
Payoff* PayoffPut::clone() const {
    /*Payoff* ptr;
    ptr = new PayoffCall(*this);
    return ptr;*/
    return new PayoffPut(*this); // "this" is a pointer to the object calling the method
}

PayoffDoubleDigital::PayoffDoubleDigital(double lowerlevel_, double upperLevel_) : lowerLevel(lowerlevel_), upperLevel(upperLevel_){
    
}

double PayoffDoubleDigital::operator()(double spot) const{
    if (spot <= lowerLevel || spot >= upperLevel) {
        return 0;
    }
    return 1;
}
Payoff* PayoffDoubleDigital::clone() const {
    /*Payoff* ptr;
    ptr = new PayoffCall(*this);
    return ptr;*/
    return new PayoffDoubleDigital(*this); // "this" is a pointer to the object calling the method
}
