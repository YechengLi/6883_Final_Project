#ifndef RETRIEVEDATA_HPP
#define RETRIEVEDATA_HPP

#include "Stock.hpp"
#include <map>
#include <string>

using namespace std;

void ReadCsv(string filename, map<string, Stock>& tickerMap);
int RetrieveFromYahoo(map<string, Stock>& tickerMap);
int RetrieveSPY(map<string, double>& SPYPriceList);
#endif // !RETRIEVEDATA_HPP

