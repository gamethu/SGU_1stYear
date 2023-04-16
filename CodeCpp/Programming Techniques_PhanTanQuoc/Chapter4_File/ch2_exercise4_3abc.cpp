#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
int prime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int TaskA(int *a,int m, int num){
    int dem=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            if(prime(*(a+num*i+j))==1)dem++;   
        }
    }
    return dem;
}
int TaskB(int *a,int m, int num){
    int max;
    for(int j=0;j<num;j++){
        max=max+*(a+j);
    }
    int b=max;
    for(int i=1;i<m;i++){
        for(int j=0;j<num;j++){
            max=max+*(a+num*i+j);
        }
        if(b<max)b=max;
        max=0;
    }
    return b;
}
int TaskC(int *a,int m, int num){
    int max;
    for(int i=0;i<m;i++){
        max=max+*(a+num*i);
    }
    int b=max;
    for(int j=1;j<num;j++){
        for(int i=0;i<m;i++){
            max=max+*(a+num*i+j);
        }
        if(b>max)b=max;
        max=0;
    }
    return b;
}
int main(){
    // đọc file
    FILE *fp=fopen("table.inp","rt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    int m,num;
    fscanf(fp,"%d %d",&m,&num);
    int *a;
    a=new int[m*num];
    int digit;
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            fscanf(fp,"%d",&digit);
            *(a+num*i+j)=digit;
        }
    }
    fclose(fp);
    // ghi file 
    FILE *fp1=fopen("table.out","wt");
    fprintf(fp1,"%d\n",TaskA(a,m,num)); // TaskA
    fprintf(fp1,"%d\n",TaskB(a,m,num)); // TaskB
    fprintf(fp1,"%d\n",TaskC(a,m,num)); // TaskC
    fclose(fp1);
    delete a;
    delete fp;
    delete fp1;
    return 0;
}