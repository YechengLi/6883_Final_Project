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


vector<double> operator*(const double& a,const vector<double>& V);
vector<double> operator/(const vector<double>& V, const double& a);
vector<double> operator+(const vector<double>& V,const vector<double>& W);


#endif /* OpeOverLoading_hpp */
