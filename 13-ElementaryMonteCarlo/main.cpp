//
//  main.cpp
//  08-01 Elementary Monte Carlo
//
//  Created by Dayal on 01/04/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

/*
 Estimate area of region bounded by r = 3 - cos(8 theta)
 x = [-4, 4] and y = [-4, 4], we use square of 5 x 5 (can also test with 4 x 4)
*/


#include <iostream>
#include <cmath>
#include <random>
#include "Stats1.h"

using namespace std;

int UniformRandom(int LowerBound, int UpperBound)
{
    return rand() % (UpperBound - LowerBound + 1) + LowerBound;
}

int main()
{
    const double w = 5.0; // width of square
    const double As = w * w; // area of square
    const unsigned int Points = 1000; // max points to generate
    
    Stats1 stats;
    
    for (unsigned int i = 1; i <= Points; ++i) // generate random x and y and check if they lie inside the plot
    {
// generate x and y between [5 and -5] inclusive
        int x = UniformRandom(-5, 5);
        int y = UniformRandom(-5, 5);
        
        double theta = atan((double)y / (double)x);
        double r = 3 - cos(8 * theta);
        double r2 = sqrt(x * x + y * y);
        
        if (r2 <= r) // points are inside the plot
            stats.add(1);
        else
            stats.add(0);
    }
    
    cout << "Area of Region: " << stats.mean() * As << endl;
    cout << "Estimate of Standard Error (Accuracy): " << stats.stDev() / sqrt(Points - 1) << endl;
    
// to reach accuracy of 0.01 problem 1(c)
    
    double Accuracy = 1;
    const double DesiredAccuracy = 0.01;
    unsigned int iPoints = 999; // start with 1000 points
    
    while (Accuracy > DesiredAccuracy)
    {
        ++iPoints;
        Stats1 stats;
        for (unsigned int i = 1; i <= iPoints; ++i) // generate random x and y and check if they lie inside the plot
        {
// generate x and y between [5 and -5] inclusive
            int x = UniformRandom(-5, 5);
            int y = UniformRandom(-5, 5);
                
            double theta = atan((double)y / (double)x);
            double r = 3 - cos(8 * theta);
            double r2 = sqrt(x * x + y * y);
            
            if (r2 <= r) // points are inside the plot
                stats.add(1);
            else
                stats.add(0);
        }
        
        Accuracy = stats.stDev() / sqrt(iPoints - 1);
    }
    
    cout << iPoints << " points are needed to reach desired accuracy of " << DesiredAccuracy << endl;
    
    return 0;
}
