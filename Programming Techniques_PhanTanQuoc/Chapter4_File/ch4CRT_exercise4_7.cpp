#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
void write2File();
int main(){
    write2File();
    return 0;
}
void write2File(){
    FILE *fp;
    fp=fopen("input.txt","wt");
    if(!fp){
        cout<<"Cant open file";
        exit(1);
    }
    cout<<"Input strlen: ";
    int num;
    cin>>num;
    if(num<=0){
        cout<<"Data error";
        exit(1);
    }
    for(int i=0;i<num;i++){
        int x=rand()%27; // ngẫu nhiêu ký tự chữ thường từ 0->25 tương ứng từ 'a'->'z' và kí tự khoảng trắng
        if(x==26)fputc(' ',fp);  
        else fputc(x+'a',fp);
    }
    fprintf(fp,"\n");
    fclose(fp);
}