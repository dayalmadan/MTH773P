//
//  main.cpp
//  2 Normal Generator Class
//
//  Created by Dayal on 30/01/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "NormalRandomGenerator.h"
#include "Stats1.h"

using namespace std;

int main()
{
    const int N = 100000;
    NormalRandomGenerator NormalGenerator;
    Stats1 stat;
    for (int i = 0; i < N; i++)
    {
        double NormalNumber = NormalGenerator.generate();
        stat.add(NormalNumber);
    }
    cout << "Analytical Mean: 0, Numerical Mean: " << stat.mean() << endl;
    cout << "Analytical StDev: 1, Numerical StDev: " << stat.stDev() << endl;
    return 0;
}
