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
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            if(*(a+num*i+j)>max)max =*(a+num*i+j);   
        }
    }
    return max;
}
int TaskC(int *a,int m, int num){
    int max;
    int b=-1;
    for(int i=0;i<m-1;i++){
        for(int j=0;j<num-1;j++){
            if(prime(*(a+num*i+j))==1&&prime(*(a+num*i+j+num))==1&&prime(*(a+num*i+j+1))==1&&prime(*(a+num*i+j+1+num))==1)
                max=max+*(a+num*i+j)+*(a+num*i+j+num)+*(a+num*i+j+1)+*(a+num*i+j+1+num);
        }
        if(b<max)b=max;
        max=0;
    }
    return b;
}
int main(){
    // đọc file
    FILE *fp=fopen("table.inp","rt");
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
    FILE *fp1=fopen("table.out","wt");
    // TaskA
    fprintf(fp1,"%d ",TaskA(a,m,num));
    int dem=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<num;j++){
            if(*(a+num*i+j)==TaskA(a,m,num))dem++;   
        }
    }
    fprintf(fp1,"%d\n",dem);
    //
    // TaskB
    int max=0;
    for(int j=0;j<num;j++){
        for(int i=0;i<m;i++){
            max=max+*(a+num*i+j);
        }
        fprintf(fp1,"%d ",max);
        max=0;
    }
    fprintf(fp1,"\n");
    //
    fprintf(fp1,"%d\n",TaskC(a,m,num)); // TaskC
    fclose(fp1);
    delete a;
    delete fp;
    delete fp1;
    return 0;
}