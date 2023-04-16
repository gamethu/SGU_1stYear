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
NODE *initNODE(int x){
    NODE *p;
    p=new NODE;
    if(!p){
        cout<<"Not enough memory!";
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
    cout<<"Linked list includes : ";
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        cout<<k->data<<" ";
    }
    cout<<endl;
}
int searchNode(LIST l,int value){
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        if(k->data==value) return 1;
    }
    return 0;
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void SelectionSort_SLL(LIST &l){
   for(NODE *i=l.pHead;i!=l.pTail;i=i->pNext){
    NODE *k=i;
    for(NODE *j=i->pNext;j!=NULL;j=j->pNext){
        if(k->data>j->data){
            k=j;
        }
    }
    swap(k->data,i->data);
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
    cout<<"Number of nodes : ";cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Node number "<<i<<" value : ";
        int x;
        cin>>x;
        NODE *p=initNODE(x);
        insertNode2Tail(l,p);
    }
    outSLL(l);
    int value;
    cout<<"which value you want me to find : ";cin>>value;
    cout<<"a)Value "<<value<<" have(1) or dont(0) in NODE : "<<searchNode(l,value);
    cout<<endl;
    SelectionSort_SLL(l);
    cout<<"b)Linked List after SelectionSort includes : ";
    outSLL(l);
    deleteSLL(l);
    return 0;
}