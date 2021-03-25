//
//  EuropeanVanilla.h
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#pragma once
#include <cmath>

class EuropeanVanilla
{
    const double mStrikePrice; // strike price of the option
    
    double PutPriceByBS(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility); // put price using black scholes
    
    double CallPriceByBS(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility); // call price using black scholes
    
public:
    
    EuropeanVanilla(const double StrikePrice): mStrikePrice(StrikePrice) {};
    
    void UpdateOptionPrice(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility); // update call/put price and greeks
    
    double CallPrice, PutPrice;
    
    double CDF(double x) const; // return cdf of standard normal distribution
    
    double DPlus(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) const; // d+ = (log(S0/K) + (r + sigmaˆ2) * T) / (sigma * sqrt(T))
    
};
