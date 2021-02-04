//
//  Stats2.cpp
//  1 StatisticsClass
//
//  Created by Dayal on 30/01/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "Stats2.h"

Stats2::Stats2()
{
    SumX = 0;
    SumY = 0;
    SumXY = 0;
    SqX = 0;
    SqY = 0;
    Count = 0;
}

void Stats2::add(double x, double y)
{
    SumX += x;
    SumY += y;
    SumXY += (x * y);
    SqX += pow(x, 2);
    SqY += pow(y, 2);
    Count++;
}

double Stats2::Covariance()
{
    if (Count <= 0)
        return 0;
    return SumXY / Count - SumX * SumY / pow(Count, 2);
}

double Stats2::Correlation()
{
    if (Count <= 0)
        return 0;
    double VarX = SqX / Count - pow(SumX / Count, 2);
    double VarY = SqY / Count - pow(SumY / Count, 2);
    return Covariance()/ sqrt(VarX * VarY);
}

double Stats2::Gradient()
{
    if (Count <= 0)
        return 0;
    double VarX = SqX / Count - pow(SumX / Count, 2);
    return Covariance() / VarX;
}

double Stats2::Intercept()
{
    if (Count <= 0)
        return 0;
    return (SumY - Gradient() * SumX) / Count;
}
