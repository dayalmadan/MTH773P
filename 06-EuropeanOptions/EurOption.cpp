//
//  EurOption.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EurOption.hpp"

EurOption::EurOption()
{
    
}

double EurOption::PDF(double x) // probability density function
{
    const double PI = atan(1.0)*4;
    return (1.0/sqrt(2.0 * PI)) * exp(-0.5 * x * x);
}

double EurOption::CDF(double x) // return cdf of standard normal distribution
{
    return erfc(-x / sqrt(2.0)) / 2.0;
}

double EurOption::DPlus()
{
    return (log(StockPrice / StrikePrice) + (AnnualInterestRate + 0.5 * pow(Volatility,2.0)) * YearsToExpiry) /(Volatility * sqrt(YearsToExpiry));
}

double EurOption::DMinus()
{
    return DPlus() - Volatility * sqrt(YearsToExpiry);
}
