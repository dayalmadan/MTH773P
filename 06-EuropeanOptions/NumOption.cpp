//
//  NumOption.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 16/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "NumOption.hpp"

NumOption::NumOption()
{
    
}

void NumOption::SetMeanAndStdev() // set mean and standard deviation for GBM
{
    m = log(StockPrice) + (AnnualInterestRate - pow(Volatility, 2) / 2) * YearsToExpiry;
    s = Volatility * sqrt(YearsToExpiry);
    return;
}

double NumOption::LogNormalPDF(double x) // calculate pdf of lognormal distribution
{
    if (x <= 0.0) // Fx is only defined for x > 0
        return 0;
    const double PI = atan(1.0) * 4;
    return (1.0 / (x * s * sqrt(2 * PI))) * exp(-pow(log(x) - m, 2) / (2 * s * s));
    return 0;
}

void NumOption::SetMaxPrice() // max price for which lognormal pdf is almost 0
{
    MaxPrice = StockPrice;
    while(true)
    {
        if (LogNormalPDF(MaxPrice) < 0.00000001)
            break;
        ++MaxPrice;
    }
    return;
}
