//
//  LinearInterpolator.h
//  01 Linear Interpolator
//
//  Created by Dayal on 02/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//
#pragma once

#include <map>

using namespace std;

class LinearInterpolator
{
    map < double, double > Points;
    void GetSlopeAndIntercept(const double x1, const double x2, const double y1, const double y2, double &Slope, double &Intercept); // calculate slope and intercept of two points
public:
    LinearInterpolator(); // default constructor
    void add(double x, double y); // add points to data structure
    double value(double x); // find interpolated value for given x
};
