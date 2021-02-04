//
//  Histogram.h
//  02-02 Histogram
//
//  Created by Dayal on 02/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <vector>
#include <limits>
#include <cmath>
#include <iostream>

using namespace std;

class Histogram
{
    double MinValue, MaxValue;
    int MaxBins;
    double BinWidth; // width of each bin
    vector < double > HistBoundaries; // save histogram boundaries
    vector < double > HistBins; // save no of points in each histogram
public:
    Histogram(double XMin, double XMax, int NoOfBins); // initialise histogram with user input values
    void add(double x); // add the x value to histogram
    void getResults(vector<double> &Boundaries, vector<double> &BinData);
    void Display();
};
