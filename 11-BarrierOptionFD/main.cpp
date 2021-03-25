//
//  main.cpp
//  07-01 Barrier Options by FD
//
//  Created by Dayal on 23/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "UpAndOutEuropeanCall.hpp"

int main()
{
    const double K = 100, B = 130, T = 1, S0 = 98, r = 0.05, sigma = 0.2;
    UpAndOutEuropeanCall barrier (K, B);
    
    cout << "Finite Difference (Explicit): " << barrier.FiniteDifferenceExplicit(S0, T, r, sigma, 80, 6400) << endl;
    
    cout << "Black Scholes: " << barrier.BSAnalyticalPrice(S0, T, r, sigma) << endl;
    
    cout << "Binomial Tree: " << barrier.BinomialTreePrice(S0, T, r, sigma, 1000) << endl;
    
    return 0;
}
