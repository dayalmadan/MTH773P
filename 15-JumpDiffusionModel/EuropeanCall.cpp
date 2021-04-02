//
//  EuropeanCall.cpp
//  09-01 Heston Model
//
//  Created by Dayal on 02/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EuropeanCall.h"
#include <iostream>

using namespace std;

double EuropeanCall::JumpDiffusionPrice(const double S0, const double r, const double sigma, const double lambda, const double m, const double s, const double T) const // call option price of heston model using monte carlo
{
    double Price = 0.0;
    const double k = exp(m + s * s * 0.5) - 1;
    const double lambda_hat = lambda * (1 + k);
    
    for (int n = 0; ; ++n) // infinite loop till sigma_n >= 1
    {
        const double sigma_n = sqrt(sigma * sigma + n * s * s / T);
        const double r_n = r - lambda * k + n * log(1 + k) / T;
        double SummationValue = CallPriceByBS(S0, r_n, T, sigma_n);
        
        for (int i = 2; i <= n; ++i) // divide by factorial
            SummationValue /= i;
        
        SummationValue *= exp(-lambda_hat * T) * pow(lambda_hat * T, n);
        cout << n << " " << SummationValue << " " << sigma_n << endl;
        Price += SummationValue;
        if (sigma_n >= 1.0)
            break;
    }
    return Price;
}

double EuropeanCall::CallPriceByBS(const double S0, const double r, const double T, const double sigma) const // call price using black scholes
{
    const double d1 = DPlus(S0, r, T, sigma);
    const double d2 = d1 - sigma * sqrt(T);
    return S0 * CDF(d1) - mStrikePrice * exp(-r * T) * CDF(d2);
}

double EuropeanCall::Payoff(const double S) const
{
    return (S > mStrikePrice)? S - mStrikePrice: 0.0;
}

double EuropeanCall::CDF(double x) const // return cdf of standard normal distribution
{
    return erfc(-x / sqrt(2.0)) * 0.5;
}

double EuropeanCall::DPlus(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) const
{
    return (log(UnderlyingPrice / mStrikePrice) + (InterestRate + 0.5 * pow(Volatility,2.0)) * YearsToExpiry) /(Volatility * sqrt(YearsToExpiry));
}
