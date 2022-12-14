//
//  gaussians.cpp
//  CEV
//
//  Created by Luca Begatti on 11/12/2022.
//

#include "gaussians.hpp"
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

void fillNormalVector(std::vector<double>& Normals){
    for (auto& x : Normals) {
        x = getOneGaussianbyCLT();
    }
}
