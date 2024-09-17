#include <iostream>
using namespace std;
int main(){
    cout<<"enter birth year, month and day seperatly"<<endl;
   int birthYear;
   int month;
   int day;
   int finalYear;
   cin>>birthYear;
   cin>>month;
   cin>>day;
   finalYear=(birthYear*365.25+month*30+day+50000)/365.25;
   cout<<"Birth year="<<birthYear<<endl;
   cout<<"Month="<<month<<endl;
   cout<<"Day="<<day<<endl;
   cout<<"Year="<<finalYear<<endl;
   return 0;
}

