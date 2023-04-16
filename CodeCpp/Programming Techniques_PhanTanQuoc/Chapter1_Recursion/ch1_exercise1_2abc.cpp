#include<iostream>
#include<math.h>
int xn_Res(int num);
int xn_nonRes(int num);
using namespace std;
int main(){
  int num;
  cin>>num;
  cout<<"a)f7 = "<<xn_Res(7)<<endl;
  cout<<"b)f"<<num<<" = "<<xn_Res(num)<<endl;
  cout<<"c)f"<<num<<" = "<<xn_nonRes(num)<<endl;
  return 0;
}
int xn_Res(int num){
  if(num==1||num==2) return 1;
  return xn_Res(num-1)+(num-1)*xn_Res(num-2);
}
int xn_nonRes(int num){
  int f=1,f2=1,f1=1;
  for(int i=3;i<=num;i++){
    f=f2+(i-1)*f1;
    f1=f2;
    f2=f;
  }
  return f;
}