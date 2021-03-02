//
//  Gilt.hpp
//  06-01 Gilt Pricing
//
//  Created by Dayal on 02/03/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#pragma once
#include "Date.hpp"
#include "Solver.hpp"
#include <iostream>
#include <cmath>

using namespace std;

class Adapter;

class Gilt: public Solver
{
    const Date mMaturity;
    const double mCoupon;
    
    const double CouponsPerYear = 2;
    
    int NoOfCouponPayments(Date &NextPayment, const Date Settlement) const; // return no. of coupon payments  
    
    
public:
    Gilt(const Date Maturity, const double Coupon) : mMaturity(Maturity), mCoupon (Coupon) {};
    
    double CleanPrice(const Date Settlement, const double Yield) const; // return clean price of bond on the settlement date
    
    double Yield(const Date Settlement, const double Clean) const; // return yield to maturity of bond given settlement date and clean price
};
