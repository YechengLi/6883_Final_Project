//
//  OpeOverLoading.cpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//

#include "OpeOverLoading.hpp"
#include <cmath>

Vector operator*(const Matrix& C,const Vector& V)
{
    unsigned long d = C.size();
    Vector W(d);
    for (int j=0; j<d; j++)
    {
        W[j]=0.0;
        for (int l=0; l<d; l++) W[j]=W[j]+C[j][l]*V[l];
    }
    return W;
}

vector<double> operator+(const vector<double>& V,const vector<double>& W)
{
    unsigned long d = V.size();
    vector<double> U(d);
    for (int j=0; j<d; j++) U[j] = V[j] + W[j];
    return U;
}

Vector operator+(const double& a,const Vector& V)
{
    unsigned long d = V.size();
    Vector U(d);
    for (int j=0; j<d; j++) U[j] = a + V[j];
    return U;
}

vector<double> operator*(const double& a,const vector<double>& V)
{
    unsigned long d = V.size();
    vector<double> U(d);
    for (int j=0; j<d; j++) U[j] = a*V[j];
    return U;
}

Vector operator*(const Vector& V,const Vector& W)
{
    unsigned long d = V.size();
    Vector U(d);
    for (int j=0; j<d; j++) U[j] = V[j] * W[j];
    return U;
}

Vector exp(const Vector& V)
{
    unsigned long d = V.size();
    Vector U(d);
    for (int j=0; j<d; j++) U[j] = exp(V[j]);
    return U;
}

double operator^(const Vector& V,const Vector& W)
{
    double sum = 0.0;
    unsigned long d = V.size();
    for (int j=0; j<d; j++) sum = sum + V[j]*W[j];
    return sum;
}

ostream & operator<<(ostream & out, Vector & V)
{
    for (Vector::iterator itr= V.begin(); itr != V.end(); itr++)
        out << *itr << "   ";
    out << endl;
    return out;
}

ostream & operator<<(ostream & out, Matrix & W)
{
    for (Matrix::iterator itr= W.begin(); itr != W.end(); itr++)
        out << *itr;
    out << endl;
    return out;
}
