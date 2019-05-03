//
//  OpeOverLoading.hpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//

#ifndef OpeOverLoading_hpp
#define OpeOverLoading_hpp

#include <vector>
#include <iostream>
using namespace std;

typedef vector<double> Vector;
typedef vector<Vector> Matrix;

Vector operator*(const Matrix& C,const Vector& V);
vector<double> operator*(const double& a,const vector<double>& V);
Vector operator+(const double& a,const Vector& V);
vector<double> operator+(const vector<double>& V,const vector<double>& W);
Vector operator*(const Vector& V,const Vector& W);
Vector exp(const Vector& V);
double operator^(const Vector& V,const Vector& W);
ostream & operator<<(ostream & out, Vector & V);
ostream & operator<<(ostream & out, Matrix & W);

#endif /* OpeOverLoading_hpp */
