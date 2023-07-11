#include<iostream>
using namespace std;
#define MAX 256
void read2File(int a[]);
void write2File(int a[]);
int main(){
    int a[MAX];
    read2File(a);
    write2File(a);
    return 0;
}
void read2File(int a[]){
    FILE *fp;
    fp=fopen("str.txt","rt");
    if(!fp){
        cout<<"Cant open file";
        exit(1);
    }
    for(int i=0;i<MAX;i++){
        a[i]=0;
    }
    char ch;
    while(!feof(fp)){
        ch=fgetc(fp);
        if(!isspace(ch)) a[int(ch)]++;
    }
    fclose(fp);
}
void write2File(int a[]){
    FILE *fp=fopen("str.out","wt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    for(int i=0;i<MAX;i++){
        if(a[i]){
            // fprintf(fp,"%s %c %s %d %s\n","Ki tu",char(i),"xuat hien",a[i],"lan");
            fprintf(fp,"%c %d ",char(i),a[i]);
        }
    }
    fclose(fp);
}