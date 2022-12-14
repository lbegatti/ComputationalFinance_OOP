//
//  Model.cpp
//  CEV
//
//  Created by Luca Begatti on 13/12/2022.
//

#include <stdio.h>
#include "Model.h"
#include "Interpolate.h"
#include <cmath>


CEV::CEV(const double spot, const std::vector<double> Vols, const std::vector<double> Voltimes,
         const double Elasticity, const double Maxdt) : xSpot(spot), xVols(Vols),xVoltimes(Voltimes),xElasticity(Elasticity),xMaxdt(Maxdt) {}

void CEV::allocate(const double& Maturity){
    double timer = 0;
    while (timer - Maturity < 0.0) {
        xSteps.push_back(timer);
        timer += xMaxdt;
        
    }
    xSteps.push_back(Maturity); // creates a vector with the steps needed for the monte carlo, the timeline for the simulated stock path.
    xDim = xSteps.size() - 1; // number of normals needed.
    
    precalc1.resize(xDim);
    precalc2.resize(xDim);
}

void CEV::init(){
    for (size_t j = 0; j<xDim; j++) {
        const double dt = xSteps[j+1] - xSteps[j];
        
        const double Vol = LinearInterpolate(xVols, xVoltimes, xSteps[j]);
        
        precalc1[j] = -0.5 * Vol * Vol * dt;
        precalc2[j] = Vol * sqrt(dt);
        
    }
}

size_t CEV::getDim() const{
    return xDim;
}

void CEV::Path(std::vector<double>& Normals, double& Endprice) const {
    double  logSpot = log(xSpot);
    double twice;
    for (size_t i = 0; i<xDim; i++) {
        if (logSpot < -40) {
            break;
        }
        twice = exp(logSpot * (xElasticity - 1));
        
        logSpot += precalc1[i] * twice * twice + precalc2[i]*twice*Normals[i];
    }
    
    Endprice = exp(logSpot);
}

std::unique_ptr<Model> CEV::clone() const{
    return std::make_unique<CEV>(*this);
}
