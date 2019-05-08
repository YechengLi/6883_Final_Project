#ifndef RETRIEVEDATA_HPP
#define RETRIEVEDATA_HPP

#include "Stock.hpp"
#include <map>
#include <string>

using namespace std;

void ReadCsv(string filename, vector<string>& tickerList, 
	map<string, Stock>& tickerMap, GroupType group);
int RetrieveFromYahoo(map<string, Stock>& tickerMap);
int RetrieveSPY(map<string, double>& SPYPriceList);
#endif

