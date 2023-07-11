#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
#define MAX 10000
void read2File(int a[],int &num,int &m);
void write2File(int a[],int num,int m);
int TaskA(int a[],int num);
int TaskB(int a[],int num);
int TaskC(int a[],int num,int m);
void exchange(int &a,int &b);
int TaskD(int a[],int num);
void write2File(int a[],int num);
int main(){
    int a[MAX],num,m;
    read2File(a,num,m);
    write2File(a,num,m);
    return 0;
}
void read2File(int a[],int &num,int &m){
    FILE *fp=fopen("num.txt","rt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    fscanf(fp,"%d %d",&num,&m);
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
void write2File(int a[],int num,int m){
    FILE *fp=fopen("NUM.OUT","wt");
    fprintf(fp,"%d\n%d\n%d\n%d\n",TaskA(a,num),/*TaskB(a,num)*/,TaskC(a,num,m),TaskD(a,num));
    fclose(fp);
}
int TaskA(int a[],int num){
    int max=a[0];
    for(int i=1;i<num;i++){
        if(a[i]<max)max=a[i];
    }
    return max;
}
// int TaskB(int a[],int num){
//     int d=0;
//     int max=0;
//     for(int i=0;i<num-1;i++){
//         if(a[i]>a[i+1])d++;
//         else{
//             if(d>max){
//                 max=d;
//                 d=0;
//             }
//         }
//     }
//     return max;
// }
int TaskC(int a[],int num,int m){
    int d=0;
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(a[i]+a[j]==m)d++;
        }
    }
    return d;
}
void exchange(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int TaskD(int a[],int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(a[i]>a[j]) exchange(a[i],a[j]);
        }
    }
    return a[num/2];
}