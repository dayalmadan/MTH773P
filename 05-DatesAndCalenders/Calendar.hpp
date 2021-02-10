//
//  Calendar.hpp
//  03-01 Dates And Calenders
//
//  Created by Dayal on 09/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once
#include <set>
#include "Date.hpp"

using namespace std;

class Calender
{
    set <unsigned int> Holidays; // ordered list of holidays (in serial date)
public:
    void addHoliday(Date dt); // add date to our holiday list
    bool isHoliday(Date dt) const; // check if holiday on given date
};
