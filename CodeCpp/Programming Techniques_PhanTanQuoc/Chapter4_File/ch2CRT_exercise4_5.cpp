#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
int main(){
    FILE *fp=fopen("TABLE1.INP","wt");
    if(!fp){
        cout<<"Cant open file";
        exit(1);
    }
    int m,num;
    cout<<"Input m lines n clum: ";
    cin>>m>>num;
    if(m<1){
        cout<<"Data error";
        exit(1);
    }
    if(!(num>0&&num<=500)){
        cout<<"Data error";
        exit(1);
    }
    fprintf(fp,"%d %d\n",m,num);
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            fprintf(fp,"%d ",abs(rand()-rand()));
        }
        fprintf(fp,"\n");
    }
    fclose(fp);
    delete fp;
    return 0;
}