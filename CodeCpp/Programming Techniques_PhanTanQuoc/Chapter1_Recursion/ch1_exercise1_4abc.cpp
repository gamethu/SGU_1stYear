#include<iostream>
#include<conio.h>
using namespace std;
int tinhFN_DeQuy(int num);
int tinhFN_KhuDeQuy(int num);
double tinhSN_DeQuy(int num);
double tinhSN_KhuDeQuy(int num);
int main(){
  int num;
  cin>>num;
  cout<<"a)S5 = "<<tinhSN_DeQuy(5)<<endl;
  cout<<"b)S"<<num<<" = "<<tinhSN_DeQuy(num)<<endl;
  cout<<"c)S"<<num<<" = "<<tinhSN_KhuDeQuy(num)<<endl;
  getch();
}
int tinhFN_DeQuy(int num){
  if(num==1||num==2) return 1;
 return tinhFN_DeQuy(num-1) + tinhFN_DeQuy(num-2);
}
double tinhSN_DeQuy(int num){
  if(num==1) return 1.0/2;
  return (num*1.0)/(1+tinhFN_DeQuy(num)) + tinhSN_DeQuy(num-1);
}
int tinhFN_KhuDeQuy(int num){
 int f=1,f2=1,f1=1;
 for(int i=3;i<=num;i++){
  f=f2+f1;
  f1=f2;
  f2=f;
 }
 return f;
}
double tinhSN_KhuDeQuy(int num){
  float s=0;
  for(int i=num;i>0;i--){
    s=s+(i*1.0)/(1+tinhFN_KhuDeQuy(i));
  }
  return s;
}
