#include<iostream>
#include<math.h>
int TaskA(int num);
int TaskB(int num);
int TaskC(int num);
int TaskD(int num);
using namespace std;
int main(){
  int num,s;
  cin>>num;
  cout<<"a)S = "<<TaskA(num)<<endl;
  cout<<"b)S = "<<TaskB(num)<<endl;
  cout<<"c)S = "<<TaskC(num)<<endl;
  cout<<"d)S = "<<TaskD(num)<<endl;
  return 0;
}
int TaskA(int num){
  if(num==1) return 1;
  return num+TaskA(num-1);
}
int TaskB(int num){
  if(num==1) return 1;
  return pow(num,2)+TaskB(num-1);
}
int TaskC(int num){
  if(num==1) return 1;
  int s=1;
  for(int i=num;i>0;i--){
    s=s*i;
  }
  return s+TaskC(num-1);
}
int TaskD(int num){
  if(num==1) return 2;
  int s=1;
  for(int i=num;i<=2*num;i++){
    s=s*i;
  }
  return s+TaskD(num-1);
}