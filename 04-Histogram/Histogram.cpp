//
//  Histogram.cpp
//  02-02 Histogram
//
//  Created by Dayal on 02/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "Histogram.h"

Histogram::Histogram(double XMin, double XMax, int NoOfBins) // initialise histogram with user input values
{
    MaxValue = XMax;
    MinValue = XMin;
    MaxBins = NoOfBins;
    if (MaxBins < 1)
        return;
    BinWidth = (MaxValue - MinValue) / NoOfBins;
    
    HistBins.assign(MaxBins + 2, 0.0);
    
    HistBoundaries.assign(MaxBins + 2, MinValue);
    
    for (int iBin = 0; iBin < MaxBins; ++iBin) // set upper limits of each bin
        HistBoundaries[iBin + 1] = HistBoundaries[iBin] + BinWidth;
    
    HistBoundaries.back() = numeric_limits<double>::max(); // set last bin to max limit
    return;
}

void Histogram::add(double x) // add the x value to histogram
{
    if (x <= MinValue) // goes to 1st bin
        ++HistBins[0];
    else if (x > MaxValue) // goes to last bin
        ++HistBins.back();
    else
    {
        int BinIdx = ceil((x - MinValue) / (MaxValue - MinValue) * MaxBins); // calculate bin index for given x
        ++HistBins[BinIdx];
    }
    return;
}

void Histogram::getResults(vector<double> &Boundaries, vector<double> &BinData)
{
// copy private variables to passed vectors
    Boundaries = HistBoundaries;
    BinData = HistBins;
    return;
}

void Histogram::Display()
{
// display '*' as a histogram
    for (int i = 0; i < HistBoundaries.size(); ++i)
    {
        cout << HistBoundaries[i] << "\t";
        for (int j = 0; j < HistBins[i]; ++j)
            cout << "*";
        cout << endl;
    }
    return;
}
