//
//  ChooserOption.h
//  07-02 Chooser Option by FD
//
//  Created by Dayal on 25/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <vector>
#include "EuropeanVanilla.h"

using namespace std;

class ChooserOption: public EuropeanVanilla
{
    const double mStrikePrice;
    
    double YPlus(const double S0, const double r, const double T, const double sigma, const double Tc) const;
    
public:
    
    ChooserOption(const double StrikePrice): mStrikePrice(StrikePrice), EuropeanVanilla(StrikePrice) {};
    
    double BSAnalyticalPrice(const double S0, const double r, const double T, const double sigma, const double Tc) const; // analytical price using formula
    
    double FiniteDifferenceExplicit(const double S0, const double r, const double T, const double sigma, const double Tc, const int Ns, const int Nt); // price using Explicit finite difference method
};
