//
//  NumPut.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 16/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "NumPut.hpp"

NumPut::NumPut(double S0, double K, double T, double Sigma, double r) // constructor to set private variables
{
    StockPrice = S0;
    StrikePrice = K;
    YearsToExpiry = T;
    Volatility = Sigma;
    AnnualInterestRate = r;
    
    SetMeanAndStdev();
}

double NumPut::Payoff(double St) // calculate payoff of put option
{
    return fmax(StrikePrice - St, 0);
}

double NumPut::PriceByApproximation(double StepSize) // aprroximate price of put option using trapezium method
{
    double LowerPrice = 0.05; // assuming minimum stock price can be 0.05
    double UpperPrice = LowerPrice + StepSize;
    double PutPrice = 0;
    while (LowerPrice <= StrikePrice) // put option is worthless above strike price
    {
        PutPrice += (Payoff(LowerPrice) * LogNormalPDF(LowerPrice) + Payoff(UpperPrice) * LogNormalPDF(UpperPrice)) * StepSize / 2.0;
        LowerPrice = UpperPrice;
        UpperPrice += StepSize;
    }
    return PutPrice * exp(-AnnualInterestRate * YearsToExpiry); // discounted put price
}
