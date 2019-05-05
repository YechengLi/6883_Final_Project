//
//  Group.hpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//
#ifndef Group_hpp
#define Group_hpp

#include <string>
#include <vector>
#include <map>
#include "Stock.hpp"
using namespace std;

class Group{
private:
    vector<string> tickerlist; //a vector containing all the ticker of the stocks in that Group
    vector<double> AvgCAAR;
    map<string,Stock> MyStock;
    int num;
public:
    vector<string> GetTickerlist(void){return tickerlist;}
    vector<double> GetAvgCAAR(void){return AvgCAAR;}
    void CalAvgCAAR();
    vector<double> CalCAAR();
    vector<double> AAR();
    Group(vector<string> tickerlist_,map<string,Stock> MyStock_):tickerlist(tickerlist_),num(tickerlist.size()),MyStock(MyStock_){}
    Group(){}
    
    
    
};

#endif /* Group_hpp */
