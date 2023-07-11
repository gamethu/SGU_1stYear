#include<iostream>
#include<math.h>
using namespace std;
void inArray(int *a,int num);
void outArray(int *a,int num);
void TaskA(int *a,int &num);
void TaskB(int *a,int &num);
void TaskC(int *a,int &num);
int prime(int n);
int main(){
    int num;
    cin>>num;
    int *a=new int[num];
    if(!a){
        cout<<"Not enough memory!";
        exit(1);
    }
    inArray(a,num);
    TaskA(a,num);
    TaskB(a,num);
    TaskC(a,num);
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
void TaskA(int *a,int &num){
    int k;
    cout<<"a)Pls type the position which you want me to delete : ";
    cin>>k;
    if(k<1||k>num){
        cout<<"Data error!!!"<<endl;
        exit(1);
    }
    for(int i=k-1;i<num-1;i++){
        *(a+i)=*(a+i+1);
    }
    num--;
    outArray(a,num);
}
void TaskB(int *a,int &num){
    int k,x;
    cout<<"b)Pls type the position and number which you want me to insert : ";
    cin>>k>>x;
    if(k<1||k>num){
        cout<<"Data error!!!"<<endl;
        exit(1);
    }
    num++;
    for(int i=num;i>k-1;i--){
        *(a+i)=*(a+i-1);
    }
    *(a+k-1)=x;
    outArray(a,num);
}
void TaskC(int *a,int &num){
    cout<<"c)Array after remove prime numbers: "<<endl;
    for(int i=0;i<num;i++){
        if(prime(*(a+i))==1){
            for(int j=i;j<num-1;j++){
                *(a+j)=*(a+j+1);
            }
            num--;
            i--;
        }
    }
    outArray(a,num);
}
int prime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
