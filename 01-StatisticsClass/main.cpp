//
//  main.cpp
//  1 StatisticsClass
//
//  Created by Dayal on 30/01/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include <random>
#include "Stats1.h"
#include "Stats2.h"

using namespace std;

void MeanStdCalculation(); // calculate mean and stdev of 10,000 uniform distribution [0,1] values 1(a)
void LinearRegression(); // 1(c)

int main()
{
    MeanStdCalculation();
    LinearRegression();
    return 0;
}

void LinearRegression() // 1(c)
{
    Stats2 stat2;
    stat2.add(1, 16);
    stat2.add(2, 11);
    stat2.add(3, 9);
    stat2.add(4, 3);
    stat2.add(5, 2);
    cout << "Covariance: " << stat2.Covariance() << endl;
    cout << "Correlation: " << stat2.Correlation() << endl;
    cout << "Gradient: " << stat2.Gradient() << endl;
    cout << "Intercept: " << stat2.Intercept() << endl;
    cout << "R2: " << pow(stat2.Correlation(), 2) << endl;
}

void MeanStdCalculation() // calculate mean and stdev of 10,000 uniform distribution [0,1] values 1(a)
{
    const double a = 0.0;
    const double b = 1.0;
    
    const double AnalyticalMean = (a + b) / 2;
    const double AnalyticalStd = (b - a) / sqrt(12);
    
    mt19937 Generator(0);
    uniform_real_distribution<double> UniformDist(a, b);
    
    Stats1 Stat;
    const int MaxLimit = 10000;
    for (int i = 0; i < MaxLimit; ++i)
    {
        double RandomNumber = UniformDist(Generator);
        Stat.add(RandomNumber);
    }
    cout << "Analytical Mean: " << AnalyticalMean << ", Numerical Mean: " << Stat.mean() << endl;
    cout << "Analytical StDev: " << AnalyticalStd << ", Numerical StDev: " << Stat.stDev() << endl;
}
