//
//  Stock.hpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//

#ifndef Stock_hpp
#define Stock_hpp

#include <vector>
#include <string>
#include <map>
using namespace std;

class Stock{
private:
    vector<double> Price;
    string StartTime;
    string EndTime;
    vector<double> AR;
public:
	void SetPrice(double dailyPrice) { Price.push_back(dailyPrice); }
	void SetStartTime(const string& StartTime_) { StartTime = StartTime_; }
	void SetEndTime(const string& EndTime_) { EndTime = EndTime_; }
	void CalAR(map<string, double> SPXReturn);
	vector<double> GetPrice(void) const { return Price; }
	string GetStartTime(void) const { return StartTime; }
	string GetEndTime(void) const { return EndTime; }
	vector<double> GetAR(void) const { return AR; }
    Stock() {}
	Stock(string StartTime_, string EndTime_) :StartTime(StartTime_), EndTime(EndTime_) {}
    
    
};

#endif /* Stock_hpp */
