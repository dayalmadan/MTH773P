//
//  main.cpp
//  06-02 Trinomial Tree
//
//  Created by Dayal on 03/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "EuropeanCall.hpp"
#include "EuropeanPut.hpp"

using namespace std;

int main()
{
    
    const double K = 110.0;
    const double T = 1.0;
    const EuropeanCall c(K, T);
    
    const double S0 = 100.0;
    const double sigma = 0.2;
    const double r = 0.05;
    const int N = 1000;
        
    const double BinomialPrice = c.BinomialTreePrice(S0, sigma, r, N);
    const double TrinomialPrice = c.TrinomialTreePrice(S0, sigma, r, N, 2.0);
    const double BSPrice = c.PriceByBSFormula(S0, r, sigma, T);
    
    cout << "Binomial Price: " << BinomialPrice << endl;
    cout << "Trinomial Price: " << TrinomialPrice << endl;
    cout << "Black-Scholes Price: " << BSPrice << endl;
    
// part 2(b)
    for (int n = 1; n <= 50; ++n)
    {
        const double BinomialPrice = c.BinomialTreePrice(S0, sigma, r, n);
        const double TrinomialPrice = c.TrinomialTreePrice(S0, sigma, r, n, 2.0);
        cout << TrinomialPrice - BSPrice << "\t" << BinomialPrice - BSPrice << endl;
    }
// Observations from 2b: Trinomial tree price is is more closer to Black Scholes price.
// Trinomial model converges quickly to black scholes as n increases.
    
// part 2(c)
    for (int i = 100; i <= 200; ++i)
    {
        const int N = 20;
        const double lambda = i / 100.0;
        const double TrinomialPrice = c.TrinomialTreePrice(S0, sigma, r, N, lambda);
        cout << lambda << "\t" << TrinomialPrice - BSPrice << endl;
    }
    
    
    return 0;
}
