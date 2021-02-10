//
//  Calendar.cpp
//  03-01 Dates And Calenders
//
//  Created by Dayal on 09/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "Calendar.hpp"

void Calender::addHoliday(Date dt) // add date to our holiday list
{
    Holidays.insert(dt.DateSerial()); // insert serial date in our list. Duplicate elements are automatically handled by sets
    return;
}

bool Calender::isHoliday(Date dt) const // check if holiday on given date
{
    if (Holidays.find(dt.DateSerial()) != Holidays.end()) // given date is a holiday
        return true;
    return false;
}
