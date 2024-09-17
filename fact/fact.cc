#include<iostream>
using namespace std;
int fact(int);
int main(){
    char c;
    do{
        int x;
        cin>>x;
        int a;
        a=fact(x);
        cout<<a<<endl;
        cin>>c;
    }while(c=='y');
    return 0;
}
int fact(int x){
    if (x==0)
        return 1;
    else
        return x*fact(x-1);
}
