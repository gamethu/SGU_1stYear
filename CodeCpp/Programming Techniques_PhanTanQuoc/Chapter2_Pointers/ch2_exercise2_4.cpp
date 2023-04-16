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
void initSLL(LIST &l){
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE *initNODE(int x){
    NODE *p;
    p=new NODE;
    if(!p){
        cout<<"Not enough memory";
        exit(0);
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
void insertNode2Tail(LIST &l,NODE *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
    l.pTail->pNext=p;
    l.pTail=p;
    }
}
void outSLL(LIST l){
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        cout<<k->data<<" ";
    }
    cout<<endl;
}
void sumpSLL(LIST l){
    cout<<"a)Tong cac phan tu trong dslk l : ";
    int dem=0;
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        dem=dem+k->data;
    }
    cout<<dem;
    cout<<endl;
}
int snt(int n){
    if(n<2)return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
void sntDSLK(LIST l){
    cout<<"b)Cac so nguyen co trong dslk l : ";
    int dem=0;
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        if(snt(k->data)==1){
        dem++;
        }
    }
    cout<<dem;
    cout<<endl;
}
void chan_leDSLK(LIST l){
    cout<<"c)Cac so chan va le lan luot trong dslk l : ";
    int dem=0,dem1=0;
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        if((k->data)%2==0)dem++;
        else dem1++;
    }
    cout<<dem<<" "<<dem1;
    cout<<endl;
}
void timMaxDSLK(LIST l){
    cout<<"d)GTLN trong dslk l : ";
    int max=l.pHead->data;
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        if(max<k->data)max=k->data;
    }
    cout<<max;
    cout<<endl;
}
void removeNodeAtHead(LIST &l){
    cout<<"e)Xoa phan tu dau trong DSLK : ";
    if(l.pHead==NULL){
        return;
    }
    else{
        NODE *p;
        p=l.pHead;
        l.pHead=l.pHead->pNext;
        delete p;
    }
}
void removeAtHead(LIST &l){
    if(l.pHead==NULL){
        return;
    }
    else{
        NODE *p;
        p=l.pHead;
        l.pHead=l.pHead->pNext;
        p->pNext = NULL;
        delete p;
    }
}
void deleteSLL(LIST &l){
    while(l.pHead){
        removeAtHead(l);
    }
}
int main(){
    LIST l;
    initSLL(l);
    int n;
    cout<<"Nhap so luong node : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cout<<"Nhap gia tri x : ";
        cin>>x;
        NODE *p=initNODE(x);
        insertNode2Tail(l,p);
    }  
    cout<<"Danh sach lien ket gom : ";outSLL(l);
    sumpSLL(l);
    sntDSLK(l);
    chan_leDSLK(l);
    timMaxDSLK(l);
    removeNodeAtHead(l);
    outSLL(l);
    deleteSLL(l);
    return 0;
}