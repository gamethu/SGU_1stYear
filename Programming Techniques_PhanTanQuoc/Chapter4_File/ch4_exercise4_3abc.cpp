#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
#define MAX 200
void read2File(int a[MAX][MAX],int &m,int &num);
void write2File(int a[MAX][MAX],int m,int num);
int prime(int n);
int TaskA(int a[MAX][MAX],int m, int num);
int TaskB(int a[MAX][MAX],int m, int num);
int TaskC(int a[MAX][MAX],int m, int num);
int main(){
    int a[MAX][MAX],m,num;
    read2File(a,m,num);
    write2File(a,m,num);
    return 0;
}
void read2File(int a[MAX][MAX],int &m,int &num){
    FILE *fp=fopen("table.inp","rt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    fscanf(fp,"%d %d",&m,&num);
    if(!(m>0&&m<=MAX&&num>0&&num<=MAX)){
        cout<<"Data error";
        exit(1);
    }
    int digit;
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            fscanf(fp,"%d",&digit);
            a[i][j]=digit;
        }
    }
    fclose(fp);
}
void write2File(int a[MAX][MAX],int m,int num){
    FILE *fp=fopen("table.out","wt");
    fprintf(fp,"%d\n%d\n%d\n",TaskA(a,m,num),TaskB(a,m,num),TaskC(a,m,num));
    fclose(fp);
}
int prime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int TaskA(int a[MAX][MAX],int m, int num){
    int dem=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            dem=dem+prime(a[i][j]);  
        }
    }
    return dem;
}
int TaskB(int a[MAX][MAX],int m, int num){
    int max;
    for(int j=0;j<num;j++){
        max=max+a[0][j];
    }
    int b=max;
    for(int i=1;i<m;i++){
        for(int j=0;j<num;j++){
            max=max+a[i][j];
        }
        if(b<max)b=max;
        max=0;
    }
    return b;
}
int TaskC(int a[MAX][MAX],int m, int num){
    int max;
    for(int i=0;i<m;i++){
        max=max+a[i][0];
    }
    int b=max;
    for(int j=1;j<num;j++){
        for(int i=0;i<m;i++){
            max=max+a[i][j];
        }
        if(b>max)b=max;
        max=0;
    }
    return b;
}