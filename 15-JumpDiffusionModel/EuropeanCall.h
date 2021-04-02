//
//  EuropeanCall.h
//  09-01 Heston Model
//
//  Created by Dayal on 02/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <cmath>

class EuropeanCall
{
    const double mStrikePrice;
    
    double Payoff(const double S) const;
    
    double CDF(double x) const; // return cdf of standard normal distribution
    
    double DPlus(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) const; // d+ = (log(S0/K) + (r + sigmaˆ2) * T) / (sigma * sqrt(T))
    
public:
    EuropeanCall(const double StrikePrice): mStrikePrice(StrikePrice) {};
    
    double JumpDiffusionPrice(const double S0, const double r, const double sigma, const double lambda, const double m, const double s, const double T) const; // call option price using jump diffusion model
    
    double CallPriceByBS(const double S0, const double r, const double T, const double sigma) const; // call price using black scholes
};
