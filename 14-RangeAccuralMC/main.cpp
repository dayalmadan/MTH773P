//
//  main.cpp
//  08-02 Range Accural MC
//
//  Created by Dayal on 01/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "RangeAccural.h"

using namespace std;

int main()
{
    const double Smin = 100, Smax = 110, M = 1000000, D = 252;
    const double S0 = 105, sigma = 0.25, r = 0.05;
    
    const RangeAccural accural(M, Smin, Smax, D);
    double StandardError;
    const double Price = accural.MonteCarloPrice(S0, sigma, r, 1000, StandardError);
    StandardError = StandardError * 100 / Price;
    cout << "Price: " << Price << ", SE: " << StandardError << endl;
    
    unsigned int N = 0;
    StandardError = 1;
    const double TargetStandardError = 0.1; // %
    while (StandardError > TargetStandardError)
    {
        N += 100000;
        const double Price = accural.MonteCarloPrice(S0, sigma, r, N, StandardError);
        StandardError = StandardError * 100 / Price;
        cout << "N: " << N << ", Price: " << Price << ", SE: " << StandardError << endl;
    }
    // for N = 1,000,000, SE is <= 0.1 %
    return 0;
}
