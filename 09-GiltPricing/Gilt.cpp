//
//  Gilt.cpp
//  06-01 Gilt Pricing
//
//  Created by Dayal on 02/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include "Gilt.hpp"
#include "Adapter.hpp"

double Gilt::CleanPrice(const Date Settlement, const double Yield) const // return clean price of bond on the settlement date
{
    Date NextCouponDate = mMaturity;
    const int NoOfPayments = NoOfCouponPayments(NextCouponDate, Settlement);
    
    Date PrevCouponDate = NextCouponDate;
    PrevCouponDate.addMonths(-6);
    PrevCouponDate.rollToGBD();
    
    int s = NextCouponDate - PrevCouponDate;
    int m = NextCouponDate - Settlement;
 
    double DirtyPrice = 100 / pow(1 + Yield / CouponsPerYear, NoOfPayments); // present value of principal
    for (int iCoupon = 1; iCoupon <= NoOfPayments; ++iCoupon) // present value of each coupon payment
    {
        DirtyPrice += (mCoupon / CouponsPerYear) / pow(1 + Yield / CouponsPerYear, iCoupon);
    }
    
    DirtyPrice /= pow(1 + Yield / CouponsPerYear, double(m) / double(s));
    
    int r = Settlement - PrevCouponDate;
    
    double AccruedInterest = r * mCoupon / (2.0 * s);
    
    return DirtyPrice - AccruedInterest;
}

double Gilt::Yield(const Date Settlement, const double Clean) const // return yield to maturity of bond given settlement date and clean price
{
    const Adapter *adapter = new Adapter(this, Settlement);
    return BisectionSolver(adapter, Clean, 0.0, 1.0, 1e-6);
}

int Gilt::NoOfCouponPayments(Date &NextCouponDate, const Date Settlement) const // return no. of coupon payments
{
    int NumPayments = 0;
    Date dt = mMaturity;
    while (dt.DateSerial() > Settlement.DateSerial())
    {
        NextCouponDate = dt;
        dt.addMonths(-6); // semi-annual payment for Gilt
        ++NumPayments;
    }
    NextCouponDate.rollToGBD(); // roll to next business day if current day is a weekend
    return NumPayments;
}
