//
//  main.cpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#include <iostream>
#include <random>
#include "Payoff.hpp"
#include "simpleMC.hpp"

int main(){

    // initialize data
    double expiry = 1.0;
    double strike = 100.0;
    double spot = 100.0;
    double sigma = 0.1;
    double r = 0.04;
    double lowerLevel = 90;
    double upperLevel = 110;

    int numberOfPaths = 10000;

    srand(1); // sets the seed

    // construct payoff objects
    PayoffCall callPayoff(strike);
    VanillaOption callOption(expiry,callPayoff);

    PayoffPut putPayoff(strike);
    VanillaOption putOption(expiry,putPayoff);

    PayoffDoubleDigital DoubleDigitalPayoff(lowerLevel,upperLevel);
    VanillaOption doubleDigitalOption(expiry,DoubleDigitalPayoff);

    double resultCall = simpleMC(callOption,spot,sigma,r,numberOfPaths);
    double resultPut = simpleMC(putOption,spot,sigma,r,numberOfPaths);
    double resultDoubleDigital = simpleMC(doubleDigitalOption,spot,sigma,r,numberOfPaths);

    std::cout << "The call price is " << resultCall << std::endl;
    std::cout << "The put price is " << resultPut << std::endl;
    std::cout << "The double digital price is " << resultDoubleDigital << std::endl;

}
