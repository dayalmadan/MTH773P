//
//  main.cpp
//  09-01 Heston Model
//
//  Created by Dayal on 02/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "EuropeanCall.h"

using namespace std;

int main()
{
    const double S0 = 100, r = 0.05, T = 1, K = 105;
    const double a = 1.25, vbar = 0.3 * 0.3, eta = 0.3, v0 = 0.2 * 0.2, rho = 0.1;
    
    EuropeanCall call(K);
    
    unsigned int N = 10000;
    double StandardError = 1;
    
    const double Price = call.MonteCarloPrice(S0, r, T, a, vbar, eta, v0, rho, N, StandardError);
    StandardError = StandardError * 100 / Price;
    cout << "N: " << N << ", Heston Model Price: " << Price << ", SE: " << StandardError << endl;
    
    const double IV = call.ImpliedVolatility(S0, r, T, Price);
    cout << "Implied Volatility: " << IV << endl;
    
    for (int k = 60; k <= 150; ++k)
    {
        EuropeanCall pricer(k);
        const double Price = pricer.MonteCarloPrice(S0, r, T, a, vbar, eta, v0, rho, N, StandardError);
        const double IV = pricer.ImpliedVolatility(S0, r, T, Price);
        cout << k << " " << IV << endl;
    }
    
    // plotting K and IV gives volatility smile, although, not perfect
    
    return 0;
}
