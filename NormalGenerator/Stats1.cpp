//
//  Stats1.cpp
//  1 StatisticsClass
//
//  Created by Dayal on 30/01/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "Stats1.h"

Stats1::Stats1()
{
    Sum = 0;
    Count = 0;
    SqSum = 0;
}

void Stats1::add(double ANumber)
{
    Sum += ANumber;
    SqSum += pow(ANumber, 2);
    Count++;
}

double Stats1::mean()
{
    if (Count > 0)
        return Sum / Count;
    return 0;
}

double Stats1::stDev()
{
    if (Count > 0)
        return sqrt(SqSum / Count - pow(Sum / Count, 2));
    return 0;
}
