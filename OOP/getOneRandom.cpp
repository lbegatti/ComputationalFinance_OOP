//
//  getOneRandom.cpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#include "getOneRandom.hpp"
#include <random>

double getOneUniform(){
    // return approximately a standard uniform variable U(0,1)
    return rand()/ (double) (RAND_MAX);

};

double getOneGaussianbyCLT(){
    double result = -6.0;
    for (int i = 0; i < 12; i++)
    {
        /* code */
        result += getOneUniform();
    }
    return result;
    

};
