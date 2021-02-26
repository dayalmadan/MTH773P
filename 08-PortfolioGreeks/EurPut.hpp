//
//  EurPut.hpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include "EurOption.hpp"

class EurPut: public EurOption
{
public:
    EurPut(double K) : EurOption(K) {}; // constructor to set private variables
    double PriceByBSFormula(const double S0, const double r, const double sigma, const double T) const; // price a put option
    double DeltaByBSFormula(const double S0, const double r, const double sigma, const double T) const; // delta of put option
    double GammaByBSFormula(const double S0, const double r, const double sigma, const double T) const; // gamme of put option
    double ThetaByBSFormula(const double S0, const double r, const double sigma, const double T) const; // theta of put option
    
    
};
