#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
using namespace std;
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
int TaskA(int *a,int num){
    int dem=0;
    for(int i=0;i<num;i++){
        if(prime(a[i])==1) dem++;
    }
    return dem;
}
void Intenchange_Sort(int *a,int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(a[i]>a[j]) exchange(a[i],a[j]);
        }
    }
}
int main(){
    // đọc file
    FILE *fp=fopen("NUM.INP","rt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    int num;
    fscanf(fp,"%d",&num);
    if(num<=0){
        cout<<"Data error";
        exit(1);
    }
    int *a=new int[num];
    if(!a){
        cout<<"Data error";
        exit(1);
    }
    int digit;
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&digit);
        a[i]=digit;
    }
    fclose(fp);
    // ghi file
    FILE *fp1=fopen("NUM.OUT","wt");
    fprintf(fp1,"%d",TaskA(a,num)); // TaskA
    fprintf(fp1,"\n");
    // TaskB
    Intenchange_Sort(a,num);
    for(int i=0;i<num;i++){
        fprintf(fp1,"%d ",a[i]);
    }
    //
    fclose(fp1);
    delete a;
    delete fp;
    delete fp1;
    return 0;
}