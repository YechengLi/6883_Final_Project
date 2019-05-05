//
//  Group.cpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//

#include "Group.hpp"
#include "OpeOverLoading.hpp"
#include <cstdlib>


void Group::CalAvgCAAR(){
	AvgCAAR.resize(120);
    for(int i = 0; i<30; i++){
		AvgCAAR = (i/(i+1.0))*AvgCAAR + (1.0/(i+1.0))*CalCAAR();
    }
}


vector<double> Group::CalCAAR(){
    vector<double> result(120);
    vector<double> arr = AAR();
    result [0] = arr [0];
    for(int i=1; i<120 ; i++){
        result[i] = result[i-1] + arr[i];
    }
    return result;
}

vector<double> Group::AAR(){
    vector<double> result(120);
    for(int i = 1;i<=30;i++){
        double U = (rand()+1.0)/(RAND_MAX+1.0);
        int index = U*num;
        result =  ((i-1.0)/i)*result + (1.0/i)*MyStock[tickerlist[index]].GetAR();
                
    }
    return result;
}
