#include<iostream>
#include<cstring>
using namespace std;
struct hoso{
    char ID[20];
    char Name[20];
    char Date[20];
    float CoBan;
    float Thuong;
    float ThucLanh;
};
void inArray(hoso *hs,int num);
void outArray(hoso *hs,int num);
void swap(hoso &a,hoso &b);
void interchangeSort_Luong(hoso *hs,int num);
int count_ascii_code(char hs[]);
void interchangeSort_ID(hoso *&hs,int num);
int main(){
    int num;
    cout<<"Number of employee : ";
    cin>>num;
    if(num<=0){
        cout<<"Data error!";
        return 0;
    }
    hoso *hs=new hoso[num];
    if(!hs){
        cout<<"Cant processing!";
        return 0;
    }
    inArray(hs,num);
    cout<<"a)Employee list : "<<endl;
    outArray(hs,num);
    interchangeSort_Luong(hs,num);
   // interchangeSort_ID(hs,num);
    return 0;
}
void inArray(hoso *hs,int num){
    for(int i=0;i<num;i++){
        cout<<"Information of employee "<<i+1<<" : "<<endl;
        cout<<"ID :";
        fflush(stdin);gets((hs+i)->ID);
        cout<<"Name :";
        fflush(stdin);gets((hs+i)->Name);
        cout<<"Date : ";
        fflush(stdin);gets((hs+i)->Date);
        cout<<"Luong co ban : ";cin>>(hs+i)->CoBan;
        cout<<"Luong thuong : ";cin>>(hs+i)->Thuong;
        (hs+i)->ThucLanh=(hs+i)->CoBan+(hs+i)->Thuong;
        cout<<endl;
    }
    cout<<endl;
}
void outArray(hoso *hs,int num){
    for(int i=0;i<num;i++){
        cout<<"Information of employee "<<i+1<<" : "<<endl;
        cout<<"ID :"<<(hs+i)->ID<<endl;
        cout<<"Name :"<<(hs+i)->Name<<endl;
        cout<<"Date : "<<(hs+i)->Date<<endl;
        cout<<"Luong co ban : "<<(hs+i)->CoBan<<endl;
        cout<<"Luong thuong : "<<(hs+i)->Thuong<<endl;
        cout<<"Thuc lanh : "<<(hs+i)->ThucLanh<<endl;
        cout<<endl;
    }
}
void swap(hoso &a,hoso &b){
    hoso temp=a;
    a=b;
    b=temp;
}
void interchangeSort_Luong(hoso *hs,int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if((hs+i)->CoBan<(hs+j)->CoBan){
                swap(hs[i],hs[j]);
            }
        }
    }
    cout<<"b)Dsach nhan vien theo bac luong giam dan : "<<endl;
    outArray(hs,num);
}
int count_ascii_code(char hs[]){
    int s=0;
	for (int i=0;i<strlen(hs);i++){
	    s=s+toascii(hs[i]);
    }
    return s;
}
void interchangeSort_ID(hoso *&hs,int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(count_ascii_code((hs+i)->ID)>count_ascii_code((hs+j)->ID)){
                swap(hs[i],hs[j]);
            }
        }
    }
    cout<<"c)Dsach nhan vien theo ma nhan vien tang dan : "<<endl;
    outArray(hs,num);
}

