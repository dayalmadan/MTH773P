//
//  Date.cpp
//  03-01 Dates And Calenders
//
//  Created by Dayal on 08/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "Date.hpp"
#include "Calendar.hpp"

unsigned int Date::daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // holds no. of days in each month

Date::Date(unsigned int Year, unsigned int Month, unsigned int Day) // takes year, month, day and convert into serial format
{
    SerialDate = DMY_to_serial(Day, Month, Year);
}

unsigned int Date::DateSerial() const // return date in serial format
{
    return SerialDate;
}

void Date::ActualDate(unsigned int &Year, unsigned int &Month, unsigned int &Day) // return actual year-month-day
{
    serial_to_DMY(SerialDate, Day, Month, Year);
    return;
}

void Date::addDays(int d) // add days to the date
{
    SerialDate += d;
    return;
}

void Date::addMonths(int m) // add months to the date
{
    unsigned int Year = 0, Month = 0, Day = 0;
    serial_to_DMY(SerialDate, Day, Month, Year);
    int y = m / 12; // if m > 12, check how many years to add (or subtract)
    m = m % 12; // how many months to add (or subtract)
    Month += m; // increase month by m
    Year += y; // increase year by y
    if (Month > 12) // when increasing months
    {
        Month -= 12;
        ++Year;
    }
    else if (Month < 1) // when decreasing months
    {
        Month += 12;
        --Year;
    }
    Day = min(Day, daysInMonth[Month]); // check day overflow
    if (Day == 29 && m == 2 && Year % 4 != 0) // If not a leap year
        Day = 28;
    SerialDate = DMY_to_serial(Day, Month, Year);
    return;
}

void Date::addYears(int y) // add years to the date
{
    unsigned int Year = 0, Month = 0, Day = 0;
    serial_to_DMY(SerialDate, Day, Month, Year);
    Year += y;
    SerialDate = DMY_to_serial(Day, Month, Year);
    return;
}

int Date::daysDiff(Date dt) // return difference between two dates in days
{
    return dt.DateSerial() - SerialDate; // difference b/w two serial dates
}

int Date::operator-(Date &dt) // difference between two dates
{
    return SerialDate - dt.DateSerial();
}

Weekday Date::weekday() // returns day of the week
{
    return (Weekday)((SerialDate - 1) % 7); // since 1 January 1900 is a Monday, and 1900 was not a leap year
}

bool Date::isGBD() // check if date is a weekday
{
    Weekday day = weekday();
    if (day == Saturday || day == Sunday) // return false if day is saturday or sunday
        return false;
    return true;
}

void Date::rollToGBD() // roll to next working day
{
    Weekday day = weekday();
    if (day == Saturday) // go to monday from saturday
        addDays(2);
    else if (day == Sunday) // go to monday from sunday
        addDays(1);
    return;
}

void Date::addBusinessDays(int d) // add business days to the date, d > 0
{
    if (d <= 0) // ignore values less than 1
        return;
    const unsigned int BusinessDaysPerWeek = 5;
    
    unsigned int businessweeks = d % BusinessDaysPerWeek; // count no of weeks to add
// Logic: To add 5 business days, we add 1 calender week
    SerialDate += (businessweeks * 7); // add weeks to the date
    
    d = d / BusinessDaysPerWeek; // remaining days after adding weeks, eg to add 6 business days, add 1 calender week and 1 day
    
    int Day = (int)weekday(); // 0 to 6, 0->Sunday, 1->Monday ...
    
    SerialDate += d; // add days to our date
    
    if (Day + d > BusinessDaysPerWeek) // need to adjust for weekends
        SerialDate += 2;
    return;
}

Date Date::operator++() // increment date by 1 day
{
    addDays(1); // add one day to our date
    return *this;
}

bool Date::operator!=(const Date &dt) const // return true if two dates are not equal
{
    return SerialDate != dt.DateSerial();
}

bool Date::isSunday() // if date is sunday
{
    return (weekday() == Sunday);
}

bool Date::isGBD(const Calender &calender) // check if date is a weekday and not a holiday
{
    if(!isGBD() || calender.isHoliday(*this)) // weekend or holiday
        return false;
    return true;
}

void Date::rollToGBD(const Calender &calender) // roll to next working day
{
    rollToGBD(); // go to monday if current day is weekend
    while(calender.isHoliday(*this)) // if current day is a holiday, go to next working day
    {
        addDays(1); // go to next day
        rollToGBD(); // if next day is weekend, go to monday
    }
    return;
}
