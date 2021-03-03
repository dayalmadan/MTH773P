//
//  VanillaOption.hpp
//  06-02 Trinomial Tree
//
//  Created by Dayal on 03/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <vector>
#include <cmath>

class VanillaOption
{
    const double mT; // years to expiry
    virtual double Payoff(double S) const = 0; // payoff function of different option types
    
protected:
    double CDF(double x) const; // return cdf of standard normal distribution
    double PDF(double x) const; // pdf of x
    double DPlus(const double S0, const double r, const double sigma, const double T, const double K) const;
    double DMinus(const double S0, const double r, const double sigma, const double T, const double K) const;
    
public:
    VanillaOption(double T) : mT(T) {};
    
    double TrinomialTreePrice(double S0, double sigma, double r, int N, double lambda) const; // price using trinomial tree
    
    double BinomialTreePrice(double S0, double sigma, double r, int N) const; // price using binomial tree
    
    virtual double PriceByBSFormula(const double S0, const double r, const double sigma, const double T) const = 0; // black scholes option pricing calculation
};
