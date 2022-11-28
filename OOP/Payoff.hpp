//
//  Payoff.hpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#ifndef Payoff_hpp
#define Payoff_hpp

#include <stdio.h>

#endif /* Payoff_hpp */

#pragma once

class Payoff{ // abstract class
public:
    // virtual means it can be implemented in derived classes
    // =0 means it HAS to be implemented in derived classes
    virtual double operator()(double spot) const = 0; // has to be implemented
    virtual ~Payoff(){} // virtual destructor. Needed when derived classes are deleted as base class
    virtual Payoff* clone() const=0;
    
    // no constructor here! it is an abstract class
};

class PayoffCall : public Payoff // inherits from Payoff class. Gets field variables and methods.
{
public:
    PayoffCall(double strike); // call option constructor
    double operator()(double spot) const; // evaluate payoff
    ~PayoffCall(){}
    Payoff* clone() const;
private:
    const double strike;
};

class PayoffPut : public Payoff // inherits from Payoff class. Gets field variables and methods.
{
public:
    PayoffPut(double strike); // call option constructor
    double operator()(double spot) const; // evaluate payoff
    ~PayoffPut(){}
    Payoff* clone() const;
private:
    const double strike;
};

class PayoffDoubleDigital : public Payoff // inherits from Payoff class. Gets field variables and methods.
{
public:
    PayoffDoubleDigital(double lowerLevel, double upperLevel); // call option constructor
    double operator()(double spot) const; // evaluate payoff
    ~PayoffDoubleDigital(){}
    Payoff* clone() const;
private:
    const double lowerLevel;
    const double upperLevel;
};
