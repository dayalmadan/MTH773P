//
//  main.cpp
//  03-01 Dates And Calenders
//
//  Created by Dayal on 08/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include "Date.hpp"
#include "Calendar.hpp"

using namespace std;

void Problem2(); // run solutions of problem 2 of coursework 3

int main()
{
    Problem2();
    return 0;
}

void Problem2() // run solutions of problem 2 of coursework 3
{
// part (a)
    vector <Date> CashFlowDates; // store cashflow dates
    Date SwapStartDate(2017, 1, 9); // interest rate swap start date
    const unsigned int SwapPeriodInYears = 10;
    const unsigned int CashFlowsPerYear = 4; // 1->annually, 2->semi-annually, 4->quarterly, 12->monthly
    const unsigned int MonthJumps = 12 / CashFlowsPerYear; // no of months till cashflow
    unsigned int TotalCashflows = 0;
    for (int iYear = 1; iYear <= SwapPeriodInYears; ++iYear) // for each year
    {
        for (int iCashFlow = 1; iCashFlow <= CashFlowsPerYear; ++iCashFlow) // cash flow per year
        {
            SwapStartDate.addMonths(MonthJumps); // go forward in date
            
            Date CashFlowDate(SwapStartDate.DateSerial());
            CashFlowDate.rollToGBD(); // if cash flow date is on weekends
            CashFlowDates.push_back(CashFlowDate);
            
            ++TotalCashflows; // cashflow counter
            unsigned int Year = 0, Month = 0, Day = 0;
            CashFlowDate.ActualDate(Year, Month, Day);
            
            cout << "Cashflow " << TotalCashflows << " is due on " << Year << "-" << Month << "-" << Day << " " << endl;
        }
    }
    
// part (b)
    unsigned int NoOfSundays = 0; // hold no of sundays that falls on 1st day of month
    unsigned int Year = 0, Month = 0, Day = 0;
    for (Date dt = Date(1950, 1, 1); dt != Date(2000, 1, 1); ++dt)
    {
        dt.ActualDate(Year, Month, Day);
        if (Day == 1 && dt.isSunday())
            ++NoOfSundays;
    }
    cout << "Number of Sundays that fall on 1st day of the month from 1st January 1950 and 31st December 1999 is :" << NoOfSundays << endl;

// part (c)
    Calender calender;
// data from https://www.gov.uk/bank-holidays
    calender.addHoliday(Date(2017,12,26));
    calender.addHoliday(Date(2017,12,25));
    calender.addHoliday(Date(2017,8,28));
    calender.addHoliday(Date(2017,5,29));
    calender.addHoliday(Date(2017,5,1));
    calender.addHoliday(Date(2017,4,17));
    calender.addHoliday(Date(2017,4,14));
    calender.addHoliday(Date(2017,1,2));
    
// store unique GBDs. eg, GBD for Jan is 22, GBD for Feb is 20, GBD for Mar is 22, GBD for Apr is 21, map will have following values
// [20]->(2), [21]->(4) and [22]->(1, 3)
    map < int, vector < int > > GBDFrequency;
    unsigned int HighestGBDCount = 0;
    unsigned int PrevMonth = 0;
    for (Date dt = Date(2017,1,1); dt != Date(2018,1,1); ++dt)
    {
        dt.ActualDate(Year, Month, Day);
        if (PrevMonth != Month) // reset counter and add previous month data to map
        {
            if (PrevMonth > 0)
                GBDFrequency[HighestGBDCount].push_back(PrevMonth);
            HighestGBDCount = 0;
            PrevMonth = Month;
        }
        if (dt.isGBD(calender))
            ++HighestGBDCount;
    }
    GBDFrequency[HighestGBDCount].push_back(PrevMonth); // add last month
    
    cout << "Months with the highest number of good business days in 2017 are: ";
    for (int i = 0; i < GBDFrequency.rbegin()->second.size(); ++i)
        cout << GBDFrequency.rbegin()->second[i] << " ";
    cout << endl;
    
    return;
}
