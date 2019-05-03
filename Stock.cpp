//
//  Stock.cpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//

#include "Stock.hpp"



void Stock::CalAR(map<string,double> SPXReturn){
    AR.resize(120);
    vector<double>::iterator itr = Price.begin();
    itr++;
    auto it = SPXReturn.find(StartTime);
    it++;
    for(int i=0;itr!=Price.end();itr++){
        AR[i] = (*itr - *(itr-1))/(*(itr-1))-it->second;
        i++;
		it++;
    }
    
    
 
}
 

