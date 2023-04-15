#include<iostream>
#include<conio.h>
int tinhX(int num);
using namespace std;
int main(){
    int num;
    cin>>num;
    cout<<"a)X7 = "<<tinhX(7)<<endl;
    cout<<"b)X"<<num<<" = "<<tinhX(num)<<endl;
    getch();
}
int tinhX(int num){
    if(num==0||num==1) return 1;
    int s=0;
    for(int i=0;i<num;i++){
        s=s+(num-i)*tinhX(i);
    }
    return s;
}
