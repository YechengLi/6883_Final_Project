#ifndef OpeOverLoading_hpp
#define OpeOverLoading_hpp

#include "Stock.hpp"
#include <vector>
#include <iostream>
using namespace std;

typedef vector <double> VectorD;
typedef vector <VectorD> VectorV;
typedef vector <VectorV> Matrix;

vector<double> operator*(const double& a,const vector<double>& V);
vector<double> operator/(const vector<double>& V, const double& a);
vector<double> operator+(const vector<double>& V,const vector<double>& W);
ostream & operator<<(ostream & out, VectorD & V);




#endif 
