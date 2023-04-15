#include<iostream>
#include<math.h>
int tinhXN_DeQuy(int num);
int tinhXN_KhuDeQuy(int num);
using namespace std;
int main(){
  int num;
  cin>>num;
  cout<<"a)f7 = "<<tinhXN_DeQuy(7)<<endl;
  cout<<"b)f"<<num<<" = "<<tinhXN_DeQuy(num)<<endl;
  cout<<"c)f"<<num<<" = "<<tinhXN_KhuDeQuy(num)<<endl;
  return 0;
}
int tinhXN_DeQuy(int num){
    if(num==1||num==2) return 1;
    return tinhXN_DeQuy(num-1)+(num-1)*tinhXN_DeQuy(num-2);
}
int tinhXN_KhuDeQuy(int num){
  int f=1,f2=1,f1=1;
  for(int i=3;i<=num;i++){
    f=f2+(i-1)*f1;
    f1=f2;
    f2=f;
  }
  return f;
}