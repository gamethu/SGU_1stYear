#include<iostream>
#include<fstream>
using namespace std;
int main(){
    FILE *fp=fopen("table.inp","wt");
    if(!fp){
        cout<<"Cant open file";
        exit(1);
    }
    int m,num;
    cout<<"Input m lines n clum: ";
    cin>>m>>num;
    if(num<=0){
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