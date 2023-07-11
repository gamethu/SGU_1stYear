#include<iostream>
#include<fstream>
#include<cmath>
void read2File(int a[500][500],int &m,int &n);
int prime(int n);
void TaskA(int a[500][500],int m,int n);
int cp(int n);
void TaskB(int a[500][500],int m,int n);
int hoanchinh(int n);
void TaskC(int a[500][500],int m,int n);
void TaskD(int a[500][500],int m,int n);
int canxung(int n);
void TaskE(int a[500][500],int m,int n);
void TaskF(int a[500][500],int m,int n);
int countDigit(int n);
void TaskG(int a[500][500],int m,int n);
void TaskH(int a[500][500],int m,int n);
int isFibo(int n);
void TaskI(int a[500][500],int m,int n);
using namespace std;
int main(){
    int a[500][500],m,n;
    read2File(a,m,n);
    TaskA(a,m,n);
    TaskB(a,m,n);
    TaskC(a,m,n);
    TaskD(a,m,n);
    TaskE(a,m,n);
    TaskF(a,m,n);
    TaskG(a,m,n);
    TaskH(a,m,n);
    TaskI(a,m,n);
    return 0;
}
void read2File(int a[500][500],int &m,int &n){
    FILE *fp=fopen("table.txt","rt");
    fscanf(fp,"%d %d",&m,&n);
    int digit;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            fscanf(fp,"%d",&digit);
            a[i][j]=digit;
        }
    }
    fclose(fp);
}
int prime(int n){
    if(n<2)return 0;
    for(int i=2;i<n;i++){
        if(n%i==0)return 0;
    }
    return 1;
}
void TaskA(int a[500][500],int m,int n){
    int d=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d=d+prime(a[i][j]);
        }
    }
    cout<<"a)"<<d<<endl;
}
int cp(int n){
    int m=sqrt(n);
    return m*m==n;
}
void TaskB(int a[500][500],int m,int n){
    int d=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d=d+cp(a[i][j]);
        }
    }
    cout<<"b)"<<d<<endl;
}
int hoanchinh(int n){
    int d=0;
    int s=n;
    int i=1;
    while(i<s&&n>0){
        if(n%i==0){
            d=d+i;
            n=n/i;
        }
        i++;
    }
    return d==s;
}
void TaskC(int a[500][500],int m,int n){
    int d=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d=d+hoanchinh(a[i][j]);
        }
    }
    cout<<"c)"<<d<<endl;
}
void TaskD(int a[500][500],int m,int n){
    int max=a[0][0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(max<a[i][j])max=a[i][j];
        }
    }
    int d=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(max==a[i][j])d++;
        }
    }
    cout<<"d)"<<d<<endl;
}
int canxung(int n){
    int d=0;
    int s=n;
    while(n!=0){
        d=d*10+n%10;
        n=n/10;
    }
    return d==s;
}
void TaskE(int a[500][500],int m,int n){
    int d=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d=d+canxung(a[i][j]);
        }
    }
    cout<<"e)"<<d<<endl;
}
void TaskF(int a[500][500],int m,int n){
    long int maxDong=a[0][0];
    for(int j=1;j<n;j++){
        if(maxDong<a[0][j])maxDong=a[0][j];
    }
    long int minDong=maxDong;
    for(int i=1;i<m;i++){
        maxDong=a[i][0];
        for(int j=1;j<n;j++){
            if(maxDong<a[i][j])maxDong=a[i][j];
        }
        if(minDong>maxDong)minDong=maxDong;
    }
    cout<<"f)"<<minDong<<endl;
}
int countDigit(int n){
    int d=0;
    while(n>0){
        d=d+n%10;
        n=n/10;
    }
    return d;
}
void TaskG(int a[500][500],int m,int n){
    int max=countDigit(a[0][0]);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(max<countDigit(a[i][j]))max=countDigit(a[i][j]);
        }
    }
    cout<<"g)"<<max<<endl;
}
void TaskH(int a[500][500],int m,int n){
    long int s=0;
    for(int i=0;i<m;i++){
        s=s+a[i][0];
    }
    long int minCot=s;
    for(int j=1;j<n;j++){
        for(int i=0;i<m;i++){
            s=s+a[i][j];
        }
        if(minCot>s)minCot=s;
        s=0;
    }
    cout<<"h)"<<minCot<<endl; 
}
int isFibo(int n){
    return cp(5*n*n+4)||cp(5*n*n-4);
}
void TaskI(int a[500][500],int m,int n){
    int d=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            d=d+isFibo(a[i][j]);
        }
    }
    cout<<"i)"<<d<<endl;
}