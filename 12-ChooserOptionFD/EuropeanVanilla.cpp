//
//  EuropeanVanilla.cpp
//  European Option Pricer
//
//  Created by Dayal on 13/03/2021.
//  Copyright © 2021 Dayal. All rights reserved.
//

#include "EuropeanVanilla.h"

double EuropeanVanilla::CDF(double x) const // return cdf of standard normal distribution
{
    return erfc(-x / sqrt(2.0)) * 0.5;
}

double EuropeanVanilla::DPlus(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) const
{
    return (log(UnderlyingPrice / mStrikePrice) + (InterestRate + 0.5 * pow(Volatility,2.0)) * YearsToExpiry) /(Volatility * sqrt(YearsToExpiry));
}

void EuropeanVanilla::UpdateOptionPrice(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) // update call/put price and greeks
{
    CallPrice = CallPriceByBS(UnderlyingPrice, InterestRate, YearsToExpiry, Volatility);
    PutPrice = PutPriceByBS(UnderlyingPrice, InterestRate, YearsToExpiry, Volatility);
    return;
}

double EuropeanVanilla::PutPriceByBS(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) // put price using black scholes
{
    const double d1 = DPlus(UnderlyingPrice, InterestRate, YearsToExpiry, Volatility);
    const double d2 = d1 - Volatility * sqrt(YearsToExpiry);
    return mStrikePrice * exp(-InterestRate * YearsToExpiry) * CDF(-d2) - UnderlyingPrice * CDF(-d1);
}

double EuropeanVanilla::CallPriceByBS(const double UnderlyingPrice, const double InterestRate, const double YearsToExpiry, const double Volatility) // call price using black scholes
{
    const double d1 = DPlus(UnderlyingPrice, InterestRate, YearsToExpiry, Volatility);
    const double d2 = d1 - Volatility * sqrt(YearsToExpiry);
    return UnderlyingPrice * CDF(d1) - mStrikePrice * exp(-InterestRate * YearsToExpiry) * CDF(d2);
}
