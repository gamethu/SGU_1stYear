#include<iostream>
#include<math.h>
int caua(int num);
int caub(int num);
int cauc(int num);
int caud(int num);
using namespace std;
int main(){
  int num,s;
  cin>>num;
  cout<<"a)S = "<<caua(num)<<endl;
  cout<<"b)S = "<<caub(num)<<endl;
  cout<<"c)S = "<<cauc(num)<<endl;
  cout<<"d)S = "<<caud(num)<<endl;
  return 0;
}
int caua(int num){
  if(num==1) return 1;
  return num+caua(num-1);
}
int caub(int num){
  if(num==1) return 1;
  return pow(num,2)+caub(num-1);
}
int cauc(int num){
  if(num==1) return 1;
  int s=1;
  for(int i=num;i>0;i--){
    s=s*i;
  }
  return s+cauc(num-1);
}
int caud(int num){
  if(num==1) return 2;
  int s=1;
  for(int i=num;i<=2*num;i++){
    s=s*i;
  }
  return s+caud(num-1);
}