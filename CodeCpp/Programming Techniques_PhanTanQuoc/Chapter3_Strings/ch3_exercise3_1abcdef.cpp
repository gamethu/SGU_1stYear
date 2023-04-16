#include<iostream>
#include<cstring>
using namespace std;
void count_upper_lower(char s[]){
	int upper=0,lower=0;
	for (int i=0;i<strlen(s);i++){
	    if(isupper(s[i])) upper++;
	    else if(islower(s[i])) lower++;
	}
	cout<<"a)So luong chu hoa, chu thuong lan luot la : "<<upper<<" "<<lower<<endl;
}
void count_ascii_code(char s[]){
    cout<<"b)Ma Ascii cua moi ky tu trong chuoi la : "<<endl;
	for (int i=0;i<strlen(s);i++){
	    cout<<"Ma Ascii cua '"<<s[i]<<"' la : "<<toascii(s[i])<<endl;
    }
}
void char_conver(char s[]){ 	
    char s1[100];
    strcpy(s1,s);
    strlwr(s1); // biến cả chuỗi kí tự thành chuỗi kí tự thường
    // strupr(s);  biến cả chuỗi kí tự thành chuỗi kí tự HOA
	for (int i=0;i<strlen(s1);i++){
	    if (isspace(s1[i])) s1[i+1]=toupper(s1[i+1]);	
    }
    s1[0]=toupper(s1[0]);
	cout<<"c)Cac ky tu dau cua chuoi thanh chu hoa, con lai thanh chu thuong la : "<<s1<<endl;
}
void word_count(char s[]){
	int d=1; 
	for (int i=0;i<strlen(s);i++){
	    if (isspace(s[i])) d++;
    }
	cout<<"d)So luong tu cua chuoi '"<<s<<"' la : "<<d<<endl;
}
void char_count(char s[]){
    cout<<"e)So luong ky tu cua moi tu trong chuoi '"<<s<<"' la : "<<endl;
	int d=0,d1=1; 
    char s1[100];
    strcpy(s1,s);
	s1[strlen(s1)]=' ';// thêm khoảng trắng vào cuối chuỗi
	for (int i=0;i<strlen(s1);i++){
	    if (!isspace(s1[i])) d++; 
	    else{
            cout<<"So luong ki tu cua tu thu "<<d1<<" la : "<<d<<endl;
		    d=0;	
            d1++;
		}
	}
}
void leftmost_rightmost(char s[]){
    cout<<"f)Mot tu dau tien ben trai, mot tu dau tien ben phai lan luot la : ";
    char s1[100],s2[100],s3[100];
    strcpy(s1,s);
    strcpy(s2,strrchr(s1,' ')+1); // tìm 1 từ bên phải
    strrev(s1);
    strcpy(s3,strrchr(s1,' ')+1); // tìm 1 từ bên trái
    strrev(s3);
    cout<<s3<<" "<<s2<<endl;
}
int main(){
    char s[100];
    cout<<"Nhap chuoi ki tu : ";
    gets(s);
    cout<<"Chuoi vua nhap : "<<s<<endl;
    count_upper_lower(s);
    count_ascii_code(s);
    char_conver(s);
    word_count(s);
    char_count(s);
    leftmost_rightmost(s);
    return 0;
}
