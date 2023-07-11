#include<iostream>
#include<time.h>
#include<math.h>
#include<cstring>
#include<iomanip>
#define MAX 1000
using namespace std;
struct thongtin{
    char MSNV[6];
    char HOTEN[32];
    int luong;
    int thuong;
    int thuclinh;
};
thongtin tt;
void write2File();
void TaskABC();
void TaskD();
void TaskE();
int main(){
    thongtin Arr[MAX];
    write2File();
    TaskABC();
    TaskD();
    TaskE();
    return 0;
}
void write2File(){
    FILE *fp=fopen("hoso.dat","wb");
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"Ho so thu "<<i+1<<" :"<<endl;
        cout<<"MSSV : ";fflush(stdin);gets(tt.MSNV);
        cout<<"Ho va Ten : ";fflush(stdin);gets(tt.HOTEN);
        cout<<"Luong : ";cin>>tt.luong;
        cout<<"Thuong : ";cin>>tt.thuong;
        tt.thuclinh=tt.luong+tt.thuclinh;
        fwrite(&tt,sizeof(tt),1,fp);
    }
    fclose(fp);
}
void TaskABC(){
    FILE *fp=fopen("nump.txt","rb");
    int tong=0;
    cout<<"b)Ho so nv gom :"<<endl;
    while(!feof(fp)){
        fread(&tt,sizeof(tt),1,fp);
        printf("%s %s %d %d %d\n",tt.MSNV,tt.HOTEN,tt.luong,tt.thuong,tt.thuclinh);
        tong=tong+tt.thuclinh;
        fflush(stdin);
    }
    cout<<"c)Tong thuc linh : "<<tong<<endl;
    fclose(fp);
}
void TaskD(){
    FILE *fp=fopen("nump.txt","rb");
    fread(&tt,sizeof(tt),1,fp);
    int max=tt.luong;
    char ch[6];
    strcpy(ch,tt.MSNV);
    while(!feof(fp)){
        if(max<tt.thuclinh){
            max=tt.luong;
            strcpy(ch,tt.MSNV);
        }
        fread(&tt,sizeof(tt),1,fp);
        fflush(stdin);
    }
    cout<<"d)Nvien co muc luong cao nhat : "<<ch<<endl;
    fclose(fp);
}
void TaskE(){
    FILE *fp=fopen("nump.txt","rb");
    int tong=0;
    while(!feof(fp)){
        fread(&tt,sizeof(tt),1,fp);
        tong++;
        fflush(stdin);
    }
    cout<<"e)Co "<<tong<<" ho so"<<endl;
    fclose(fp);
}