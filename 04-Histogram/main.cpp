//
//  main.cpp
//  02-02 Histogram
//
//  Created by Dayal on 02/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "Histogram.h"
#include <random>

using namespace std;

int main()
{
    mt19937 Generate(0);
    
    const int Simulations = 1000; // can be changed to 1 million
    normal_distribution<double> NormalNumber(0, 1);
    
    Histogram histogram(-4, 4, 20);
    for (int i = 0; i < Simulations; ++i)
    {
        histogram.add(NormalNumber(Generate));
    }
    vector<double> boundaries, BinData;
    histogram.getResults(boundaries, BinData);
     
    for (int i = 0; i < boundaries.size(); ++i)
        cout << boundaries[i] << "\t" << BinData[i] << endl;
// Function to display histogram
    histogram.Display();
    return 0;
}
