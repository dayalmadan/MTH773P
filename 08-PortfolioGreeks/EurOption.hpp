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
    
    //const double YearsToExpiry, StrikePrice, StockPrice, Volatility, AnnualInterestRate;
    const double mStrikePrice;
    
    double CDF(double x) const; // return cdf of standard normal distribution
    double PDF(double x) const; // pdf of x
    double DPlus(const double S0, const double r, const double sigma, const double T) const;
    double DMinus(const double S0, const double r, const double sigma, const double T) const;
    
public:
    EurOption(const double StrikePrice) : mStrikePrice(StrikePrice) {};

    virtual double PriceByBSFormula(const double S0, const double r, const double sigma, const double T) const = 0; // black scholes option pricing calculation
    virtual double DeltaByBSFormula(const double S0, const double r, const double sigma, const double T) const = 0; // delta of option using BS
    virtual double GammaByBSFormula(const double S0, const double r, const double sigma, const double T) const = 0; // gamme using BS
    virtual double ThetaByBSFormula(const double S0, const double r, const double sigma, const double T) const = 0; // theta using BS
};
