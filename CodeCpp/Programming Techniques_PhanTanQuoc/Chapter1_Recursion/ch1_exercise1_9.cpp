#include<iostream>
#include<conio.h>
#define max 1000
void nhapMang(int a[],int &n);
void xuatMang(int a[],int n);
void QuickSort(int a[],int left,int right);
void exchange (int &a,int &b);
using namespace std;
int main(){
    int a[max];
    int n;
    nhapMang(a,n);cout<<endl;
    QuickSort(a,0,n-1);
    xuatMang(a,n);
    getch();
}
void nhapMang(int a[],int &n){
 cin>>n;
 for(int i=0;i<n;i++){
    cin>>a[i];
 }
}
void xuatMang(int a[],int n){
 for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
 }
}
void QuickSort(int a[],int left,int right){
    int x=a[(left+right)/2];
    int i=left;
    int j=right;
    while(i<j){
        while(a[i]<x)i++;
        while(a[j]>x)j--;
        if(i<=j) exchange(a[i++],a[j--]);
    }
    if(left<j) QuickSort(a,left,j);
    if(i<right) QuickSort(a,i,right);
}
void exchange(int &a, int &b){
    int temp=a;
        a=b;
        b=temp;
}