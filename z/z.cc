#include<iostream>
using namespace std;
int main(){
   int numberOfTerms;
   int m, m2, mn;
   int term;

   m=1;
   m2=1;
   cout<<"Enter number of terms of Fibonacci series you want"<<endl;
   cin>>numberOfTerms;

   cout<<"First "<<numberOfTerms<<" terms of Fibonacci series are "<<endl;

   for(term=0; term<numberOfTerms; term++){
  	if(term<=1)
     mn=m;
  	else{
     mn=m+m2;
     m=m2;
     m2=mn;
  	}
  	cout<<mn<<endl;
   }
   return 0;
}
