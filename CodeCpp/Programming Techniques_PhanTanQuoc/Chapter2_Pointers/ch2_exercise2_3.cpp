#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
struct dathuc{
    float heso;
    unsigned int somu;
};
void inArray(dathuc *dt,int num);
void outArray(dathuc *dt,int num);
float tong(dathuc *dt,int num, float heso);
int main(){
    int num;
    cout<<"Nhap so luong don thuc : ";
    cin>>num;
    dathuc *dt;
    if(num<=0){
        cout<<"Data error";
        exit(0);
    }
    dt=new dathuc[num];
    if(!dt){
        cout<<"Not enough memory";
        exit(0);
    }
    inArray(dt,num);
    outArray(dt,num);
    float x;
    cout<<"Nhap x0 = ";cin>>x;
    cout<<"Gia tri cua da thuc tai vi tri x0 = "<<x<<" la : "<<tong(dt,num,x);
    delete dt;
    getch();
}
void inArray(dathuc *dt,int num){
    for(int i=0;i<num;i++){
        cout<<"He so da thuc "<<i+1<<" : ";cin>>(dt+i)->heso;
        cout<<"So mu da thuc "<<i+1<<" : ";cin>>(dt+i)->somu;
    }
}
void outArray(dathuc *dt,int num){
    cout<<"Bieu thuc da nhap la : ";
    for(int i=0;i<num;i++){
        cout<<(dt+i)->heso<<"x"<<"^"<<(dt+i)->somu;
        if(i<num-1)cout<<" + ";
    }
    cout<<endl;
}
float tong(dathuc *dt,int num,float x){
    if(num==1) return dt[0].heso*pow(x,dt[0].somu);
    return dt[num-1].heso*pow(x,dt[num-1].somu)+tong(dt,num-1,x);
}
