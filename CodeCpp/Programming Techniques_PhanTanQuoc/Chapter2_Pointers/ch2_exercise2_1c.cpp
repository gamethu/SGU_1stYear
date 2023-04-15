#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
void inArray(int *a,int num);
void outArray(int *a,int num);
void deleteDigit(int *a,int &num,int k);
int prime(int n);
int main(){
    int num;
    cin>>num;
    if(num<=0){
        cout<<"Data error";
        exit(0);
    }
    int *a;
    a=new int[num];
    if(!a){
        cout<<"Not enough memory!";
        exit(0);
    }
    inArray(a,num);
    for(int i=0;i<num;i++){
        if(prime(*(a+i))==1){
            deleteDigit(a,num,i);
            i--;
        }
    }
    outArray(a,num);
    delete []a;
    getch();
}
void inArray(int *a,int num){
    for(int i=0;i<num;i++){
        cin>>*(a+i);
    }
}
void outArray(int *a,int num){
    for(int i=0;i<num;i++){
        cout<<*(a+i)<<" ";
    }
}
void deleteDigit(int *a,int &num,int k){
    for(int i=k;i<num-1;i++){
        *(a+i)=*(a+i+1);
    }
    num--;
}
int prime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}