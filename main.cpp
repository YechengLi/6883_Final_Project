//
//  main.cpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//

#include <iostream>
#include "OpeOverLoading.hpp"
#include "Group.hpp"
#include <map>
#include "Stock.hpp"
#include "RetrieveData.hpp"

int main() 
{
	map<string, Stock> beatMap, meetMap, missMap;
	ReadCsv("beat.csv", beatMap);
	ReadCsv("meet.csv", meetMap);
	ReadCsv("miss.csv", missMap);
	RetrieveFromYahoo(beatMap);
	RetrieveFromYahoo(meetMap);
	RetrieveFromYahoo(missMap);
	map<string, double> SPY;
	RetrieveSPY(SPY);
    
    
	return 0;
}
