//
//  EuropeanCall.cpp
//  09-01 Heston Model
//
//  Created by Dayal on 02/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EuropeanCall.h"

double EuropeanCall::MonteCarloPrice(const double S0, const double r, const double T, const double a, const double vbar, const double eta, const double v0, const double rho, const unsigned int N, double &StandardError) const // call option price of heston model using monte carlo
{
    NormalRandomGenerator normal;
    Stats1 s;
    
    const double dt = 1 / 365.0;
    
    const double TimeSteps = T * 365.0;
    
    for (unsigned int i = 1; i <= N; ++i) // number of simulations
    {
        double S = S0;
        double v = v0;
        for (unsigned int j = 1; j <= TimeSteps; ++j) // number of days
        {
            const double z1 = normal.generate();
            const double z2 = rho * z1 + sqrt(1 - rho * rho) * normal.generate();
            S *= exp((r - v / 2) * dt + sqrt(v * dt) * z1);
            v = pow(sqrt(v) + eta * sqrt(dt) * z2 / 2, 2) - a * (v - vbar) * dt - eta * eta * dt / 4;
        }
        s.add(Payoff(S));
    }
    StandardError = exp(-r) * s.stDev() / sqrt(N - 1);
    return exp(-r) * s.mean();
}

double EuropeanCall::ImpliedVolatility(const double S0, const double r, const double T, const double CallPrice) const // calculate implied volatility of call option using bisection solver
{
    const double Accuracy = 1e-6; // upto 6 decimal places
    
// lower and upper bounds of implied volatility
    double left = 0.0;
    double right = 2.0;
    
    double fl = CallPriceByBS(S0, r, T, left);
    if (CallPrice < fl)
        return Accuracy;
    double fr = CallPriceByBS(S0, r, T, right);
    //cout << fl << " " << fr << endl;
    while (true)
    {
        const double mid = (left + right) / 2.0;
        if (right - left <= Accuracy)
            return mid;
        const double fm = CallPriceByBS(S0, r, T, mid);
        //cout << fm << endl;
        if ((fl <= CallPrice && CallPrice <= fm) || (fm <= CallPrice && CallPrice <= fl))
        {
            right = mid;
            fr = fm;
        }
        else
        {
            left = mid;
            fl = fm;
        }
    }
    
    return 0.0;
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
