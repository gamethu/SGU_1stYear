#include<iostream>
#include<conio.h>
#define max 1000
void nhapMang(int a[],int n);
void xuatMang(int a[],int n);
void InsertHeap(int a[],int left,int right);
void CreateHeap(int a[],int n);
void HeapSort(int a[],int n);
void exchange (int &a,int &b);
using namespace std;
int main(){
    int a[max];
    int n;
    cin>>n;
    nhapMang(a,n);cout<<endl;
    HeapSort(a,n);
    xuatMang(a,n);
    getch();
}
void nhapMang(int a[],int n){
 for(int i=0;i<n;i++){
    cin>>a[i];
 }
}
void xuatMang(int a[],int n){
 for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
 }
}
void exchange(int &a, int &b){
    int temp=a;
        a=b;
        b=temp;
}
void InsertHeap(int a[],int left,int right){
    int p=2*left;
    if(p>right) return;
    if(p<right) 
     if(a[p]<a[p+1]) p++;
    if(a[left]<a[p]){
        exchange(a[left],a[p]);
        InsertHeap(a,p,right);
    }
}
void CreateHeap(int a[],int n){
    for(int k=(n+1)/2;k>=0;k--){
        InsertHeap(a,k,n-1);
    }
}
void HeapSort(int a[],int n){
    CreateHeap(a,n);
    for(int i=n-1;i>0;i--){
        exchange(a[0],a[i]);
        InsertHeap(a,0,i-1);
    }
}
