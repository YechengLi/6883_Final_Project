//
//  OpeOverLoading.cpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//

#include "OpeOverLoading.hpp"
#include <cmath>


vector<double> operator+(const vector<double>& V,const vector<double>& W)
{
    unsigned long d = V.size();
    vector<double> U(d);
    for (int j=0; j<d; j++) U[j] = V[j] + W[j];
    return U;
}



vector<double> operator*(const double& a,const vector<double>& V)
{
    unsigned long d = V.size();
    vector<double> U(d);
    for (int j=0; j<d; j++) U[j] = a*V[j];
    return U;
}

vector<double> operator/(const vector<double>& V, const double& a)
{
    unsigned long d = V.size();
    vector<double> U(d);
    for (int j=0; j<d; j++) U[j] = V[j]/a;
    return U;
}
