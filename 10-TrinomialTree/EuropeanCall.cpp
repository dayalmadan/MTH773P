//
//  EuropeanCall.cpp
//  06-02 Trinomial Tree
//
//  Created by Dayal on 03/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EuropeanCall.hpp"

double EuropeanCall::Payoff(double S) const
{
    return fmax(S - mK, 0);
}

double EuropeanCall::PriceByBSFormula(const double S0, const double r, const double sigma, const double T) const // price a call option
{
    return S0 * CDF(DPlus(S0, r, sigma, T, mK)) - mK * exp (-r * T) * CDF(DMinus(S0, r, sigma, T, mK));
}
