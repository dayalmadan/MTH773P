//
//  NormalRandomGenerator.h
//  2 Normal Generator Class
//
//  Created by Kaveri Dayal on 30/01/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include <cstdlib>
#include <cmath>

class NormalRandomGenerator
{
    double PreviousGenerated;
public:
    NormalRandomGenerator();
    double generate2A(); // used in 2a problem
    double generate();
};
