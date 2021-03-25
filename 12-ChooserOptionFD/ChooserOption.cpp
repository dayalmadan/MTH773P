//
//  ChooserOption.cpp
//  07-02 Chooser Option by FD
//
//  Created by Dayal on 25/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "ChooserOption.h"

double ChooserOption::BSAnalyticalPrice(const double S0, const double r, const double T, const double sigma, const double Tc) const // analytical price using formula
{
    double Price = S0 * CDF(DPlus(S0, r, T, sigma)) - mStrikePrice * exp(-r * T) * CDF(DPlus(S0, r, T, sigma) - sigma * sqrt(T));
    Price -= S0 * CDF(-YPlus(S0, r, T, sigma, Tc));
    Price += mStrikePrice * exp(-r * T) * CDF(-YPlus(S0, r, T, sigma, Tc) + sigma * sqrt(Tc));
    return Price;
}

double ChooserOption::FiniteDifferenceExplicit(const double S0, const double r, const double T, const double sigma, const double Tc, const int Ns, const int Nt) // price using Explicit finite difference method
{
    const double S_max = S0 * 2;
    const double S_min = 0;
        
    const double dt = Tc / Nt;
    const double dS = (S_max - S_min) / Ns;
        
    vector<double> V(Ns + 1);
        
    double S = S_min;
        
    // set terminal payoff
    for (int i = 0; i <= Ns; ++i)
    {
        UpdateOptionPrice(S, r, T - Tc, sigma);
        V[i] = max(CallPrice, PutPrice);
            
        S += dS;
    }
    
    double t = Tc;
    
    for (int i = Nt - 1; i >= 0; --i)
    {
        vector<double> U(Ns + 1);
        S = S_min;
        for (int j = 1; j < Ns; ++j)
        {
            S += dS;
            // barrier option satisfy black scholes PDE
            const double a = -sigma * sigma * S * S / 2.0;
            const double b = -r * S;
            const double c = r;
                
            const double A = dt / dS * (b / 2.0 - a / dS);
            const double B = 1.0 - dt * c + 2.0 * dt * a / dS / dS;
            const double C = -dt / dS * (b / 2.0 + a / dS);
                
            U[j] = A * V[j - 1] + B * V[j] + C * V[j + 1];
        }
        t -= dt;
        
    // Boundary conditions
        UpdateOptionPrice(S_min, r, T - Tc, sigma);
        U[0] = max(CallPrice, PutPrice) * exp(-r * (Tc - t));
        UpdateOptionPrice(S_max, r, T - Tc, sigma);
        U[Ns] = max(CallPrice, PutPrice) * exp(-r * (Tc - t));
            
        V = U;
    }
    const int left = floor(S0 - S_min) / dS;
    const double w = (S0 - (S_min + left * dS)) / dS;
        
    const double price = V[left] * (1.0 - w) + V[left + 1] * w;
    
    return price;
}

double ChooserOption::YPlus(const double S0, const double r, const double T, const double sigma, const double Tc) const
{
    return (log(S0 / mStrikePrice) + r * T + pow(sigma, 2) * Tc / 2) / (sigma * sqrt(Tc));
}
