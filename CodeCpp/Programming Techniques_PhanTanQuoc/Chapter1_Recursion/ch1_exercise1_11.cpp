#include<iostream>
#define max 1000
void inArr(int a[],int num);
void outArr(int a[],int num);
void InsertHeap(int a[],int left,int right);
void CreateHeap(int a[],int num);
void HeapSort(int a[],int nm);
void exchange (int &a,int &b);
using namespace std;
int main(){
    int a[max];
    int num;
    cin>>num;
    inArr(a,num);cout<<endl;
    HeapSort(a,num);
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
void CreateHeap(int a[],int num){
    for(int k=(num+1)/2;k>=0;k--){
        InsertHeap(a,k,num-1);
    }
}
void HeapSort(int a[],int num){
    CreateHeap(a,num);
    for(int i=num-1;i>0;i--){
        exchange(a[0],a[i]);
        InsertHeap(a,0,i-1);
    }
}
