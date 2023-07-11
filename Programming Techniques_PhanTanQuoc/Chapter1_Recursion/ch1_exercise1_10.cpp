#include<iostream>
#define max 1000
void inArr(int a[],int num);
void outArr(int a[],int num);
void merge(int a[],int left,int mid,int right);
void MergeSort(int a[],int left,int right);
using namespace std;
int main(){
    int a[max];
    int num;
    cin>>num;
    inArr(a,num);
    MergeSort(a,0,num-1);
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
void merge(int a[],int left,int mid,int right){
    int k=left;
    int i=left;
    int j=mid+1;
    int b[max];
    while(k<=mid&&j<=right){
        if(a[k]<=a[j]) b[i++]=a[k++];
        else b[i++]=a[j++];
    }
    if(j<=right) for(int h=j;h<=right;h++) b[i++]=a[h];
    if(k<=mid) for(int h=k;h<=mid;h++) b[i++]=a[h];
    for(int s=left;s<=right;s++) a[s]=b[s];
}
void MergeSort(int a[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
