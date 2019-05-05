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
#include <vector>
using namespace std;

Group* GroupCalculation(vector<string>& TickerList, map<string, Stock>& Mystock, map<string, double>* SPYptr)
{
    for (map<string, Stock>::iterator itr = Mystock.begin(); itr != Mystock.end(); itr++) {
        itr->second.CalAR(SPYptr);
    }
    Group* GroupPtr = new Group(TickerList, Mystock);
    GroupPtr->CalAvgCAAR();
    return GroupPtr;
}

int main()
{
    vector<string> BeatList, MeetList, MissList;
    map<string, Stock> BeatMap, MeetMap, MissMap;
    ReadCsv("beat.csv", BeatList, BeatMap);
    ReadCsv("meet.csv", MeetList, MeetMap);
    ReadCsv("miss.csv", MissList, MissMap);
    RetrieveFromYahoo(BeatMap);
    RetrieveFromYahoo(MeetMap);
    RetrieveFromYahoo(MissMap);
    map<string, double> SPY;
    RetrieveSPY(SPY);
    map<string, double>* SPYptr = CalReturn(SPY);
    
    Group* BeatPtr = GroupCalculation(BeatList, BeatMap, SPYptr);
    Group* MeetPtr = GroupCalculation(MeetList, MeetMap, SPYptr);
    Group* MissPtr = GroupCalculation(MissList, MissMap, SPYptr);
    
    //for (map<string, Stock>::iterator itr = BeatMap.begin();itr!= BeatMap.end();itr++) {
    //    itr->second.CalAR(SPYptr);
    //}
    //Group BeatGroup(BeatList, BeatMap);
    //BeatGroup.CalAvgCAAR();
    //
    //for (map<string, Stock>::iterator itr = MeetMap.begin(); itr != MeetMap.end(); itr++) {
    //    itr->second.CalAR(SPYptr);
    //}
    //Group MeetGroup(MeetList, MeetMap);
    //MeetGroup.CalAvgCAAR();
    
    //for (map<string, Stock>::iterator itr = MissMap.begin(); itr != MissMap.end(); itr++) {
    //    itr->second.CalAR(SPYptr);
    //}
    //Group MissGroup(MissList, MissMap);
    //MissGroup.CalAvgCAAR();
    
    for (int i = 0; i <= 10; i++)
    {
        cout << BeatPtr->GetAvgCAAR()[i] << endl;
    }
    
    for (int i = 0; i <= 10; i++)
    {
        cout << MeetPtr->GetAvgCAAR()[i] << endl;
    }
    
    for (int i = 0; i <= 10; i++)
    {
        cout << MissPtr->GetAvgCAAR()[i] << endl;
    }
    
    
    
    
    delete SPYptr;
    delete BeatPtr;
    delete MeetPtr;
    delete MissPtr;
    
    return 0;
}
