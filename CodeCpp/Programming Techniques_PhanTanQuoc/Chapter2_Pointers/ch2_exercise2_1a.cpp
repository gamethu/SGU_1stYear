#include<iostream>
#include<conio.h>
using namespace std;
void inArray(int *a,int num);
void outArray(int *a,int num);
void deleteDigit(int *a,int &num,int k);
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
    int k;
    cout<<"Pls type the position which you want me to delete : ";cin>>k;
    deleteDigit(a,num,k);
    outArray(a,num);
    delete a;
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
    for(int i=k-1;i<num-1;i++){
        *(a+i)=*(a+i+1);
    }
    num--;
}