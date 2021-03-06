//
//  EurPut.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EurPut.hpp"

double EurPut::PriceByBSFormula(const double S0, const double r, const double sigma, const double T) const // price a call option
{
    return mStrikePrice * exp (-r * T) * CDF(-DMinus(S0, r, sigma, T)) - S0 * CDF(-DPlus(S0, r, sigma, T));
}

double EurPut::DeltaByBSFormula(const double S0, const double r, const double sigma, const double T) const // delta of call option
{
    return -CDF(-DPlus(S0, r, sigma, T));
}

double EurPut::GammaByBSFormula(const double S0, const double r, const double sigma, const double T) const // gamme of call option
{
    return PDF(DPlus(S0, r, sigma, T)) / (S0 * sigma * sqrt(T));
}

double EurPut::ThetaByBSFormula(const double S0, const double r, const double sigma, const double T) const // theta of call option
{
    return -S0 * PDF(-DPlus(S0, r, sigma, T)) * sigma / (2 * sqrt(T)) + r * mStrikePrice * exp(-r * T) * CDF(-DMinus(S0, r, sigma, T));
}
