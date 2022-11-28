//
//  simpleMC.hpp
//  OOP
//
//  Created by Luca Begatti on 24/11/2022.
//

#ifndef simpleMC_hpp
#define simpleMC_hpp

#include <stdio.h>

#endif /* simpleMC_hpp */

#pragma once
#include "Payoff.hpp"
#include "Vanilla.hpp"

double simpleMC(const VanillaOption& theOption,
                double spot,
                double sigma,
                double r,
                int numberOfPaths);
