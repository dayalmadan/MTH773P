//
//  EuropeanPut.cpp
//  06-02 Trinomial Tree
//
//  Created by Dayal on 03/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EuropeanPut.hpp"

double EuropeanPut::Payoff(double S) const
{
    return fmax(mK - S, 0);
}

double EuropeanPut::PriceByBSFormula(const double S0, const double r, const double sigma, const double T) const // price a call option
{
    return mK * exp (-r * T) * CDF(-DMinus(S0, r, sigma, T, mK)) - S0 * CDF(-DPlus(S0, r, sigma, T, mK));
}
