//
//  Adapter.hpp
//  06-01 Gilt Pricing
//
//  Created by Dayal on 02/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include "Date.hpp"
#include "Gilt.hpp"
#include "Function.hpp"

class Adapter: public Function
{
    
    const Date mSettlement; // settlement date
    const Gilt *mGilt;
public:
    Adapter(const Gilt *MyGilt, const Date Settlement) : mGilt(MyGilt), mSettlement(Settlement) {};
    double eval(double x) const; // for solver
};
