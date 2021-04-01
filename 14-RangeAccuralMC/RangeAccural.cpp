//
//  RangeAccural.cpp
//  08-02 Range Accural MC
//
//  Created by Dayal on 01/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "RangeAccural.h"

double RangeAccural::MonteCarloPrice(const double S0, const double sigma, const double r, const unsigned int N, double &StandardError) const
{
    NormalRandomGenerator normal;
    Stats1 s;
    
    const double drift = (r - sigma * sigma / 2.0);
    
    for (unsigned int i = 1; i <= N; ++i) // number of simulations
    {
        double d = 0.0;
        double S = S0;
        for (unsigned int j = 1; j <= mD; ++j) // number of days
        {
            const double z = normal.generate();
            S *= exp(drift + sigma * z);
            if (mSmin <= S && S <= mSmax)
                ++d;
        }
        s.add(Payoff(d));
    }
    StandardError = exp(-r) * s.stDev() / sqrt(N - 1);
    return exp(-r) * s.mean();
}

double RangeAccural::Payoff(const double d) const
{
    return mM * d / mD;
}
