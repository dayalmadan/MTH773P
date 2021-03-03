//
//  VanillaOption.cpp
//  06-02 Trinomial Tree
//
//  Created by Dayal on 03/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "VanillaOption.hpp"

double VanillaOption::TrinomialTreePrice(double S0, double sigma, double r, int N, double lambda) const
{
    const double h = mT / N;
    const double u = exp(lambda * sigma * sqrt(h));
    const double d = 1.0 / u;
    const double M = exp(r * h);
    const double V = exp(2 * r * h) * (exp(sigma * sigma * h) - 1);

    const double qu = ((V + M * M - M) * u - (M - 1)) / ((u - 1) * (u * u - 1));
    const double qd = (u * u * (V + M * M - M) - u * u * u * (M - 1)) / ((u - 1) * (u * u - 1));
    const double qnc = 1 - qu - qd;
    
    std::vector<double> v(2 * N + 1); // N up moves, N down moves, 1 no move
    int DownMoves = N;
    for (int i = 0; i <= 2 * N; ++i) // total number of terminal notes
    {
        const double ST = S0 * pow(d, DownMoves);
        v[i] = Payoff(ST);
        
        --DownMoves;
    }
    
    for (int n = N - 1; n >= 0; --n) // number of time steps
    {
        for (int i = 0; i <= 2 * n; ++i)
        {
            v[i] = (qu * v[i + 2] + qnc * v[i + 1] + qd * v[i]) / M;
        }
    }
    
    return v[0];
}

double VanillaOption::BinomialTreePrice(double S0, double sigma, double r, int N) const
{
    const double delta = mT / N;
    const double u = exp(sigma * sqrt(delta));
    const double d = 1.0 / u;
    const double R = exp(r * delta) - 1.0;

    const double qu = (1.0 + R - d) / (u - d);
    const double qd = 1.0 - qu;

    std::vector<double> v(N + 1);
    for (int i = 0; i <= N; ++i)
    {
        const double ST = S0 * pow(u, i) * pow(d, N - i);
        v[i] = Payoff(ST);
    }
    for (int n = N - 1; n >= 0; --n)
    {
        for (int i = 0; i <= n; ++i)
        {
            v[i] = (qu * v[i + 1] + qd * v[i]) / (1.0 + R);
        }
    }
    return v[0];
}

double VanillaOption::PDF(double x) const // probability density function
{
    const double PI = atan(1.0) * 4;
    return (1.0/sqrt(2.0 * PI)) * exp(-0.5 * x * x);
}

double VanillaOption::CDF(double x) const // return cdf of standard normal distribution
{
    return erfc(-x / sqrt(2.0)) / 2.0;
}

double VanillaOption::DPlus(const double S0, const double r, const double sigma, const double T, const double K) const
{
    return (log(S0 / K) + (r + 0.5 * pow(sigma,2.0)) * T) /(sigma * sqrt(T));
}

double VanillaOption::DMinus(const double S0, const double r, const double sigma, const double T, const double K) const
{
    return DPlus(S0, r, sigma, T, K) - sigma * sqrt(T);
}
