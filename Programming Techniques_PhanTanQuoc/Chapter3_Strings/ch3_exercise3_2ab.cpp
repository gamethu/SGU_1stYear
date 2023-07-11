#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int checkSuXuatHien(char x[], char s[]);
int main(){
    char s[255],x[255];
    fflush(stdin);gets(s);
    fflush(stdin);gets(x);
    cout<<checkSuXuatHien(x,s)<<endl;
    return 0;
}
int checkSuXuatHien(char x[], char s[]){
    char *found=strstr(s,x);
    return found!=NULL?strlen(s)-strlen(found):-1;
}