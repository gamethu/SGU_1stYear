#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
using namespace std;
int main(){
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
    delete fp;
    return 0;
}