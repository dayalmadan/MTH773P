//
//  main.cpp
//  07-02 Chooser Option by FD
//
//  Created by Dayal on 25/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "ChooserOption.h"

using namespace std;

int main()
{
    const double K = 100, Tc = 0.5, T = 1, S0 = 100, r = 0.05, sigma = 0.2;
    ChooserOption chooser(K);
    cout << "Analytical price: " << chooser.BSAnalyticalPrice(S0, r, T, sigma, Tc) << endl;
    chooser.UpdateOptionPrice(S0, r, T, sigma);
    cout << "Analytical Call: " << chooser.CallPrice << endl;
    cout << "Analytical Put: " << chooser.PutPrice << endl;
    
    cout << "Price by Finite Difference: " << chooser.FiniteDifferenceExplicit(S0, r, T, sigma, Tc, 80, 6400) << endl;
    return 0;
}
