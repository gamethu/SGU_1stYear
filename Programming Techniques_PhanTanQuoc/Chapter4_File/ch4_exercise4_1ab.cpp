#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
#define MAX 10000
void read2File(int a[],int &num);
void write2File(int a[],int num);
int prime(int n);
void exchange(int &a,int &b);
int TaskA(int a[],int num);
void Intenchange_Sort(int a[],int num);
int main(){
    int a[MAX],num;
    read2File(a,num);
    write2File(a,num);
    return 0;
}
void read2File(int a[],int &num){
    FILE *fp=fopen("num.txt","rt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    fscanf(fp,"%d",&num);
    if(num<=0||num>MAX){
        cout<<"Data error";
        exit(1);
    }
    int digit;
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&digit);
        a[i]=digit;
    }
    fclose(fp);
}
void write2File(int a[],int num){
    FILE *fp=fopen("NUM.OUT","wt");
    fprintf(fp,"%d\n",TaskA(a,num)); // TaskA
    // TaskB
    Intenchange_Sort(a,num);
    for(int i=0;i<num;i++){
        fprintf(fp,"%d ",a[i]);
    }
    fclose(fp);
}
int prime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
void exchange(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int TaskA(int a[],int num){
    if(num==1) return a[0]%2==0;
    return a[num-1]%2==0+TaskA(a,num-1);
}
void Intenchange_Sort(int a[],int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(a[i]>a[j]) exchange(a[i],a[j]);
        }
    }
}