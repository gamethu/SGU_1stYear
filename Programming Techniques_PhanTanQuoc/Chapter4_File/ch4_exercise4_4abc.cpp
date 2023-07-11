#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
#define MAX 500
void read2File(int a[MAX][MAX],int &m,int &num);
void write2File(int a[MAX][MAX],int m,int num);
int prime(int n);
int TaskA(int a[MAX][MAX],int m, int num);
int TaskC(int a[MAX][MAX],int m, int num);
int main(){
    int a[MAX][MAX],m,num;
    read2File(a,m,num);
    write2File(a,m,num);
    return 0;
}
void read2File(int a[MAX][MAX],int &m,int &num){
    FILE *fp=fopen("table.txt","rt");
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
    // TaskA
    fprintf(fp,"%d ",TaskA(a,m,num));
    int count=0,x=TaskA(a,m,num);
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            if(a[i][j]==x)count++;   
        }
    }
    fprintf(fp,"%d\n",count);
    // TaskB
    int max=0;
    for(int j=0;j<num;j++){
        for(int i=0;i<m;i++){
            max=max+a[i][j];
        }
        fprintf(fp,"%d ",max);
        max=0;
    }
    fprintf(fp,"\n%d\n",TaskC(a,m,num)); // TaskC
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
    int max=a[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            if(a[i][j]>max)max =a[i][j];   
        }
    }
    return max;
}
int TaskC(int a[MAX][MAX],int m, int num){
    int max;
    int b=-1;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<num-1;j++){
            if(prime(a[i][j])==1&&prime(a[i][j+1])==1&&prime(a[i+1][j])==1&&prime(a[i+1][j+1])==1)
                max=max+a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
        }
        if(b<max)b=max;
        max=0;
    }
    return b;
}