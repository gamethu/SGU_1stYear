 #include<iostream>
using namespace std;
int fn_Res(int num);
int fn_nonRes(int num);
double sn_Res(int num);
double sn_nonRes(int num);
int main(){
  int num;
  cin>>num;
  cout<<"a)S5 = "<<sn_Res(5)<<endl;
  cout<<"b)S"<<num<<" = "<<sn_Res(num)<<endl;
  cout<<"c)S"<<num<<" = "<<sn_nonRes(num)<<endl;
  return 0;
}
int fn_Res(int num){
  if(num==1||num==2) return 1;
 return fn_Res(num-1) + fn_Res(num-2);
}
double sn_Res(int num){
  if(num==1) return 1.0/2;
  return (num*1.0)/(1+fn_Res(num)) + sn_Res(num-1);
}
int fn_nonRes(int num){
 int f=1,f2=1,f1=1;
 for(int i=3;i<=num;i++){
  f=f2+f1;
  f1=f2;
  f2=f;
 }
 return f;
}
double sn_nonRes(int num){
  float s=0;
  for(int i=num;i>0;i--){
    s=s+(i*1.0)/(1+fn_nonRes(i));
  }
  return s;
}
