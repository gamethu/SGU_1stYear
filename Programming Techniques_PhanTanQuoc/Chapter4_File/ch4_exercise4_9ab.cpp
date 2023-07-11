#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void write2File();
char *rightMostWord(char *s);
int countWord(char *s);
int main(){
    write2File();
    return 0;
}
void write2File(){
    FILE *fp=fopen("str.txt","rt");
    if(!fp){
        cout<<"Cant open file";
        exit(1);
    }
    FILE *fp1=fopen("str.out","wt");
    if(!fp1){
        cout<<"Cant open file";
        exit(1);
    }
    char s[100];
    int count=0;
    while(!feof(fp)){
        fgets(s,100,fp);
        count=count+countWord(s);
        fputs(rightMostWord(s),fp1);
    }
    fprintf(fp1,"\n%d",count);
    fclose(fp1);
    fclose(fp);
}
char *rightMostWord(char *s){
    return strrchr(s,' ')+1;
}
int countWord(char *s){
    int d=1; 
	for (int i=0;i<strlen(s);i++){
	    if (isspace(s[i])&&s[i]!=10) d++;
    }
    return d;
}