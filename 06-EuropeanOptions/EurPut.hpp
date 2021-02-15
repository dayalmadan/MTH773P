//
//  EurPut.hpp
//  04-01 BS European Options
//
//  Created by Dayal on 15/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include "EurOption.hpp"

class EurPut: public EurOption
{
public:
    EurPut(double S0, double K, double T, double Sigma, double r); // constructor to set private variables
    double PriceByBSFormula(); // price a call option
    double DeltaByBSFormula(); // delta of call option
    double GammaByBSFormula(); // gamme of call option
    double ThetaByBSFormula(); // theta of call option
};
