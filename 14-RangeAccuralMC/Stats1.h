//
//  Stats1.h
//  1 StatisticsClass
//
//  Created by Dayal on 30/01/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <cmath>

class Stats1
{
    double Sum; // total sum of values
    int Count; // total count of values added
    double SqSum; // sum of squares
public:
    Stats1();
    void add(double ANumber); // to add values to sum
    double mean();
    double stDev();
};
