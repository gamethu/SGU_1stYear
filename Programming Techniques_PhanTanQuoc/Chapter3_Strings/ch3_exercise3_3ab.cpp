#include<iostream>
#include<cstring>
#define max 1000
using namespace std;
void TaskA();
void TaskB();
int main(){
    TaskA();
    TaskB();
    return 0;
}
void TaskA(){
    char s[max];
    cout<<"Nhap chuoi ki tu : ";
    gets(s);
    cout<<"Chuoi ki tu vua nhap : "<<s<<endl;
    int kt,vt;
    cout<<"Nhap so luong ki tu va vi tri can xoa : ";cin>>kt>>vt;
    for(int i=0;i<strlen(s);i++){
        if(i+1==vt){
            for(int j=i;j<strlen(s);j++){
                s[j]=s[j+kt];
            }
            while(kt){
                kt--;
                i--; 
            }
        }
    }
    cout<<"a)Chuoi ki tu sau khi xoa "<<kt<<" ky tu tu vi tri "<<vt<<" cua chuoi la : "<<s<<endl;
}
void TaskB(){
    char s1[max],s2[max];
    cout<<"Nhap chuoi 1 : ";fflush(stdin);gets(s1);
    cout<<"Nhap chuoi 2 : ";fflush(stdin);gets(s2);
    int p;
    cout<<"Nhap vi tri can chen chuoi '"<<s2<<"' vao trong chuoi '"<<s1<<"' :";
    cin>>p;

    char s1tail[100],s1head[100];
    strcpy(s1head,s1);
    strcpy(s1tail,s1+p-1); // phải từ một 
    int k=strlen(s1)-strlen(s1tail);
    s1[k]='\0'; // trái từ một
    strcpy(s1head,s1);
    strcat(s1head,s2);
    strcat(s1head,s1tail);
    cout<<s1head<<endl;
}