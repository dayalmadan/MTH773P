//
//  main.cpp
//  09-02 Jump Diffusion Model
//
//  Created by Dayal on 02/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "EuropeanCall.h"

using namespace std;

int main()
{
    const double S0 = 100, r = 0.05, sigma = 0.15, lambda = 1, m = 0.05, s = 0.3, K = 105, T = 0.5;
    EuropeanCall call(K);
    const double BSPrice = call.CallPriceByBS(S0, r, T, sigma);
    const double JDPrice = call.JumpDiffusionPrice(S0, r, sigma, lambda, m, s, T);
    cout << "Black Scholes Price: " << BSPrice << ", Jump DIffusion Price: " << JDPrice << endl;
    return 0;
}
