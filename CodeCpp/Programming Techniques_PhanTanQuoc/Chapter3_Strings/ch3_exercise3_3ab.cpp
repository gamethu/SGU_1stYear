#include<iostream>
#include<cstring>
using namespace std;
void remove_char(char s[],int kt,int vt){
    for(int i=0;i<strlen(s);i++){
        if(i+1==vt){
            int j;
            for(j=i;j<strlen(s);j++){
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
void insert_char2to_pchar1(char s1[],char s2[],int vt){
    char s1tail[100],s1head[100];

    strcpy(s1head,s1);
    cout<<endl;
    strcpy(s1tail,s1+vt-1); // phải từ một
    int k=strlen(s1)-strlen(s1tail);
    s1[k]='\0';
    strcpy(s1head,s1);
    strcat(s1head,s2);
    strcat(s1head,s1tail);
    cout<<s1head<<endl;
}
int main(){
    char s[100];
    cout<<"Nhap chuoi ki tu : ";
    gets(s);
    cout<<"Chuoi ki tu vua nhap : "<<s<<endl;
    int kt,vt;
    cout<<"Nhap so luong ki tu va vi tri can xoa : ";
    cin>>kt>>vt;
    remove_char(s,kt,vt);

    char s1[100],s2[100];
    cout<<"Nhap chuoi 1 : ";
    fflush(stdin);gets(s1);
    cout<<"Nhap chuoi 2 : ";
    fflush(stdin);gets(s2);
    // int p; // cmt do đã khai báo ở trên
    cout<<"Nhap vi tri can chen chuoi '"<<s2<<"' vao trong chuoi '"<<s1<<"' :";
    // int vt; // cmt do đã khai báo ở trên
    cin>>vt;
    cout<<"b)Chuoi sau khi chen '"<<s2<<"' vao vi tri "<<vt<<" cua chuoi '"<<s1<<"' la : ";insert_char2to_pchar1(s1,s2,vt);
    return 0;
}