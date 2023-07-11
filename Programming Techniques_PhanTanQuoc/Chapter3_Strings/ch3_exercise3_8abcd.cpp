#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstring>
using namespace std;
struct hoso{
    char ID[20];
    char Name[20];
    float NgoaiNgu;
    float CoBan;
    float CoSo;
    float Tong3Mon;
};
typedef hoso HOSO;
void inArray(HOSO *hs,int num);
void outArray(HOSO *hs,int num);
void swap(HOSO &a,HOSO &b);
void TaskA(HOSO *hs,int num);
void TaskB(HOSO *hs,int num);
void TaskC(HOSO *hs,int num);
void TaskD(HOSO *hs,int num);
int count_ascii_code(char hs[]);
void TaskE(HOSO *hs,int num);
int main(){
    int num;
    cout<<"Number of students : ";
    cin>>num;
    if(num<=0){
        cout<<"Data error!";
        exit(0);
    }
    HOSO *hs;
    hs=new HOSO[num];
    if(!hs){
        cout<<"Cant processing!";
        exit(0);
    }
    inArray(hs,num);
    cout<<"Student list : "<<endl;
    outArray(hs,num);
    TaskA(hs,num);
    TaskB(hs,num);
    TaskC(hs,num);
    TaskD(hs,num);
    TaskE(hs,num);
    return 0;
}
void inArray(HOSO *hs,int num){
    for(int i=0;i<num;i++){
        cout<<"Information of student "<<i+1<<" : "<<endl;
        cout<<"ID :";
        fflush(stdin);gets((hs+i)->ID);
        cout<<"Name :";
        fflush(stdin);gets((hs+i)->Name);
        cout<<"Diem mon ngoai ngu : ";cin>>(hs+i)->NgoaiNgu;
        cout<<"Diem mon ngoai ngu : ";cin>>(hs+i)->CoBan;
        cout<<"Diem mon ngoai ngu : ";cin>>(hs+i)->CoSo;
        (hs+i)->Tong3Mon=(hs+i)->NgoaiNgu+(hs+i)->CoBan+(hs+i)->CoSo;
        cout<<endl;
    }
    cout<<endl;
}
void outArray(HOSO *hs,int num){
    for(int i=0;i<num;i++){
            cout<<"Information of student "<<i+1<<" : "<<endl;
            cout<<"ID :"<<((hs+i)->ID)<<endl;
            cout<<"Name :"<<((hs+i)->Name)<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->NgoaiNgu<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->CoBan<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->CoSo<<endl;
            cout<<"Tong 3 mon : "<<(hs+i)->Tong3Mon<<endl;
            cout<<endl;
    }
}
void swap(HOSO &a,HOSO &b){
    HOSO temp=a;
    a=b;
    b=temp;
}
void TaskA(HOSO *hs,int num){
    cout<<"a)Thi sinh co it nhat mon mon thi co diem nho hon 5 la : "<<endl;
    for(int i=0;i<num;i++){
        if((hs+i)->NgoaiNgu<5||(hs+i)->CoBan<5||(hs+i)->CoSo<5){
            cout<<"Information of student "<<i+1<<" : "<<endl;
            cout<<"ID :"<<((hs+i)->ID)<<endl;
            cout<<"Name :"<<((hs+i)->Name)<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->NgoaiNgu<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->CoBan<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->CoSo<<endl;
            cout<<"Tong 3 mon : "<<(hs+i)->Tong3Mon<<endl;
            cout<<endl;
        }
    }
}
void TaskB(HOSO *hs,int num){
    cout<<"b)Tong cac thi sinh co diem tong 3 mon >=5 va diem CoBan+CoSo >=12 la : ";
    int dem=0;
    for(int i=0;i<num;i++){
        if(i==num-1&&!((hs+i)->Tong3Mon>=5&&((hs+i)->CoBan+(hs+i)->CoSo>=12))){
            cout<<"Khong ton tai hoc sinh can tim!";
            return;
        }
        if((hs+i)->Tong3Mon>=5&&((hs+i)->CoBan+(hs+i)->CoSo>=12)){
            dem++;
        }
    }
    cout<<dem;
    cout<<endl;
}
void TaskC(HOSO *hs,int num){
    cout<<"c)Cac thi sinh co diem tong 3 mon lon nhat la : "<<endl;
    float max=(hs+0)->Tong3Mon;
    for(int i=1;i<num;i++){
        if((hs+i)->Tong3Mon>max){
            max=(hs+i)->Tong3Mon;
        }
    }
    for(int i=0;i<num;i++){
        if((hs+i)->Tong3Mon==max){
            cout<<"Information of student "<<i+1<<" : "<<endl;
            cout<<"ID :"<<((hs+i)->ID)<<endl;
            cout<<"Name :"<<((hs+i)->Name)<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->NgoaiNgu<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->CoBan<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->CoSo<<endl;
            cout<<"Tong 3 mon : "<<(hs+i)->Tong3Mon<<endl;
            cout<<endl;
        }
    }
}
void TaskD(HOSO *hs,int num){
    char s[20];
    cout<<"Nhap sbd cua thi sinh can tim : ";
    fflush(stdin);gets(s);
    cout<<"d)Thong tin thi sinh can tim la : "<<endl;
    for(int i=0;i<num;i++){
        if(i==num-1&&strcmp((hs+i)->ID,s)!=0){
            cout<<"Hoc sinh khong ton tai!";
        }
        else if(strcmp((hs+i)->ID,s)==0){
            cout<<"Information of student "<<i+1<<" : "<<endl;
            cout<<"ID :"<<((hs+i)->ID)<<endl;
            cout<<"Name :"<<((hs+i)->Name)<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->NgoaiNgu<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->CoBan<<endl;
            cout<<"Diem mon ngoai ngu : "<<(hs+i)->CoSo<<endl;
            cout<<"Tong 3 mon : "<<(hs+i)->Tong3Mon<<endl;
            cout<<endl;
        }
    }
    cout<<endl;
}
int count_ascii_code(char hs[]){
    int s=0;
	for (int i=0;i<strlen(hs);i++){
	    s=s+toascii(hs[i]);
    }
    return s;
}
void TaskE(HOSO *hs,int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(count_ascii_code((hs+i)->ID)>count_ascii_code((hs+j)->ID)){
                swap(hs[i],hs[j]);
            }
        }
    }
    cout<<"e)Dsach thi sinh theo so bao danh tang dan : "<<endl;
    outArray(hs,num);
}
