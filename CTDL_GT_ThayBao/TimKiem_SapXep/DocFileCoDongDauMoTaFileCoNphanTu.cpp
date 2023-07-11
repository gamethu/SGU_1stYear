#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<math.h>
int snt(int n);
using namespace std;
int main(){
    FILE *fp;
    fp=fopen("data.in","rt");
    if(!fp){
        cout<<"Cant open this file!";
        exit(0);
    }
    int num;
    fscanf(fp,"%d",&num);
    if(num<=0){
        cout<<"This file was empty";
        fclose(fp);
        exit(0);
    }
    int *a;
    a=new int[num];
    if(!a){
        cout<<"Not enough memory!";
        fclose(fp);
        exit(0);
    }
    int digit;
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&digit);
        a[i]=digit;
    }
    fclose(fp);
    int dem=0;
    for(int i=0;i<num;i++){
        if(snt(a[i])==1) dem++;
    }
    cout<<"Numbers of digts : "<<num<<endl;
    cout<<"Numbers of prime digits: "<<dem<<endl;
    delete []a;
    getch();
}
int snt(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}