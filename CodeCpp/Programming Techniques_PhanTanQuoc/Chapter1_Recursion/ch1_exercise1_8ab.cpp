#include<iostream>
#include<conio.h>
using namespace std;
int C(int k,int n);
void veTgPascal(int h);
int main(){
    int k,n,h;
    cin>>k>>n>>h;
    cout<<"a)He so nhi thuc C "<<k<<" "<<n<<" = "<<C(k,n)<<endl;
    cout<<"b)Tam giac Pascal co chieu cao "<<h<<" la : "<<endl;
    veTgPascal(h);
    getch();
}
int C(int k,int n){
    if(k==0||k==n) return 1;
    return C(k-1,n-1)+C(k,n-1);
}
void veTgPascal(int h){
    int i,j;
    for(i=0;i<h;i++){
     for(j=0;j<=i;j++){
      cout<<C(j,i)<<" ";
     }
     cout<<endl;
    }
    cout<<endl;
}