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

// helper function to create a Vanilla call
//VanillaOption makeAVanillaCall(double strike, double expiry){
//    PayoffCall callPayoff(strike);
//    //VanillaOption aVanilla(expiry,callPayoff);
//    //return aVanilla;
//    return VanillaOption(expiry,callPayoff); // not using the move copy constructor "return value optimization", so the compiler understands that this return values are temp objects
//                                            // does not implements the constructor
//}

//void moveSemanticsExample(){
//    double strike = 100.0;
//    double expiry = 1;
//    
//    // construct payoff objects
//    PayoffCall callPayoff(strike);
//    VanillaOption callOption(expiry,callPayoff);
//    
//    std::cout << "Move assignment example" << std::endl;
//    callOption= makeAVanillaCall(110, expiry); // the call option object is already existing (line 26) so here you are assigning it
//    
//    std::cout << "Move copy example" << std::endl;
//    VanillaOption newVanilla(makeAVanillaCall(110, expiry));
//    VanillaOption moreVanilla = makeAVanillaCall(110, expiry); // also here with the copy constructor because we are creating a new object.
//    
//    
//}

int main(){
    
    //moveSemanticsExample();

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
