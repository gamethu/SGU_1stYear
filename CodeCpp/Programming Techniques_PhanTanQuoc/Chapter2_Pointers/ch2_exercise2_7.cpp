#include<iostream>
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
    l.pHead=l.pTail=NULL;
}
NODE *initNode(int x){
    NODE *p;
    p=new NODE;
    if(!p){
        cout<<"Not enought memory";
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
void separateSLL(LIST l,LIST &l1,LIST &l2){
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        if((k->data)%2==0){
            NODE *p=initNode(k->data);
            insertNode2Tail(l1,p);
        }
        else if((k->data)%2!=0){
            NODE *p=initNode(k->data);
            insertNode2Tail(l2,p);
        }
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
        p->pNext=NULL;
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
    cout<<"Numbers of List need to put in : ";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"X value : ";
        int x;
        cin>>x;
        NODE *p=initNode(x);
        insertNode2Tail(l,p);
    }
    cout<<"List includes : ";
    outSLL(l);
    LIST l1,l2;
    initSLL(l1);
    initSLL(l2);
    separateSLL(l,l1,l2);
    cout<<"ODD list :";outSLL(l1);
    cout<<"EVEN list :";outSLL(l2);
    deleteSLL(l);
    deleteSLL(l1);
    deleteSLL(l2);
    return 0;
}
