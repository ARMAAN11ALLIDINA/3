#include<iostream>
#include<string>
#include<vector>
using namespace std;
void sort(vector<int>, int);
bool linearSearch(const vector<int>, int, int, int&);
bool binarySearch(const vector<int>, int, int, int&);
void searchAndReport(const vector<int>, int, int, string, bool (*search)(const vector<int>, int, int, int &));
int main(){
   vector<int> v;
   int n=0;
   int colour;
   cout<<"Enter a colour(0 when done) ";
   cin>>colour;
   while(colour!=0){
  	v.push_back(colour);
  	n++;
  	cout<<"Enter a colour(0 when done) ";
  	cin>>colour;
   }
   sort(v, n);
   cout<<"\nEnter a colour to search for (0 when done): ";
   cin>>colour;
   while(colour!=0){
  	searchAndReport(v, n, colour,"linear search",linearSearch);
  	searchAndReport(v, n, colour,"binary search",binarySearch);
  	cout<<"Enter a colour to search for (0 when done): ";
  	cin>>colour;
   }
   return 0;
}
void sort(vector<int> v, int n){
    int temp;
    for(int i=0; i<n-1; i++){
  	if(v[i]>v[i+1]){
     temp=v[i];
     v[i]=v[i+1];
     v[i+1]=temp;
  	}
   }
}
bool linearSearch(const vector<int> v, int n, int colour, int &count){
   count=0;
   for(int i=0; i<n; i++){
  	if(v[i]==colour){
     count++;
     return true;
  	}
  	else{
     count++;
  	}
   }
   return false;
}
bool binarySearch(const vector<int> v, int n, int colour, int &count){
   int mid=n/2;
   int beg = 0;
   int end = n - 1;
   while(beg <= end){
  	mid = (beg+end)/2;
  	if(v[mid] == colour)
  	{
     count++;
     return true;
  	}
  	else if(colour < v[mid]){
     end = mid-1;
     count++;
  	}
  	else if(colour>v[mid]){
     beg = mid+1;
     count++;
  	}
  	else{
     count=n;
     return true;
  	}
   }
   return false;
}
void searchAndReport(const vector<int> v, int n, int colour, string label, bool (*search)(const vector<int> v, int n, int colour, int &count)){
   int count=0;
   if(search(v, n, colour, count)){
  	cout<<"found "<<label<<" comparisions = "<<count<<" "<<endl;
   }
   else{
  	cout<<"not found "<<label<<" comparisions = "<<count<<" "<< endl;
   }
}

