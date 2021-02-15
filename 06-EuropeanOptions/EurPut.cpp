//
//  EurPut.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EurPut.hpp"

EurPut::EurPut(double S0, double K, double T, double Sigma, double r) // constructor to set private variables
{
    StockPrice = S0;
    StrikePrice = K;
    YearsToExpiry = T;
    Volatility = Sigma;
    AnnualInterestRate = r;
}

double EurPut::PriceByBSFormula() // price a call option
{
    return StrikePrice * exp (-AnnualInterestRate * YearsToExpiry) * CDF(-DMinus()) - StockPrice * CDF(-DPlus());
}

double EurPut::DeltaByBSFormula() // delta of call option
{
    return CDF(-DPlus());
}

double EurPut::GammaByBSFormula() // gamme of call option
{
    return PDF(DPlus()) / (StockPrice * Volatility * sqrt(YearsToExpiry));
}

double EurPut::ThetaByBSFormula() // theta of call option
{
    return -StockPrice * PDF(-DPlus()) * Volatility / (2 * sqrt(YearsToExpiry)) + AnnualInterestRate * StrikePrice * exp(-AnnualInterestRate * YearsToExpiry) * CDF(-DMinus());
}
