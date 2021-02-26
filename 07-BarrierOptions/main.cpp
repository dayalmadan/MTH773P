//
//  main.cpp
//  05-01 Barrier Options
//
//  Created by Dayal on 26/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "UpAndOutEuropeanCall.hpp"

using namespace std;

int main()
{
    const double K = 100, B = 130, T = 1, S0 = 98, r = 0.05, sigma = 0.2;
    UpAndOutEuropeanCall barrier (K, B);
    cout << "Price of the given barrier option using Black Scholes is: " << barrier.BSAnalyticalPrice(S0, T, r, sigma) << endl;
    for (int i = 1; i <= 10; ++i)
    {
        const double N = i * 50;
        cout << "Price using Binomial tree with " << N << " time steps: " << barrier.BinomialTreePrice(S0, T, r, sigma, N) << endl;
    }
    return 0;
}
