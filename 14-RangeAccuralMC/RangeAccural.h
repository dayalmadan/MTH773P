//
//  RangeAccural.h
//  08-02 Range Accural MC
//
//  Created by Dayal on 01/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <cmath>
#include "Stats1.h"
#include "NormalRandomGenerator.h"

class RangeAccural
{
    const double mM, mSmin, mSmax, mD;
    double Payoff(const double d) const;
public:
    
    RangeAccural(const double M, const double Smin, const double Smax, const double D): mM(M), mSmin(Smin), mSmax(Smax), mD(D) {};
    double MonteCarloPrice(const double S0, const double sigma, const double r, const unsigned int N, double &StandardError) const;
};
