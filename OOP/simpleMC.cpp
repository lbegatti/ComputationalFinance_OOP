//
//  simpleMC.cpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#include "simpleMC.hpp"
#include <cmath>
#include "getOneRandom.hpp"


double simpleMC(const VanillaOption& theOption,double spot,double sigma,double r, int numberOfPaths){
        // "pass by reference" -> the & tells the compiler to use the reference of Payoff, so no copy anymore
    // calculation outside the loop, as they are not stochastic
    double variance = sigma * sigma * theOption.getExpiry();
    double vol = sqrt(variance);
    double movedSpot = spot * exp(r*theOption.getExpiry() - 0.5 * variance);

    double runningSum = 0.0;

    for (int i = 0; i < numberOfPaths; i++)
    {
        /* code */
        double thisSpot = movedSpot * exp(vol*getOneGaussianbyCLT());
        double thisPayoff = theOption.optionPayoff(thisSpot); // here where we use our class
        
        runningSum += thisPayoff;
    }
    return exp(-r * theOption.getExpiry())*runningSum/numberOfPaths;
    };
