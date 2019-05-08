//
//  main.cpp
//  Final Project
//
//  Created by apple on 2019/5/2.
//  Copyright © 2019年 Robot Wang. All rights reserved.
//

#include "OpeOverLoading.hpp"
#include "Group.hpp"
#include "Stock.hpp"
#include "RetrieveData.hpp"
#include <iostream>
#include <map>
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

//void plotResults(double xData[], vector<double> yData, vector<double> yData2, vector<double> yData3, int dataSize) {
//	FILE *gnuplotPipe, *tempDataFile;
//	const char *tempDataFileName;
//	double x, y, x2, y2, x3, y3;
//	int i;
//	tempDataFileName = "tempData";
//	gnuplotPipe = popen("/opt/local/bin/gnuplot", "w");
//	if (gnuplotPipe) {
//		fprintf(gnuplotPipe, "plot \"%s\" with lines\n", tempDataFileName);
//		fflush(gnuplotPipe);
//		tempDataFile = fopen(tempDataFileName, "w");
//		for (i = 0; i < dataSize; i++) {
//			x = xData[i];
//			y = yData[i];
//			cout << x << endl << y << endl;
//			fprintf(tempDataFile, "%lf %lf\n", x, y);
//		}
//
//		for (i = 0; i < dataSize; i++) {
//			x2 = xData[i];
//			y2 = yData2[i];
//			cout << x2 << endl << y2 << endl;
//			fprintf(tempDataFile, "%lf %lf\n", x2, y2);
//		}
//
//		for (i = 0; i <= dataSize; i++) {
//			x3 = xData[i];
//			y3 = yData3[i];
//			fprintf(tempDataFile, "%lf %lf\n", x3, y3);
//		}
//
//		fclose(tempDataFile);
//		printf("press enter to continue...");
//		getchar();
//		remove(tempDataFileName);
//		fprintf(gnuplotPipe, "exit \n");
//	}
//	else {
//		printf("gnuplot not found...");
//	}
//}

int main()
{
    vector<string> BeatList, MeetList, MissList;
    map<string, Stock> BeatMap, MeetMap, MissMap;
    ReadCsv("beat.csv", BeatList, BeatMap, Beat);
    ReadCsv("meet.csv", MeetList, MeetMap, Meet);
    ReadCsv("miss.csv", MissList, MissMap, Miss);
    RetrieveFromYahoo(BeatMap);
    RetrieveFromYahoo(MeetMap);
    RetrieveFromYahoo(MissMap);
    map<string, double> SPY;
    RetrieveSPY(SPY);
    map<string, double>* SPYptr = CalReturn(SPY);
	//test Display()
	BeatMap["AMZN"].Display();
    
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

	//double Time[120];
	//for (int i = 0; i < 120; i++) {
	//	Time[i] = i + 1;
	//}
	//double* ptr = Time;
	//vector<double> yData = BeatPtr->GetAvgCAAR();
	//vector<double> yData2 = MeetPtr->GetAvgCAAR();
	//vector<double> yData3 = MissPtr->GetAvgCAAR();
	//plotResults(Time, yData, yData2, yData3, 120);
    
    
    
    
    delete SPYptr;
    delete BeatPtr;
    delete MeetPtr;
    delete MissPtr;
    
    return 0;
}
