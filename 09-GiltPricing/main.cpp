//
//  main.cpp
//  06-01 Gilt Pricing
//
//  Created by Dayal on 02/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include "Date.hpp"
#include "Gilt.hpp"

using namespace std;

int main()
{
    const Date Maturity(2039, 9, 7); // 7th September 2039
    const double Coupon = 4.25; // in percentage
    const Gilt MyGilt(Maturity, Coupon);
    
    const Date Settlement(2013, 12, 12); // 12th December 2013
    
// Calculate clean price on settlement date assuming yield of 3.1432%
    const double Yield = 3.1432; // in percentage
    //const double Yield = 3.43261; // in percentage
    const double CleanPrice = MyGilt.CleanPrice(Settlement, Yield / 100.0); // divide by 100 to change from percent to decimal
    cout << "Clean price: " << CleanPrice << endl;
    
// calculate yield to maturity from settlement date assuming clean price of 111.95
    const double MarketCleanPrice = 111.95; // given in problem statement
    const double YieldToMaturity = MyGilt.Yield(Settlement, MarketCleanPrice) * 100;
    cout << "Yield to Maturity: " << YieldToMaturity << " %" << endl;
    
    return 0;
}
