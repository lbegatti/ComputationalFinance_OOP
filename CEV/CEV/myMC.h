//
//  myMC.h
//  CEV
//
//  Created by Luca Begatti on 13/12/2022.
//

#ifndef myMC_h
#define myMC_h


#endif /* myMC_h */
#pragma once
#include "Model.h"
#include "SimpleClaim.h"
#include "gaussians.hpp"

inline std::vector<double> myMC(const Model& Mod, const SimpleClaim& Prod, const size_t nPath){
    auto NewMod = Mod.clone();
    NewMod -> allocate(Prod.getMat());
    NewMod -> init();
    
    std::vector<double> Normals(NewMod -> getDim());
    
    double MatPrice;
    
    std::vector<double> Payoffs(nPath);
    
    for (size_t i = 0; i<nPath; i++) {
        fillNormalVector(Normals);
        NewMod -> Path(Normals,MatPrice);
        Prod.Payoff(MatPrice,Payoffs[i]);
    }
    return Payoffs;
    
    
}
