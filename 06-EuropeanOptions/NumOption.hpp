//
//  NumOption.hpp
//  04-01 BS European Options
//
//  Created by Dayal on 16/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <cmath>

class NumOption
{
protected:
    
    double YearsToExpiry, StrikePrice, StockPrice, Volatility, AnnualInterestRate;
    
    double m, s, MaxPrice;
    void SetMeanAndStdev(); // set mean and standard deviation for GBM
    
    double LogNormalPDF(double x); // calculate pdf of lognormal distribution
    void SetMaxPrice(); // max price for which lognormal pdf is almost 0
    
public:
    NumOption();
    
    virtual double Payoff(double St) = 0; // calculate payoff of option
    virtual double PriceByApproximation(double StepSize) = 0; // calculate price of option by approximation
    
};
