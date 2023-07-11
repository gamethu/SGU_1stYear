#include<iostream>
#define max 1000
void inArr(int a[],int num);
void outArr(int a[],int nm);
void QuickSort(int a[],int left,int right);
void exchange (int &a,int &b);
using namespace std;
int main(){
    int a[max];
    int num;
    cin>>num;
    inArr(a,num);
    QuickSort(a,0,num-1);
    outArr(a,num);
    return 0;
}
void inArr(int a[],int num){
 for(int i=0;i<num;i++){
    cin>>a[i];
 }
}
void outArr(int a[],int num){
 for(int i=0;i<num;i++){
    cout<<a[i]<<" ";
 }
}
void QuickSort(int a[],int left,int right){
    int x=a[(left+right)/2],i=left,j=right;
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