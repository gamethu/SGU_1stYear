#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
void write2File();
int main(){
    write2File();
    return 0;
}
void write2File(){
    FILE *fp=fopen("NUM.INP","wt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    int num;
    cout<<"Digit's number has in file : ";
    cin>>num;
    if(num<=0){
        cout<<"Data error";
        exit(1);
    }
    fprintf(fp,"%d",num);
    fprintf(fp,"\n");
    for(int i=0;i<num;i++){
        fprintf(fp,"%d ",abs(rand()-rand()));
    }
    fclose(fp);
}