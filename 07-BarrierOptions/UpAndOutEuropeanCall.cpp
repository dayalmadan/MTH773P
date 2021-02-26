//
//  UpAndOutEuropeanCall.cpp
//  05-01 Barrier Options
//
//  Created by Dayal on 26/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "UpAndOutEuropeanCall.hpp"

double UpAndOutEuropeanCall::BSAnalyticalPrice(const double SharePrice, const double YearsToExpiry, const double InterestRate, const double Volatility) const // analytical formula for barrier up and out european call option
{
    const double SigmaRootT = Volatility * sqrt(YearsToExpiry);
    const double d1 = DPlus(SharePrice / mStrikePrice, InterestRate, Volatility, YearsToExpiry);
    const double d2 = d1 - SigmaRootT;
    const double d3 = DPlus(SharePrice / mBarrierPrice, InterestRate, Volatility, YearsToExpiry);
    const double d4 = d3 - SigmaRootT;
    const double d5 = DPlus(SharePrice / mBarrierPrice, -InterestRate, Volatility, YearsToExpiry);
    const double d6 = d5 - SigmaRootT;
    const double d7 = DPlus(SharePrice * mStrikePrice / pow(mBarrierPrice, 2), -InterestRate, Volatility, YearsToExpiry);
    const double d8 = d7 - SigmaRootT;
    double OptionPrice =  SharePrice * (CDF(d1) - CDF(d3) - pow(mBarrierPrice / SharePrice, 1 + 2 * InterestRate / pow(Volatility, 2)) * (CDF(d6) - CDF(d8)));
    OptionPrice -= mStrikePrice * exp(-InterestRate * YearsToExpiry) * (CDF(d2) - CDF(d4) - pow(mBarrierPrice / SharePrice, -1 + 2 * InterestRate / pow(Volatility, 2)) * (CDF(d5) - CDF(d7)));
    return OptionPrice;
}

double UpAndOutEuropeanCall::BinomialTreePrice(const double SharePrice, const double YearsToExpiry, const double InterestRate, const double Volatility, const int N) const // price using binomial tree
{
    const double StepSize = YearsToExpiry / N;
    const double u = exp((InterestRate - pow(Volatility, 2) / 2) * StepSize + Volatility * sqrt(StepSize));
    const double d = exp((InterestRate - pow(Volatility, 2) / 2) * StepSize - Volatility * sqrt(StepSize));
    const double StepGrowth = exp(InterestRate * StepSize); // growth in one step = 1 + R
    const double qu = (StepGrowth - d) / (u - d);
    const double qd = 1.0 - qu;
    vector <double> V(N + 1);
    for (int i = 0; i <= N; ++i) // terminal nodes of the tree
    {
        const double ST = SharePrice * pow(u, i) * pow(d, N - i);
        V[i] = PayOff(ST);
    }
    for (int n = N - 1; n >= 0; --n) // recursive backtracking of the tree
    {
        for (int i = 0; i <= n; ++i) // calculate value at each node
        {
            const double St = SharePrice * pow(u, i) * pow(d, n - i);
            V[i] = St >= mBarrierPrice ? 0 : (qu * V[i + 1] + qd * V[i]) / StepGrowth;
        }
    }
    return V[0];
}

double UpAndOutEuropeanCall::DPlus(const double x, const double r, const double sigma, const double T) const
{
    return (log(x) + (r + pow(sigma, 2) / 2) * T) / (sigma * sqrt(T));
}

double UpAndOutEuropeanCall::CDF(const double x) const // return cdf of standard normal distribution
{
    return erfc(-x / sqrt(2.0)) / 2.0;
}

double UpAndOutEuropeanCall::PayOff(const double SharePrice) const // return payoff of barrier option
{
    return fmax(SharePrice - mStrikePrice, 0);
}
