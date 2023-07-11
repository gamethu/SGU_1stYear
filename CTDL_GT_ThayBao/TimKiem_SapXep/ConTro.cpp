#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<ctime>
void inArray(int *a,int n);
void outArray(int *a,int n);
using namespace std;
int main(){
    int *a;
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Error 404!!!";
        exit(0);
    }
    a=new int[n];
    if(!a){
        cout<<"Not enough memory";
        exit(0);
    }
    inArray(a,n);
    // Sắp xếp + Tìm kiếm vứt vào đây
    outArray(a,n);cout<<endl;
    delete []a;
    getch();
}
void inArray(int *a,int n){
 int x;
 for(int i=0;i<n;i++){
    x=rand()-rand();
    if(x==0){
        i--;
        break;
    }
    a[i]=x;
 }
}
void outArray(int *a,int n){
 cout<<"Data of array A: "<<endl;
 for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
 }
}










