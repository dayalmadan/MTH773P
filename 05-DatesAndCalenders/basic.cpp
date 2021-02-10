//********************************************************
//
//	Michael J Phillips
//	Copyright 2013
//	All rights reserved.
//
//********************************************************

#include <cmath>
#include "basic.h"

//	Days in each month in a leap year
static unsigned int daysInMonth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(unsigned int year)
{
    if (year % 100 == 0)
        return (year % 400 == 0);
	return (year % 4 == 0);
}

unsigned int DMY_to_serial(unsigned int day, unsigned int month, unsigned int year)
{
	//
	//	Cumulative days in previous months
	//
	static const unsigned int f[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

	//
	//	Validation of input values
	//
	if (year < 1900)
	{
		//	Need to give an error message
	}
	if (month < 1 || month > 12)
	{
		//	Need to give an error message
	}
	if (day < 1 || day > daysInMonth[month-1])
	{
		//	Need to give an error message
	}
	if (!isLeapYear(year) && month == 2 && day == 29)
	{
		//	Need to give an error message
	}
	
	unsigned int serial = (year - 1900) * 365 + static_cast<int>((year - 1897) / 4) + f[month-1] + day;

	if (month > 2 && isLeapYear(year))
		++serial;

	return serial;
}

void serial_to_DMY(unsigned int serial, unsigned int& day, unsigned int& month, unsigned int& year)
{
	static const double EPSILON = 0.00000001;
	static const double N1 = 365.25;
	static const double N2 = 2447.0 / 80.0;

	//	Move base to 29/2/1900 (this will be <0 for first 2 months of 1900)
	const int serialAdj = serial - 60;

	//	Number of whole years that have passed since 29/2/1900
	const int g = static_cast<int>(floor((serialAdj - EPSILON) / N1));

	//	Days since most recent last date in february, plus dummy zero month of 30 days
	const int c = serialAdj - static_cast<int>(floor(g * N1)) + 30;

	//	Number of months after February (1 to 12)
	const unsigned int p = static_cast<unsigned int>(floor(c / N2));

	//	Determine outputs
	day = c - static_cast<unsigned int>(N2 * p);
	month = p + 2;
	year = g + 1900;

	if (p >= 11)
	{
		month -= 12;
		++year;
	}
	return;
}

