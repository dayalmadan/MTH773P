//
//  EurOption.hpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <cmath>

class EurOption
{
protected:
    
    double YearsToExpiry, StrikePrice, StockPrice, Volatility, AnnualInterestRate;
    
    double CDF(double x); // return cdf of standard normal distribution
    double PDF(double x); // pdf of x
    double DPlus();
    double DMinus();
    
public:
    EurOption();

    virtual double PriceByBSFormula() = 0; // black scholes option pricing calculation
    virtual double DeltaByBSFormula() = 0; // delta of option using BS
    virtual double GammaByBSFormula() = 0; // gamme using BS
    virtual double ThetaByBSFormula() = 0; // theta using BS
};
