//
//  Adapter.cpp
//  06-01 Gilt Pricing
//
//  Created by Dayal on 02/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "Adapter.hpp"

double Adapter::eval(double x) const // for solver
{
    return mGilt->CleanPrice(mSettlement , x);
}
