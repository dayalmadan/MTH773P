//
//  main.cpp
//  05-02 Portfolio Greeks
//
//  Created by Dayal on 26/02/2021.
//  Copyright © 2021 MTH773P. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "EurCall.hpp"
#include "EurPut.hpp"

using namespace std;

struct Options // structure to store options data
{
    vector <EurOption *> obj;
    vector <int> Quantity;
    vector <double> YearsToExpiry;
};

int main()
{
    Options OptionData;
    
// Read file where options data is stored
    string OptionFile = ".../typical.txt"; // update your file path here
    ifstream ifs(OptionFile.c_str());
    while (!ifs.eof())
    {
        char CallPutFlag;
        int Quantity;
        double StrikePrice, YearsToExpiry;
        ifs >> CallPutFlag >> Quantity >> StrikePrice >> YearsToExpiry;
        
        if (!ifs)
            break;
        
        EurOption *p = NULL;
        if (CallPutFlag == 'C')
        {
            p = new EurCall(StrikePrice);
        }
        else if (CallPutFlag == 'P')
        {
            p = new EurPut(StrikePrice);
        }
        if (p != NULL) // found correct option type
        {
            OptionData.obj.push_back(p);
            OptionData.Quantity.push_back(Quantity);
            OptionData.YearsToExpiry.push_back(YearsToExpiry);
        }
    }
    ifs.close();
    
    const double S0 = 100.0, sigma = 0.3, r = 0.04;
    
    double PortfolioDelta = 0, PortfolioGamma = 0, PortfolioTheta = 0;
    
    cout << "No." << setw(20) << "Delta" << setw(20) << "Gamma" << setw(20) << "Theta" << endl;
    for (int i = 0; i < OptionData.obj.size(); i++)
    {
        double T = OptionData.YearsToExpiry[i];
        int Quantity = OptionData.Quantity[i];
        double Delta = OptionData.obj[i]->DeltaByBSFormula(S0, r, sigma, T) * Quantity;
        double Gamma = OptionData.obj[i]->GammaByBSFormula(S0, r, sigma, T) * Quantity;
        double Theta = OptionData.obj[i]->ThetaByBSFormula(S0, r, sigma, T) * Quantity;
        cout << "Trade " << i + 1 << setw(20) << Delta << setw(20) << Gamma << setw(20) << Theta << endl;
        PortfolioDelta += Delta;
        PortfolioGamma += Gamma;
        PortfolioTheta += Theta;
    }
    cout << endl;
    cout << "Total" << setw(20) << PortfolioDelta << setw(20) << PortfolioGamma << setw(20) << PortfolioTheta << endl;
    return 0;
}
