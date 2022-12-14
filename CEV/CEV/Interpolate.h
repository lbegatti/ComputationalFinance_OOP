//
//  Interpolate.h
//  CEV
//
//  Created by Luca Begatti on 13/12/2022.
//

#ifndef Interpolate_h
#define Interpolate_h


#endif /* Interpolate_h */

#pragma once
#include <algorithm>
#include <vector>

inline double LinearInterpolate(const std::vector<double> Vols,const std::vector<double> Voltimes,const double& point){
    // iterators
    
    // std::vector<double>::iterator
    auto it = upper_bound(Voltimes.begin(),Voltimes.end(),point);
    
    if (it == Voltimes.end()) {
        return *(Vols.end() - 1); //end() gives the point after the last so if you want the last one you need end()-1
    }
    if (it == Voltimes.begin()) {
        return *(Vols.begin());
    }
    
    size_t index = std::distance(Voltimes.begin(),it);
    
    double vol1 = Vols[index -1];
    double vol2 = Vols[index];
    double t1 = Voltimes[index -1];
    double t2 = Voltimes[index];
    
    double val = vol1 + (point - t1)*(vol2 - vol1)/(t2 - t1);
    
    return val;
};
