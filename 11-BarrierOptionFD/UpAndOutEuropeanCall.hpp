//
//  UpAndOutEuropeanCall.hpp
//  05-01 Barrier Options
//
//  Created by Dayal on 26/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once
#include <cmath>
#include <vector>
#include <random>

using namespace std;

class UpAndOutEuropeanCall
{
    const double mStrikePrice, mBarrierPrice;
    
    double DPlus(const double x, const double r, const double sigma, const double T) const;
    
    double CDF(const double x) const; // return cdf of standard normal distribution
    
    double PayOff(const double SharePrice) const; // return payoff of barrier option
    
public:
    
    UpAndOutEuropeanCall(double StrikePrice, double BarrierPrice) : mStrikePrice(StrikePrice), mBarrierPrice(BarrierPrice) {};
    
    double BSAnalyticalPrice(const double SharePrice, const double YearsToExpiry, const double InterestRate, const double Volatility) const; // analytical formula for barrier up and out european call option
    double BinomialTreePrice(const double SharePrice, const double YearsToExpiry, const double InterestRate, const double Volatility, const int N) const; // price using binomial tree
    double FiniteDifferenceExplicit(const double SharePrice, const double YearsToExpiry, const double InterestRate, const double Volatility, const int Ns, const int Nt) const; // price using finite difference method (explicit method)
};
