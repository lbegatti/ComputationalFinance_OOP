//
//  Statistics.h
//  CEV
//
//  Created by Luca Begatti on 13/12/2022.
//

#ifndef Statistics_h
#define Statistics_h


#endif /* Statistics_h */

#pragma once
#include "myMC.h"
#include <algorithm>
#include <numeric>

inline double MCValue(const Model& Mod, const SimpleClaim& Prod, const size_t nPath, const int seed = 1){
    srand(seed);
    std::vector<double> MyPayoffs;
    MyPayoffs = myMC(Mod,Prod,nPath);
    
    return std::accumulate(MyPayoffs.begin(), MyPayoffs.end(),0.0)/(double)(nPath);
}
