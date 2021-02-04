//
//  NormalRandomGenerator.cpp
//  2 Normal Generator Class
//
//  Created by Dayal on 30/01/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "NormalRandomGenerator.h"


NormalRandomGenerator::NormalRandomGenerator()
{
    PreviousGenerated = (double)rand() / (double)RAND_MAX;
}

double NormalRandomGenerator::generate2A()
{
    double Uniform1 = (double)rand() / (double)RAND_MAX;
    double Uniform2 = (double)rand() / (double)RAND_MAX;
    return sqrt(-2 * log(Uniform1)) * cos(2 * 2 * acos(0.0) * Uniform2);
}

double NormalRandomGenerator::generate()
{
    double Uniform = (double)rand() / (double)RAND_MAX;
    double Z = sqrt(-2 * log(PreviousGenerated)) * cos(2 * 2 * acos(0.0) * Uniform);
    PreviousGenerated = Uniform;
    return Z;
}
