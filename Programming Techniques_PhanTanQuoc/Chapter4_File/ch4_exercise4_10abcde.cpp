#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void write2File();
char *longestWord(char s[]);
char *leftWord(char s[]);
char *rightWord(char s[]);
int countWord(char s[]);
// int findWordInString(char s[]);
int main(){
    write2File();
    return 0;
}
void write2File(){
    FILE *fp;
    fp=fopen("str.txt","rt");
    if(!fp){
        cout<<"Cant open file";
        exit(1);
    }
    FILE *fp1;
    fp1=fopen("str.out","wt");
    if(!fp1){
        cout<<"Cant open file";
        exit(1);
    }
    char s[3000];
    // TaskA
    int num=0;
    while(!feof(fp)){
        fgets(s,3000,fp);
        fputs(longestWord(s),fp1);
        fprintf(fp1,"\n");
    }
    fprintf(fp1,"\n");
    // TaskB
    fseek(fp,0,0);
    while(!feof(fp)){
        fgets(s,3000,fp);
        fprintf(fp1,"%s %s\n",leftWord(s),rightWord(s));
    }
    fprintf(fp1,"\n");
    // TaskC
    fseek(fp,0,0);
    fgets(s,3000,fp);
    char ch[3000];
    strcat(ch,s);
    while(!feof(fp)){
        fgets(s,3000,fp);
        if(strlen(ch)<strlen(s))strcat(ch,s);
    }
    fputs(ch,fp1);
    fprintf(fp1,"\n");
    //TaskD
    int count=0;
    fseek(fp,0,0);
    while(!feof(fp)){
        fgets(s,3000,fp);
        count=count+countWord(s);
    }
    fprintf(fp1,"%d\n",count);
    // // TaskE
    // count=0;
    // fseek(fp,0,0);
    // while(!feof(fp)){
    //     fgets(s,3000,fp);
    //     count=count+findWordInString(s);
    // }
    // fprintf(fp1,"%d",count);
    fclose(fp1);
    fclose(fp);
}
char *longestWord(char s[]){
    char *token=strtok(s," ");
    char *ch=token;
    while(token){
        if(strlen(ch)<strlen(token))ch=token;
        token=strtok(NULL," ");
    }
    return ch;
}
char *leftWord(char s[]){
    char *ch=s;
    return strtok(ch," ");
}
char *rightWord(char s[]){
    char *ch=s;
    return strrchr(ch,' ')+1;
}
int countWord(char s[]){
    char *ch=s;
    ch[strlen(ch)-1]=' ';
    int d=0; 
	for (int i=0;i<strlen(ch);i++){
	    if (isspace(ch[i])&&ch[i]!=10) d++;
    }
    return d;
}
// int findWordInString(char s[]){
//     int d=0;
//     char *token=strtok(s," ");
//     char s1[]="your";
//     while(token){
//         char *found=strstr(s,s1);
//         if(found) d++; // found!=NULL ở đây có nghĩa là đã tìm thấy sự xuất hiện của chuỗi " your" trong str1 
//         token=strtok(NULL," ");
//     }
//     return d;
// }