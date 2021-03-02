//
//  Solver.cpp
//  06-01 Gilt Pricing
//
//  Created by Dayal on 02/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "Solver.hpp"

double Solver::BisectionSolver(const Function* f, double c, double left, double right, double acc) const // bisection solver algorithm
{
    double fl = f->eval(left);
    double fr = f->eval(right);
    
    while (true)
    {
        const double mid = (left + right) / 2.0;
        if (right - left <= acc)
            return mid;
        const double fm = f->eval(mid);
        if ((fl <= c && fm >= c) || (fm <= c && fl >= c))
        {
            right = mid;
            fr = fm;
        }
        else
        {
            left = mid;
            fl = fm;
        }
    }
    
    return 0.0;
}
