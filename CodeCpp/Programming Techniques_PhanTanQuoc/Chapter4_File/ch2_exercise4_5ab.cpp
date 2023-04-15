#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
using namespace std;
int prime(int n){
    if(n<2) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int TaskA(int *a,int m, int num){
    int max=*a;
    for(int j=1;j<num;j++){
        if(*(a+j)<max)max=*(a+j);   
    }
    int b=max;
    for(int i=1;i<m;i++){
        max=*(a+num*i);
        for(int j=1;j<num;j++){
            if(*(a+num*i+j)<max)max =*(a+num*i+j);   
        }
        if(b<max)b=max;
        max=0;
    }
    return b;
}
int main(){
    // đọc file
    FILE *fp=fopen("TABLE1.INP","rt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    int m,num;
    fscanf(fp,"%d %d",&m,&num);
    int *a;
    a=new int[m*num];
    int digit;
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            fscanf(fp,"%d",&digit);
            *(a+num*i+j)=digit;
        }
    }
    fclose(fp);
    // ghi file 
    FILE *fp1=fopen("TABLE1.OUT","wt");
    fprintf(fp1,"%d\n",TaskA(a,m,num)); // TaskA

    fclose(fp1);
    delete a;
    delete fp;
    delete fp1;
    return 0;
}