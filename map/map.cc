#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cctype>
#include<algorithm>
#include<iomanip>
using namespace std;
char lower(int);
void printMap(const map<string,int>&);
bool great(const pair <int,string>&, const pair <int,string>&);
int main(){
   map<string,int>frequency;
   vector<pair <int,string> > v;
   string word;
   cout<<"enter words(done when finished entering)"<<endl;
   while(word!="done"){
        cin>>word;
        if(word!="done"){
            transform(word.begin(),word.end(),word.begin(),lower);
            frequency[word]++;
        }
    }
    cout<<"alphabetical order"<<endl;
    printMap(frequency);
    for(auto it=frequency.begin(); it!=frequency.end(); ++it){
        v.push_back(make_pair(it->second,it->first));
    }
   cout<<endl;
   cout<<"numerical order"<<endl;
   sort(v.begin(),v.end(),great);
   cout<<"Frequency"<<' '<<"Word"<<endl;
   cout<<"---------"<<' '<<"--------------------"<<endl;
   for(int i=0;i!=v.size(); i++){
  	cout<<setw(9)<<right<<v[i].first<<' '<<left<<v[i].second<<endl;
   }
   return 0;
}
char lower(int a){
   return tolower(a);
}
void printMap(const map<string,int>& A){
   cout<<"Word"<<setw(25)<<"Frequency"<<endl;
   cout<<"--------------------"<<setw(5)<<"---------"<<endl;
   for(auto it=A.begin(); it!=A.end(); ++it){
  	cout<<setw(25)<<left<<it->first<<setw(25)<<it->second<<endl;
   }
}
bool great(const pair<int,string>& a, const pair <int,string>& b){
   return(a.first>b.first);
}

