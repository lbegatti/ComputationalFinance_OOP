//
//  Model.h
//  CEV
//
//  Created by Luca Begatti on 13/12/2022.
//

#ifndef Model_h
#define Model_h


#endif /* Model_h */

#pragma once
#include <vector>
#include <memory>

class Model {
public:
    virtual void allocate(const double& Maturity) = 0; // allocate the model
    
    virtual void init() = 0;
    
    virtual size_t getDim() const = 0;
    virtual void Path(std::vector<double>& Normals,double& Endprice) const = 0;
    
    virtual std::unique_ptr<Model> clone() const = 0;
    
    virtual ~Model(){};
    
    
};

class CEV : public Model{
public:
    CEV(const double spot, const std::vector<double> Vols, const std::vector<double> Voltimes, const double Elasticity, const double Maxdt);
    
    void allocate(const double& Maturity);
    void init();
    size_t getDim() const;
    void Path(std::vector<double>& Normals,double& Endprice) const;
    std::unique_ptr<Model> clone() const;
    
private:
    double xSpot;
    double xElasticity;
    
    std::vector<double> xVols;
    std::vector<double> xVoltimes;
    
    std::vector<double> precalc1;
    std::vector<double> precalc2;
    
    std::vector<double> xSteps;
    size_t xDim;
    
    double  xMaxdt;
};
