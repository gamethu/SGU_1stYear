#include<iostream>
using namespace std;
int C(int k,int n);
void printPascalTriangle(int h);
int main(){
    int k,n,h;
    do
    {
        cin>>n>>k>>h;
        if(n<0||k<0||k>n||h<1){
            cout<<"Wrong data!!! Pls type again"<<endl;
        }
    } while (n<0||k<0||k>n||h<1);
    cout<<"a)He so nhi thuc C "<<k<<" "<<n<<" = "<<C(k,n)<<endl;
    cout<<"b)Tam giac Pascal co chieu cao "<<h<<" la : "<<endl;
    printPascalTriangle(h);
    return 0;
}
int C(int k,int n){
    if(k==0||k==n) return 1;
    return C(k-1,n-1)+C(k,n-1);
}
void printPascalTriangle(int h){
    for(int i=0;i<h;i++){
     for(int j=0;j<=i;j++){
      cout<<C(j,i)<<" ";
     }
     cout<<endl;
    }
}