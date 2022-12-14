//
//  SimpleClaim.h
//  CEV
//
//  Created by Luca Begatti on 13/12/2022.
//

#ifndef SimpleClaim_h
#define SimpleClaim_h


#endif /* SimpleClaim_h */

#pragma once
#include <memory>
#include <algorithm>

class SimpleClaim{
public:
    virtual double getMat() const = 0;
    
    virtual void Payoff(double& Matprice,double& Payoff) const = 0;
    
    virtual std::unique_ptr<SimpleClaim> clone() const = 0;
    
    virtual ~SimpleClaim(){};
};

class EuropeanCall : public SimpleClaim{
private:
    double xMat;
    double xStrike;
public:
    
    EuropeanCall(const double Strike, const double Mat) : xMat(Mat), xStrike(Strike){}
    
    double getMat() const{
        return xMat;
    }
    void Payoff(double& Matprice,double& Payoff) const {
        Payoff = std::max<double>(Matprice - xStrike,0);
    }
    std::unique_ptr<SimpleClaim> clone() const{
        return std::make_unique<EuropeanCall>(*this);
    }
};
