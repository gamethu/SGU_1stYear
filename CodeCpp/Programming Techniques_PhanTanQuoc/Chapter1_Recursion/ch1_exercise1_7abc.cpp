#include<iostream>
#define max 1000
using namespace std;
void inArr(int a[], int num);
void outArr(int a[], int num);
int sumpN(int a[], int num);
int Max(int a[], int num);
int prime(int num);
int countN(int a[], int num,int count);
int main(){
    int a[max];
    int num;
    int count;
    cin>>num;
    inArr(a,num);
    outArr(a,num);
    cout<<"a)Tong Cua "<<num<<" Phan Tu Tren = "<<sumpN(a,num)<<endl;
    cout<<"b)Max Trong "<<num<<" Phan Tu Tren = "<<Max(a,num)<<endl;
    cout<<"c)Tong SNT Trong "<<num<<" Phan Tu Tren = "<<countN(a,num,0)<<endl;
    return 0;
}
void inArr(int a[], int num){
  for(int i=0;i<num;i++){
    cin>>a[i];
  }
  cout<<endl;
} 
void outArr(int a[], int num){
  for(int i=0;i<num;i++){
    cout<<" "<<a[i];
  }
  cout<<endl;  
}
int sumpN(int a[], int num){
 if(num==1) return a[0];
 return a[num-1]+sumpN(a,num-1);
}
int Max(int a[], int num){
  if(num==1) return a[0];  
  if(a[num-1]>Max(a,num-1))
   return a[num-1];
  return Max(a,num-1);
}
int prime(int num){
 if(num<2) return 0;
 for(int i=2;i<num;i++){
 if(num%i==0) return 0;
 }
 return 1;
}
int countN(int a[], int num, int count){
 if(num==0) return count;
 if(prime(a[num-1])==1) count++;
  return countN(a,num-1,count);
 return countN(a,num-1,count);
}