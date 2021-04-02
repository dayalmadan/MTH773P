//
//  EuropeanCall.h
//  09-01 Heston Model
//
//  Created by Dayal on 02/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <cmath>
#include <random>
#include "NormalRandomGenerator.h"
#include "Stats1.h"

class EuropeanCall
{
    const double mStrikePrice;
    
    double Payoff(const double S) const;
    
    double CDF(double x) const; // return cdf of standard normal distribution
    
    double DPlus(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) const; // d+ = (log(S0/K) + (r + sigmaˆ2) * T) / (sigma * sqrt(T))
    
public:
    EuropeanCall(const double StrikePrice): mStrikePrice(StrikePrice) {};
    
    double MonteCarloPrice(const double S0, const double r, const double T, const double a, const double vbar, const double eta, const double v0, const double rho, const unsigned int N, double &StandardError) const; // call option price of heston model using monte carlo
    
    double ImpliedVolatility(const double S0, const double r, const double T, const double CallPrice) const; // calculate implied volatility of call option using bisection solver
    
    double CallPriceByBS(const double S0, const double r, const double T, const double sigma) const; // call price using black scholes
};
