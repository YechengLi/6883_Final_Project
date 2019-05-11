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
void plotResults(double xData[], vector<double> yData, vector<double> yData2, vector<double> yData3, int dataSize) {
    FILE *gnuplotPipe,*tempDataFile;
    const char *tempDataFileName1 = "Group Beat";
    const char *tempDataFileName2 = "Group Meet";
    const char *tempDataFileName3 = "Group Miss";
    double x,y, x2, y2,x3,y3;
    int i;
    gnuplotPipe = popen("/opt/local/bin/gnuplot","w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe,"plot \"%s\" with lines, \"%s\" with lines, \"%s\" with lines\n",tempDataFileName1, tempDataFileName2,tempDataFileName3);
        fflush(gnuplotPipe);
        tempDataFile = fopen(tempDataFileName1,"w");
        for (i=0; i < dataSize; i++) {
            x = xData[i];
            y = yData[i];
            fprintf(tempDataFile,"%lf %lf\n",x,y);
        }
        fclose(tempDataFile);
        tempDataFile = fopen(tempDataFileName2,"w");
        for (i=0; i < dataSize; i++) {
            x2 = xData[i];
            y2 = yData2[i];
            fprintf(tempDataFile,"%lf %lf\n",x2,y2);
        }
        fclose(tempDataFile);
        tempDataFile = fopen(tempDataFileName3,"w");
        for (i=0; i < dataSize; i++) {
            x3 = xData[i];
            y3 = yData3[i];
            fprintf(tempDataFile,"%lf %lf\n",x3,y3);
        }
        fclose(tempDataFile);
        
//        printf("press enter to continue...");
        getchar();
//        remove(tempDataFileName1);
//        remove(tempDataFileName2);
        fprintf(gnuplotPipe,"exit \n");
    } else {
        printf("gnuplot not found...");
    }
}

int main()
{
    vector<string> BeatList, MeetList, MissList;
    map<string, Stock> BeatMap, MeetMap, MissMap;
    map<string, double> SPY;
    map<string, double>* SPYptr = nullptr;
    
    Group* BeatPtr = nullptr;
    Group* MeetPtr = nullptr;
    Group* MissPtr = nullptr;
    
    Matrix DataMatirx;
    VectorV BeatVector(2);
    VectorV MeetVector(2);
    VectorV MissVector(2);

    int Option;

    do
    {
        cout << "Please enter the options' number to proceed:" << endl;
        cout << "1. Retrieve historical price data for all stocks." << endl
             << "2. Pull information for on stock from one group." << endl
             << "3. Show AAR or CAAR for one group." << endl
             << "4. Show the Gunplot graphs with CAAR for all 3 groups." << endl
             << "5. Exit your program" << endl;
        cout << endl;
        cout << "Enter your option: "; cin >> Option;
        
        switch(Option)
        {
            case 1:{
                ReadCsv("beat.csv", BeatList, BeatMap, Beat);
                ReadCsv("meet.csv", MeetList, MeetMap, Meet);
                ReadCsv("miss.csv", MissList, MissMap, Miss);
                RetrieveFromYahoo(BeatMap);
                RetrieveFromYahoo(MeetMap);
                RetrieveFromYahoo(MissMap);
                RetrieveSPY(SPY);
                SPYptr = CalReturn(SPY);
                cout << "Retrieve completed" << endl;
                break;
            }
                
            case 2:{
                char temp;
                do{
                    string TickerName;
                    cout << "Please enter the stock's ticker: "; cin >> TickerName;
                    int x =0;
                    //Check the tickername from which list(Beat, Meet, Miss) and show details/information for this stock. 
                    for (int i=0; i < BeatList.size(); i++)
                    { if(BeatList[i] == TickerName) {BeatMap[TickerName].Display(); x=1;}}
                    for (int i=0; i < MeetList.size(); i++)
                    { if(MeetList[i] == TickerName) {MeetMap[TickerName].Display(); x=1;}}
                    for (int i=0; i < MissList.size(); i++)
                    { if(MissList[i] == TickerName) {MissMap[TickerName].Display(); x=1;}}
                    //If the tickername not in the all three list, then tell us and re-decide option.
                    if (x == 0) cout << "Your Ticker is not in S&P500" << endl;
                    cout << endl;
                    cout << "Do you want to look for other stock's information? (Y/N) "; cin >> temp;
                }
                while (temp == 'Y' || temp == 'y');
                    break;
            }
            
            case 3:{
                
                BeatPtr = GroupCalculation(BeatList, BeatMap, SPYptr);
                MeetPtr = GroupCalculation(MeetList, MeetMap, SPYptr);
                MissPtr = GroupCalculation(MissList, MissMap, SPYptr);
                
                BeatVector[0] = BeatPtr->GetAvgAAR();
                BeatVector[1] = BeatPtr->GetAvgCAAR();
                MeetVector[0] = MeetPtr->GetAvgAAR();
                MeetVector[1] = MeetPtr->GetAvgCAAR();
                MissVector[0] = MissPtr->GetAvgAAR();
                MissVector[1] = MissPtr->GetAvgCAAR();
                DataMatirx.push_back(BeatVector);
                DataMatirx.push_back(MeetVector);
                DataMatirx.push_back(MissVector);
                
                int GroupName;
                int DataName;
                string GroupString[3] = { "Beat", "Meet", "Miss"};
                string DataString[2] = {"AAR", "CAAR"};
                
                char temp;
                do{
                    cout << "1.Beat   2.Meet  3.Miss:  "; cin >> GroupName;
                    cout << "1.AAR   2.CAAR:  "; cin >> DataName;
                    cout << GroupString[GroupName-1] << " " << DataString[DataName-1] << endl;
                    cout << DataMatirx[GroupName-1][DataName-1] << endl;
                    cout << "Do you want to look for other data? (Y/N)  "; cin >> temp;
                    cout << endl;
                }
                while (temp == 'Y' || temp == 'y');
                    break;
                
            }
            case 4:{
            
                BeatPtr = GroupCalculation(BeatList, BeatMap, SPYptr);
                MeetPtr = GroupCalculation(MeetList, MeetMap, SPYptr);
                MissPtr = GroupCalculation(MissList, MissMap, SPYptr);
                
                double Time[120];
                for(int i=0;i<120;i++){
                    Time[i] = i-59;
                }
                
                vector<double> yData = BeatPtr->GetAvgCAAR();
                vector<double> yData2 = MeetPtr->GetAvgCAAR();
                vector<double> yData3 = MissPtr->GetAvgCAAR();
                
                plotResults(Time,yData, yData2, yData3, 120);
                cout << "Graph drawn" << endl
                     << endl;
                break;
                
            }
                
            
            case 5:{
                cout << "Promgram terminated!" << endl
                     << endl
                     << endl
                     << endl
                     << endl
                     << "Good luck with your finals and have a good summer vacation!!!!!!!!" << endl
                     << endl
                     << endl;
                break;
            }
        }
    }
    while(Option >0 && Option <5);
    
return 0;
}
