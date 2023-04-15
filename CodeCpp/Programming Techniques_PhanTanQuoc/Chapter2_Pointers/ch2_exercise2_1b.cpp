#include<iostream>
#include<conio.h>
using namespace std;
void inArray(int *a,int num);
void outArray(int *a,int num);
void insertDigit(int *a,int &num,int k,int x);
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
    int k,x;
    cout<<"Pls type the position and number which you want me to insert : ";cin>>k>>x;
    insertDigit(a,num,k,x);
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
void insertDigit(int *a,int &num,int k,int x){
    for(int i=num;i>k;i--){
        *(a+i)=*(a+i-1);
        a[k]=x;
        num++;
    }
}