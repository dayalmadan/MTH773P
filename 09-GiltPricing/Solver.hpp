//
//  Solver.hpp
//  06-01 Gilt Pricing
//
//  Created by Dayal on 02/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//  Cal also implement Another solver methods here

#pragma once
#include "Function.hpp"

class Solver
{
public:
    double BisectionSolver(const Function* f, double c, double left, double right, double acc) const; // bisection solver algorithm
};
