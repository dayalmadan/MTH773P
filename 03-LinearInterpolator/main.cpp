//
//  main.cpp
//  01 Linear Interpolator
//
//  Created by Dayal on 02/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "LinearInterpolator.h"

using namespace std;

int main()
{
    LinearInterpolator interpolator;
    interpolator.add(10, 0);
    interpolator.add(22, 21);
    interpolator.add(7, 26);
    interpolator.add(0, -20);
    cout << interpolator.value(23) << endl;
    cout << interpolator.value(0) << endl;
    cout << interpolator.value(-10) << endl;
    return 0;
}
