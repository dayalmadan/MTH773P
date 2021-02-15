//
//  EurCall.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "EurCall.hpp"

EurCall::EurCall(double S0, double K, double T, double Sigma, double r) // constructor to set private variables
{
    StockPrice = S0;
    StrikePrice = K;
    YearsToExpiry = T;
    Volatility = Sigma;
    AnnualInterestRate = r;
}

double EurCall::PriceByBSFormula() // price a call option
{
    return StockPrice * CDF(DPlus()) - StrikePrice * exp (-AnnualInterestRate * YearsToExpiry) * CDF(DMinus());
}

double EurCall::DeltaByBSFormula() // delta of call option
{
    return CDF(DPlus());
}

double EurCall::GammaByBSFormula() // gamme of call option
{
    return PDF(DPlus()) / (StockPrice * Volatility * sqrt(YearsToExpiry));
}

double EurCall::ThetaByBSFormula() // theta of call option
{
    return -StockPrice * PDF(DPlus()) * Volatility / (2 * sqrt(YearsToExpiry)) - AnnualInterestRate * StrikePrice * exp(-AnnualInterestRate * YearsToExpiry) * CDF(DMinus());
}
