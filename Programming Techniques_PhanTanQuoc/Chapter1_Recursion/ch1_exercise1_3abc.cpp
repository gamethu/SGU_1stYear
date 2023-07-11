#include<iostream>
#include<math.h>
int xn_Res(int num);
int yn_Res(int num);
float xn_nonRes(int num);
float yn_nonRes(int num);
using namespace std;
int main(){
  int num;
  cin>>num;
  cout<<"a)x3 = "<<xn_Res(3)<<" va y3= "<<yn_Res(3)<<endl;
  cout<<"b)x"<<num<<" = "<<xn_Res(num)<<" va y"<<num<<" = "<<yn_Res(num)<<endl;
  // cout<<"c)x"<<num<<" = "<<xn_nonRes(num)<<" va y"<<num<<" = "<<yn_nonRes(num)<<endl;
  return 0;
}
int xn_Res(int num){
  if(num==0) return 1;
  return (1.0/3)*xn_Res(num-1)+(1.0/2)*yn_Res(num-1)+27;
}
int yn_Res(int num){
  if(num==0) return 2;
  return (1.0/5)*xn_Res(num-1)+(1.0/7)*yn_Res(num-1)+11 ;
}
// float xn_nonRes(int num){
//  float f=1,x=2,y=1;
//   for(int i=1;i<=num;i++){
//     f=(1.0/3)*y+(1.0/2)*x+27;
//     x=y;
//     y=f;
//   }
//   return f;
// }
// float yn_nonRes(int num){
//  float f=1,x=2,y=1;
//   for(int i=1;i<=num;i++){
//     f=(1.0/5)*y+(1.0/7)*x+11;
//     x=y;
//     y=f;
//   }
//   return f;
// }