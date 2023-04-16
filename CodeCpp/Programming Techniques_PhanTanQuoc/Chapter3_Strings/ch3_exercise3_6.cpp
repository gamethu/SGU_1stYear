#include<iostream>
#include<cstring>
using namespace std;
struct hoten{
    char Ho[10];    
    char Ten[10];
};
struct ThongTin{
    char ID[10];
    hoten name;
};
void inArray(ThongTin *in4,int num){
    for(int i=0;i<num;i++){
        cout<<"LIST "<<i+1<<" : "<<endl;
        cout<<"ID : ";
        fflush(stdin);gets((in4+i)->ID);
        cout<<"Ho va ten : ";cin>>in4[i].name.Ho>>in4[i].name.Ten;
    }
    cout<<endl;
}
void outArray(ThongTin *in4,int num){
    for(int i=0;i<num;i++){
        cout<<"LIST "<<i+1<<" : "<<endl;
        cout<<(in4+i)->ID<<endl;
        cout<<"Ho va ten : "<<in4[i].name.Ho<<" "<<in4[i].name.Ten<<endl;
    }   
    cout<<endl;
}
int char_covert(char s[]){
    int sump=0;
    for(int i=0;i<strlen(s);i++){
        sump=sump+toascii(s[i]);
    }
    return sump;
}
void swap(ThongTin &a,ThongTin &b){
    ThongTin temp=a;
    a=b;
    b=temp;
}
void interchangesort(ThongTin *in4,int num){
    cout<<"Sap xep danh sach tang dan theo cot ten : "<<endl;
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++){
            if(char_covert(in4[i].name.Ten)>char_covert(in4[j].name.Ten))
                swap(in4[i],in4[j]);
        }
    }
    outArray(in4,num);
}
int main(){
    cout<<"Number of input list : ";
    int num;
    cin>>num;
    if(num<=0){
        cout<<"Data error!";
        exit(0);
    }
    ThongTin *in4;
    in4=new ThongTin[num];
    if(!in4){
        cout<<"cant processing!";
        exit(0);
    }
    inArray(in4,num);
    cout<<"LIST : "<<endl;
    outArray(in4,num);
    interchangesort(in4,num);
    return 0;  
}