//
//  NumCall.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 16/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "NumCall.hpp"

NumCall::NumCall(double S0, double K, double T, double Sigma, double r) // constructor to set private variables
{
    StockPrice = S0;
    StrikePrice = K;
    YearsToExpiry = T;
    Volatility = Sigma;
    AnnualInterestRate = r;
    
    SetMeanAndStdev();
}

double NumCall::Payoff(double St) // calculate payoff of call option
{
    return fmax(St - StrikePrice, 0);
}

double NumCall::PriceByApproximation(double StepSize) // aprroximate price of call option using trapezium method
{
    SetMaxPrice();
    double LowerPrice = StrikePrice; // call option is worthless below strike price
    double UpperPrice = StrikePrice + StepSize;
    double CallPrice = 0;
    while (LowerPrice <= MaxPrice)
    {
        CallPrice += (Payoff(LowerPrice) * LogNormalPDF(LowerPrice) + Payoff(UpperPrice) * LogNormalPDF(UpperPrice)) * StepSize / 2.0;
        LowerPrice = UpperPrice;
        UpperPrice += StepSize;
    }
    return CallPrice * exp(-AnnualInterestRate * YearsToExpiry); // discounted call price
}
