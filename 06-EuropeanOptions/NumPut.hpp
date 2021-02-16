//
//  NumPut.hpp
//  04-01 BS European Options
//
//  Created by Dayal on 16/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include "NumOption.hpp"

class NumPut: public NumOption
{
public:
    NumPut(double S0, double K, double T, double Sigma, double r); // constructor to set private variables
    double Payoff(double St); // calculate payoff of call option
    double PriceByApproximation(double StepSize); // aprroximate price of call option using trapezium method
};
