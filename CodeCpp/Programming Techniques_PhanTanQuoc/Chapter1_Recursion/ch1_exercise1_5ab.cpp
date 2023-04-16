#include<iostream>
int x(int num);
using namespace std;
int main(){
    int num;
    cin>>num;
    cout<<"a)X7 = "<<x(7)<<endl;
    cout<<"b)X"<<num<<" = "<<x(num)<<endl;
    return 0;
}
int x(int num){
    if(num==1) return 1;
    int s=0;
    for(int i=1;i<num;i++){
        s=s+x(i);
    }
    return num*s;
}