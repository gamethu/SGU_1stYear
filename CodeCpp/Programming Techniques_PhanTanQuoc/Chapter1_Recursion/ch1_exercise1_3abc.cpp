#include<iostream>
#include<conio.h>
#include<math.h>
int tinhXN_DeQuy(int num);
int tinhYN_DeQuy(int num);
int tinhXN_KhuDeQuy(int num);
int tinhYN_KhuDeQuy(int num);
using namespace std;
int main(){
  int num;
  cin>>num;
  cout<<"a)x3 = "<<tinhXN_DeQuy(3)<<" va y3= "<<tinhYN_DeQuy(3)<<endl;
  cout<<"b)x"<<num<<" = "<<tinhXN_DeQuy(num)<<" va y"<<num<<" = "<<tinhYN_DeQuy(num)<<endl;
  cout<<"c)x"<<num<<" = "<<tinhXN_KhuDeQuy(num)<<" va y"<<num<<" = "<<tinhYN_KhuDeQuy(num)<<endl;
  getch();
}
int tinhXN_DeQuy(int num){
    if(num==0) return 1;
    return (1.0/3)*tinhXN_DeQuy(num-1)+(1.0/2)*tinhYN_DeQuy(num-1)+27;
}
int tinhYN_DeQuy(int num){
    if(num==0) return 2;
    return (1.0/5)*tinhXN_DeQuy(num-1)+(1.0/7)*tinhYN_DeQuy(num-1)+11 ;
}
// int tinhXN_KhuDeQuy(int n){
//  int f=1,x=2,y=1;
//   for(int i=1;i<=n;i++){
//     f=(1.0/3)*y+(1.0/2)*x+27;
//     x=y;
//     y=f;
//   }
//   return f;
// }
// int tinhYN_KhuDeQuy(int n){
//  int f=1,x=2,y=1;
//   for(int i=1;i<=n;i++){
//     f=(1.0/5)*y+(1.0/7)*x+11;
//     x=y;
//     y=f;
//   }
//   return f;
// }