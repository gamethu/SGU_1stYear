#include<iostream>
#include<math.h>
using namespace std;
void inArray(int *a,int num);
void outArray(int *a,int num);
void deleteDigit(int *a,int &num,int k);
void insertDigit(int *a,int &num,int k,int x);
int prime(int n);
int main(){
    int num;
    cin>>num;
    int *a=new int[num];
    if(!a){
        cout<<"Not enough memory!";
        exit(0);
    }
    inArray(a,num);
    int k,x;
    cout<<"a)Pls type the position which you want me to delete : ";
    cin>>k;deleteDigit(a,num,k-1);
    outArray(a,num);
    cout<<"b)Pls type the position and number which you want me to insert : ";
    cin>>k>>x;insertDigit(a,num,k,x);
    outArray(a,num);
    cout<<"c)Array after remove prime numbers: ";
    for(int i=0;i<num;i++){
        if(prime(*(a+i))==1){
            deleteDigit(a,num,i);
            i--;
        }
    }
    outArray(a,num);
    delete a;
    return 0;
}
void inArray(int *a,int num){
    for(int i=0;i<num;i++){
        cin>>*(a+i);
    }
}
void outArray(int *a,int num){
    cout<<"Array includes: ";
    for(int i=0;i<num;i++){
        cout<<*(a+i)<<" ";
    }
    cout<<endl;
}
void deleteDigit(int *a,int &num,int k){
    for(int i=k;i<num-1;i++){
        *(a+i)=*(a+i+1);
    }
    num--;
}
void insertDigit(int *a,int &num,int k,int x){
    for(int i=num;i>k-1;i--){
        *(a+i)=*(a+i-1);
        a[k-1]=x;
        num++;
    }
}
int prime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
