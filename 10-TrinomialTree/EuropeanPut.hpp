//
//  EuropeanPut.hpp
//  06-02 Trinomial Tree
//
//  Created by Dayal on 03/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include "VanillaOption.hpp"

class EuropeanPut: public VanillaOption
{
    double Payoff(double S) const;
        
    const double mK; // strike Price
        
public:
    EuropeanPut(double K, double T) : VanillaOption(T), mK(K) {};
    
    double PriceByBSFormula(const double S0, const double r, const double sigma, const double T) const; // price a call option
};
