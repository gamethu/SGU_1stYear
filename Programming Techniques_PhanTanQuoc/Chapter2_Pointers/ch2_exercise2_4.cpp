#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
struct node{
    int data;
    struct node *pNext;
};
typedef node NODE;
struct list{
    NODE *pHead;
    NODE *pTail;
};
typedef list LIST;
void initSLL(LIST &l);
NODE *initNODE(int x);
void insertNode2Tail(LIST &l,NODE *p);
void outSLL(LIST l);
void TaskA(LIST l);
int prime(int n);
void TaskB(LIST l);
void TaskC(LIST l);
void TaskD(LIST l);
void TaskE(LIST &l);
void removeAtHead(LIST &l);
void deleteSLL(LIST &l);
int main(){
    LIST l;
    initSLL(l);
    int n;
    cout<<"Nhap so luong node : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cout<<"Node number "<<i<<" value : ";
        cin>>x;
        NODE *p=initNODE(x);
        if(!p){
            cout<<"Not enough memory";
            return 0;
        }
        insertNode2Tail(l,p);
    }  
    cout<<"SLL includes : ";
    outSLL(l);
    TaskA(l);
    TaskB(l);
    TaskC(l);
    TaskD(l);
    TaskE(l);
    outSLL(l);
    deleteSLL(l);
    return 0;
}
void initSLL(LIST &l){
    l.pHead=l.pTail=NULL;
}
NODE *initNODE(int x){
    NODE *p=new NODE;
    if(!p) return NULL;
    p->data=x;
    p->pNext=NULL;
    return p;
}
void insertNode2Tail(LIST &l,NODE *p){
    if(!l.pHead) l.pHead=l.pTail=p;
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void outSLL(LIST l){
    while(l.pHead){
        cout<<l.pHead->data<<" ";
        l.pHead=l.pHead->pNext;
    }
    cout<<endl;
}
void TaskA(LIST l){
    cout<<"a)Tong cac phan tu trong dslk l : ";
    int dem=0;
    while(l.pHead){
        dem=dem+l.pHead->data;
        l.pHead=l.pHead->pNext;
    }
    cout<<dem<<endl;
}
int prime(int n){
    if(n<2)return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
void TaskB(LIST l){
    cout<<"b)Cac so nguyen co trong dslk l : ";
    int dem=0;
    while(l.pHead){
        if(prime(l.pHead->data)==1) dem++;
        l.pHead=l.pHead->pNext;
    }
    cout<<dem<<endl;
}
void TaskC(LIST l){
    cout<<"c)Cac so chan va le lan luot trong dslk l : ";
    int odd=0,even=0;
    while(l.pHead){
        if((l.pHead->data)%2==0)odd++;
        else even++;
        l.pHead=l.pHead->pNext;
    }
    cout<<odd<<" "<<even<<endl;
} 
void TaskD(LIST l){
    cout<<"d)GTLN trong dslk l : ";
    int max=l.pHead->data;
    l.pHead=l.pHead->pNext;
    while(l.pHead){
        if(max<l.pHead->data)max=l.pHead->data;
        l.pHead=l.pHead->pNext;
    }
    cout<<max<<endl;
}
void TaskE(LIST &l){
    cout<<"e)Xoa phan tu dau trong DSLK : ";
    if(!l.pHead) return;
    NODE *p;
    p=l.pHead;
    l.pHead=l.pHead->pNext;
    delete p;
}
void removeAtHead(LIST &l){
    if(!l.pHead)return;
    NODE *p;
    p=l.pHead;
    l.pHead=l.pHead->pNext;
    p->pNext=NULL;
    delete p;
    
}
void deleteSLL(LIST &l){
    while(l.pHead){
        removeAtHead(l);
    }
}
