//
//  LinearInterpolator.cpp
//  01 Linear Interpolator
//
//  Created by Dayal on 02/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "LinearInterpolator.h"

LinearInterpolator::LinearInterpolator() // default constructor
{
    return;
}

void LinearInterpolator::add(double x, double y) // add points to data structure
{
// Ignore if x is present in Points
    if (Points.find(x) == Points.end())
        Points[x] = y;
    return;
}

double LinearInterpolator::value(double x) // find interpolated value for given x
{
// need at least two points to calculate interpolated value, else f(x) = x
    if (Points.size() < 2)
        return x;
    double Slope = 0, Intercept = 0;
// if x is an existing point, return corresponding value
    if (Points.find(x) != Points.end())
        return Points[x];
// if x < minimum point
    if (x < Points.begin()->first)
    {
        map < double, double >::iterator P1, P2;
        P1 = Points.begin();
        P2 = next(P1);
        GetSlopeAndIntercept(P1->first, P2->first, P1->second, P2->second, Slope, Intercept);
    }
// if x > maximum point
    else if (x > Points.rbegin()->first)
    {
        map < double, double >::reverse_iterator P1, P2;
        P1 = Points.rbegin();
        P2 = next(P1);
        GetSlopeAndIntercept(P1->first, P2->first, P1->second, P2->second, Slope, Intercept);
    }
// if x is in between available points
    else
    {
        for (map < double, double >::iterator it = Points.begin(); it != Points.end(); ++it)
        {
            if (x > it->first && x < next(it)->first)
            {
                GetSlopeAndIntercept(it->first, next(it)->first, it->second, next(it)->second, Slope, Intercept);
                break;
            }
        }
    }
    return Slope * x + Intercept;
}

void LinearInterpolator::GetSlopeAndIntercept(const double x1, const double x2, const double y1, const double y2, double &Slope, double &Intercept) // calculate slope and intercept of two points
{
// m = (y2-y1)/(x2-x1)
    Slope = (y2 - y1) / (x2 - x1);
    Intercept = y2 - Slope * x2;
}
