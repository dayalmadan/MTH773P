//
//  Date.hpp
//  03-01 Dates And Calenders
//
//  Created by Dayal on 08/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once

#include "basic.h"
#include <algorithm>

using namespace std;

enum Weekday {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday}; // enumeration for week days

class Calender;

class Date
{
    static unsigned int daysInMonth[]; // holds no. of days in each month
    unsigned int SerialDate;
    
    Weekday weekday(); // returns day of the week
public:
    Date(unsigned int InputSerialDate) : SerialDate(InputSerialDate) {} // takes date as serial number
    Date(unsigned int Year, unsigned int Month, unsigned int Day); // takes year, month, day and convert into serial format
    unsigned int DateSerial() const; // return date in serial format
    void ActualDate(unsigned int &Year, unsigned int &Month, unsigned int &Day); // return actual year-month-day
    
    void addDays(int d); // add days to the date
    void addMonths(int m); // add months to the date
    void addYears(int y); // add years to the date
    
    int daysDiff(Date dt); // return difference between two dates in days
    int operator-(Date &dt); // difference between two dates
    
    bool isGBD(); // check if date is a weekday
    void rollToGBD(); // roll to next working day
    
    void addBusinessDays(int d); // add business days to the date, d > 0
    
    Date operator++(); // increment date by 1 day
    
    bool operator!=(const Date &dt) const; // return true if two dates are not equal
    
    bool isSunday(); // if date is sunday
    
    bool isGBD(const Calender &calender); // check if date is a weekday and not a holiday
    void rollToGBD(const Calender &calender); // roll to next working day
};
