#include<iostream>
#include<cmath>
using namespace std;
int math();
float mathf();
int main(){
    int choice;
    int ans;
    float f;
    cout<<"enter choice, 1=integers, 2=float"<<endl;
    cin>>choice;
    if(choice==1){
        ans=math();
        cout<<ans<<endl;
    }
    else if(choice==2){
        f=mathf();
        cout<<f<<endl;
    }
    else{
        cout<<"invalid"<<endl;
    }
    return 0;
}
int math(){
    cout<<"enter operands"<<endl;
    int o1, o2;
    int ans;
    cin>>o1;
    cin>>o2;
    cout<<"enter operator, + - * / p, if invalid will output random number"<<endl;
    char op;
    cin>>op;
    if(op=='+')
        ans=o1+o2;
    else if(op=='-')
        ans=o1-o2;
    else if(op=='*')
        ans=o1*o2;
    else if(op=='/')
        ans=o1/o2;
    else if(op=='p'||op=='P'){
        int o1b=o1;
        if(o2==1){
            ans=o1;
        }
        else{
            for(int i=1; i<o2; i++){
                ans=o1*o1b;
                o1=ans;
            }
        }
    }
    else{
        cout<<"invalid"<<endl;
    }
    return ans;
}
float mathf(){
    cout<<"enter operands"<<endl;
    float o1, o2;
    float ans;
    cin>>o1;
    cin>>o2;
    cout<<"enter operator, + - * / p, if invalid will output random number"<<endl;
    char op;
    cin>>op;
    if(op=='+')
        ans=o1+o2;
    else if(op=='-')
        ans=o1-o2;
    else if(op=='*')
        ans=o1*o2;
    else if(op=='/')
        ans=o1/o2;
    else if(op=='p'||op=='P')
        ans=pow(o1, o2);
    else
        cout<<"invalid"<<endl;
    return ans;
}
