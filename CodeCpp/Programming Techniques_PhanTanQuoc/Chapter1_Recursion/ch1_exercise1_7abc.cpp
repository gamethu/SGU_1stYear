#include<iostream>
#include<conio.h>
#define max 100
using namespace std;
void nhapMang(int a[], int num);
void xuatMang(int a[], int num);
int tongN(int a[], int num);
int Max(int a[], int num);
int snt(int num);
int countN(int a[], int num,int dem);
int main(){
    int a[max];
    int num;
    int dem;
    cin>>num;
    nhapMang(a,num);cout<<endl;
    xuatMang(a,num);cout<<endl;
    cout<<"a)Tong Cua "<<num<<" Phan Tu Tren = "<<tongN(a,num)<<endl;
    cout<<"b)Max Trong "<<num<<" Phan Tu Tren = "<<Max(a,num)<<endl;
    cout<<"c)Tong SNT Trong "<<num<<" Phan Tu Tren = "<<countN(a,num,0)<<endl;
    getch();
}
void nhapMang(int a[], int num){
 for(int i=0;i<num;i++){
    cin>>a[i];
 }
}
void xuatMang(int a[], int num){
  for(int i=0;i<num;i++){
    cout<<" "<<a[i];
 }  
}
int tongN(int a[], int num){
 if(num==1) return a[0];
 return a[num-1]+tongN(a,num-1);
}
int Max(int a[], int num){
  if(num==1) return a[0];  
  if(a[num-1]>Max(a,num-1))
   return a[num-1];
  return Max(a,num-1);
}
int snt(int num){
 if(num<2) return 0;
 for(int i=2;i<num;i++){
 if(num%i==0) return 0;
 }
 return 1;
}
int countN(int a[], int num, int dem){
 if(num==0) return dem;
 if(snt(a[num-1])==1) dem++;
  return countN(a,num-1,dem);
 return countN(a,num-1,dem);
}