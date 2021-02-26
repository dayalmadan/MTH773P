//
//  EurOption.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EurOption.hpp"

double EurOption::PDF(double x) const // probability density function
{
    const double PI = atan(1.0) * 4;
    return (1.0/sqrt(2.0 * PI)) * exp(-0.5 * x * x);
}

double EurOption::CDF(double x) const // return cdf of standard normal distribution
{
    return erfc(-x / sqrt(2.0)) / 2.0;
}

double EurOption::DPlus(const double S0, const double r, const double sigma, const double T) const
{
    return (log(S0 / mStrikePrice) + (r + 0.5 * pow(sigma,2.0)) * T) /(sigma * sqrt(T));
}

double EurOption::DMinus(const double S0, const double r, const double sigma, const double T) const
{
    return DPlus(S0, r, sigma, T) - sigma * sqrt(T);
}
