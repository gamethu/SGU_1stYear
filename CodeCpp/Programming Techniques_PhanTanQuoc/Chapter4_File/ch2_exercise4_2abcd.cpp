#include<iostream>
#include<fstream>
#include<cstdlib>
#include<math.h>
using namespace std;
int TaskA(int *a,int num){
    int max=a[0];
    for(int i=1;i<num;i++){
        if(a[i]>max)max=a[i];
    }
    return max;
}
int TaskB(int *a,int num){
    int d=0;
    int max=0;
    for(int i=0;i<num-1;i++){
        if(a[i]>a[i+1])d++;
        else{
            if(d>max){
                max=d;
                d=0;
            }
        }
    }
    return max;
}
int TaskC(int *a,int num,int findingValue){
    int d=0;
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(a[i]+a[j]==findingValue)d++;
        }
    }
    return d;
}
void exchange(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
int TaskD(int *a,int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(a[i]>a[j]) exchange(a[i],a[j]);
        }
    }
    return a[num/2];
}
int main(){
    // đọc file
    FILE *fp=fopen("NUM.INP","rt");
    if(!fp){
        cout<<"Cant open";
        exit(1);
    }
    int num;
    fscanf(fp,"%d",&num);
    int findingValue;
    fscanf(fp,"%d",&findingValue);
    if(num<=0){
        cout<<"Data error";
        exit(1);
    }
    int *a=new int[num];
    if(!a){
        cout<<"Data error";
        exit(1);
    }
    int digit;
    for(int i=0;i<num;i++){
        fscanf(fp,"%d",&digit);
        a[i]=digit;
    }
    fclose(fp);
    // ghi file
    FILE *fp1=fopen("NUM.OUT","wt");
    fprintf(fp1,"%d\n",TaskA(a,num)); // TaskA
    fprintf(fp1,"%d\n",TaskB(a,num)); // TaskB
    fprintf(fp1,"%d\n",TaskC(a,num,findingValue)); // TaskC
    fprintf(fp1,"%d",TaskD(a,num)); // TaskD
    fclose(fp1);
    delete a;
    delete fp;
    delete fp1;
    return 0;
}