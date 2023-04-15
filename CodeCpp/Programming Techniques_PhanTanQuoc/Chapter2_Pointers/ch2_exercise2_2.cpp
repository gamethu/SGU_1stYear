#include<iostream>
#include<conio.h>
#include<cstdio>
using namespace std;
struct hoso{
    char maso[32];
    char hoten[32];
    float coban;
    float chuyennganh1;
    float chuyennganh2;
};
void inArray(hoso *hs,int num);
void caua(hoso *hs,int num);
void caub(hoso *hs,int num);
void cauc(hoso *hs,int num);
void caud(hoso *hs,int num);
void swap(hoso &a,hoso &b);
void caue(hoso *hs,int num);
int main(){
    int num;
    cin>>num;
    if(num<=0){
        cout<<"Data error";
        exit(0);
    }
    hoso *hs;
    hs=new hoso[num];
    if(!hs){
        cout<<"Not enough memory!";
        exit(0);
    }
    inArray(hs,num);
    caub(hs,num);
    cauc(hs,num);
    caud(hs,num);
    caue(hs,num);
    delete hs;
    getch();
}
void inArray(hoso *hs,int num){
    for(int i=0;i<num;i++){
        cout<<"Ma so sinh vien : ";
        fflush(stdin);
            gets((hs+i)->maso);
        cout<<"Ho va ten : ";
        fflush(stdin);
            gets((hs+i)->hoten);
        cout<<"Diem mon co ban : "; cin>>(hs+i)->coban;
        cout<<"Diem mon chuyen nganh 1 : "; cin>>(hs+i)->chuyennganh1;
        cout<<"Diem mon chuyen nganh 2 : "; cin>>(hs+i)->chuyennganh2;
    }
}
void caub(hoso *hs,int num){
    cout<<"b)Danh sach thi sinh tham du : "<<endl;
    for(int i=0;i<num;i++){
        cout<<(hs+i)->maso<<" "<<(hs+i)->hoten<<" "<<(hs+i)->coban<<" "<<(hs+i)->chuyennganh1<<" "<<(hs+i)->chuyennganh2<<" ";
        cout<<(hs+i)->coban+(hs+i)->chuyennganh1+(hs+i)->chuyennganh2<<endl;
    }
    cout<<endl;
}
void cauc(hoso *hs,int num){
    cout<<"c)Nhung thi sinh co it nhat mot mon thi co diem nho hon 5 la : "<<endl;
    for(int i=0;i<num;i++){
        if((hs+i)->coban<5||(hs+i)->chuyennganh1<5||(hs+i)->chuyennganh2<5){
            cout<<(hs+i)->hoten<<" ";
        }
    }
    cout<<endl;
}
void caud(hoso *hs,int num){
    float max=hs[0].coban+hs[0].chuyennganh1+hs[0].chuyennganh2;
    for(int i=1;i<num;i++){
        if((hs+i)->coban+(hs+i)->chuyennganh1+(hs+i)->chuyennganh2>max) hoso max=*(hs+i);
    }
    cout<<"d)Nhung thi sinh co tong diem 3 mon lon nhat : "<<endl;
    for(int i=0;i<num;i++){
    if((hs+i)->coban+(hs+i)->chuyennganh1+(hs+i)->chuyennganh2==max){
            cout<<hs[i].hoten;
         }
    }
    cout<<endl;
}
void swap(hoso &a,hoso &b){
    hoso temp=a;
    a=b;
    b=temp;
}
void caue(hoso *hs,int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
        if((hs+i)->chuyennganh1+(hs+i)->chuyennganh1>(hs+j)->chuyennganh1+(hs+j)->chuyennganh1)
        swap(*(hs+i),*(hs+j));
        }
    }
    cout<<"e)Danh sach theo diem 2 mon chuyen nganh tang dan: "<<endl;
    for(int i=0;i<num;i++){
        cout<<(hs+i)->maso<<" "<<(hs+i)->hoten<<" "<<(hs+i)->coban<<" "<<(hs+i)->chuyennganh1<<" "<<(hs+i)->chuyennganh2<<" ";
        cout<<(hs+i)->coban+(hs+i)->chuyennganh1+(hs+i)->chuyennganh2<<endl; 
    }
}
