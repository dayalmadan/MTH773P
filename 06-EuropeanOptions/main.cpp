//
//  main.cpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "EurOption.hpp"
#include "EurCall.hpp"
#include "EurPut.hpp"
#include "NumOption.hpp"
#include "NumCall.hpp"
#include "NumPut.hpp"

using namespace std;

int main()
{
    double S0 = 100, K = 102, T = 0.75, r = 0.06, sigma = 0.25;
// Price and greeks of Call option
    EurOption *european = new EurCall(S0, K, T, sigma, r);
    cout << "Call Option" << endl;
    cout << "Price: " << european->PriceByBSFormula() << endl;
    cout << "Delta: " << european->DeltaByBSFormula() << endl;
    cout << "Gamma: " << european->GammaByBSFormula() << endl;
    cout << "Theta: " << european->ThetaByBSFormula() << endl;
    cout << endl;
// Price and greeks of put option
    european = new EurPut(S0, K, T, sigma, r);
    cout << "Put Option" << endl;
    cout << "Price: " << european->PriceByBSFormula() << endl;
    cout << "Delta: " << european->DeltaByBSFormula() << endl;
    cout << "Gamma: " << european->GammaByBSFormula() << endl;
    cout << "Theta: " << european->ThetaByBSFormula() << endl;
    
    NumOption *approx = new NumCall(S0, K, T, sigma, r);
    
    const double StepSize = 0.01;
    
    cout << "Call Option price using approximation: " << approx->PriceByApproximation(StepSize) << endl;
    
    approx = new NumPut(S0, K, T, sigma, r);
    cout << "Call Option price using approximation: " << approx->PriceByApproximation(StepSize) << endl;
    
    return 0;
}
