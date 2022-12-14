//
//  main.cpp
//  CEV
//
//  Created by Luca Begatti on 11/12/2022.
//

#include <iostream>
#include "Statistics.h"

int main(){
    const double expiry = 1;
    const double spot = 100;
    const double elas = 0.9;
    const double strike = 100;
    const double maxdt = 1/(double)52;
    const size_t Paths = 10000;
    
    std::vector<double> times={0.25,0.5,0.75};
    std::vector<double> vols = {0.5,0.2,0.4,0.3};
    
    EuropeanCall aCall(strike,expiry);
    CEV aCEV(spot,vols,times,elas,maxdt);
    
    double value = MCValue(aCEV, aCall, Paths);
    
    std::cout<<value<<std::endl;
}
