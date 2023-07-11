// 4 9 4 13 9 8 11 20 10
#include<iostream>
#include<math.h>
#define MAX 100000
using namespace std;
struct phanso{
    int tuso;
    int mauso;
};
phanso ps;
void write2File();
void read2File(phanso Arr[],int &num);
void TaskA(phanso Arr[],int num);
void TaskB(phanso Arr[],int num);
int prime(int n);
void TaskC(phanso Arr[],int num);
void TaskD(phanso Arr[],int num);
void TaskE(phanso Arr[],int num);
int UCLN(long int &a,long int &b);
int pstoigian(long int tuso,long int mauso);
void TaskF(phanso Arr[],int num);
int main(){
    phanso Arr[MAX];
    int num;
    //write2File();
    read2File(Arr,num);
    TaskA(Arr,num);
    TaskB(Arr,num);
    TaskC(Arr,num);
    TaskD(Arr,num);
    TaskE(Arr,num);
    TaskF(Arr,num);
    return 0;
}
void write2File(){
    FILE *fp=fopen("nump.txt","wb");
    int num;
    cin>>num;
    putw(num,fp);
    for(int i=0;i<num;i++){
       cin>>ps.tuso>>ps.mauso;
       fwrite(&ps,sizeof(ps),1,fp);
    }
    fclose(fp);
}
void read2File(phanso Arr[],int &num){
    FILE *fp=fopen("fract_b.txt","rb");
    num=getw(fp);
    for(int i=0;i<num;i++){
        fread(&ps,sizeof(ps),1,fp);
        Arr[i].tuso=ps.tuso;
        Arr[i].mauso=ps.mauso;
    }
    fclose(fp);
}
void TaskA(phanso Arr[],int num){
    int count=0;
    for(int i=0;i<num;i++){
        if(Arr[i].tuso<Arr[i].mauso) count++;
    }
    cout<<"a)"<<count<<endl;
}
void TaskB(phanso Arr[],int num){
    int count=0;
    for(int i=0;i<num;i++){
        if(Arr[i].tuso%Arr[i].mauso==0) count++;
    }
    cout<<"b)"<<count<<endl;
}
int prime(int n){
    if(n<2)return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return 0;
    }
    return 1;
}
void TaskC(phanso Arr[],int num){
    int count=0;
    for(int i=0;i<num;i++){
        if(prime(Arr[i].tuso)&&prime(Arr[i].mauso))count++;
    }
    cout<<"c)"<<count<<endl;
}
void TaskD(phanso Arr[],int num){
    int maxtu=Arr[0].tuso;
    int maxmau=Arr[0].mauso;
    for(int i=1;i<num;i++){
        if(maxtu*Arr[i].mauso<maxmau*Arr[i].tuso){
            maxtu=Arr[i].tuso;
            maxmau=Arr[i].mauso;
        }
    }
    cout<<"d)"<<maxtu<<"/"<<maxmau<<endl;
}
void TaskE(phanso Arr[],int num){
    phanso psMax;
    int i=0;
    while(Arr[i].tuso>Arr[i].mauso){
        i++;
    }
    psMax=Arr[i];
    for(;i<num;i++){
        if((Arr[i].tuso<Arr[i].mauso)&&(psMax.tuso*Arr[i].mauso<psMax.mauso*Arr[i].tuso)) psMax=Arr[i];
    }

    phanso psMin;
    i=0;
    while(Arr[i].tuso<Arr[i].mauso){
        i++;
    }
    psMin=Arr[i];
    for(;i<num;i++){
        if((Arr[i].tuso>Arr[i].mauso)&&(psMin.tuso*Arr[i].mauso>psMin.mauso*Arr[i].tuso)) psMin=Arr[i];
    }
    cout<<"e)"<<psMax.tuso<<"/"<<psMax.mauso<<" "<<psMin.tuso<<"/"<<psMin.mauso<<endl;
}
int UCLN(long int &a,long int &b){
    int r=a%b;
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int pstoigian(long int tuso,long int mauso){
    return UCLN(tuso,mauso)==1;
}
void TaskF(phanso Arr[],int num){
    int count=0;
    for(int i=0;i<num;i++){
        if(pstoigian(Arr[i].tuso,Arr[i].mauso))count++;
    }
    cout<<"f)"<<count<<endl;
}