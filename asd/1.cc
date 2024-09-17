#include<iostream>
using namespace std;
int main(){
    cout<<"enter height in feet with remaining inches seperatly"<<endl;
    int heightInFeet;
    int heightInInches;
    float heightInMeters;
    float heightInCentimeters;
    int totalHeight;
    cin>>heightInFeet;
    cin>>heightInInches;
    heightInMeters=heightInFeet*0.3048;
    heightInCentimeters=heightInInches*2.54;
    totalHeight=heightInMeters*100+heightInCentimeters;
    cout<<"Feet="<<heightInFeet<<endl;
    cout<<"Inches="<<heightInInches<<endl;
    cout<<"Meter="<<heightInMeters<<endl;
    cout<<"Centimeters="<<heightInCentimeters<<endl;
    cout<<"Height="<<totalHeight<<endl;
    return 0;
}

