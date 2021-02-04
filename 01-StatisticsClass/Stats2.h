//
//  Stats2.h
//  1 StatisticsClass
//
//  Created by Dayal on 30/01/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <cmath>

class Stats2
{
    double SumX, SumY, SumXY, SqX, SqY;
    int Count;
public:
    Stats2();
    void add(double x, double y); // add points x and y
    double Covariance(); // calculate covariance
    double Correlation(); // calculate correlation
    double Gradient(); // calculate gradient of linear regression
    double Intercept(); // calculate intercept of linear regression
    
};
