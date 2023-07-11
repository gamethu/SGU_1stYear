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
void initSLL(LIST &l);
NODE *initNODE(int x);
void insertNode2Tail(LIST &l,NODE *p);
void outSLL(LIST l);
int searchNode(LIST l,int value);
void swap(int &a,int &b);
void TaskD(LIST &l);
void removeAtHead(LIST &l);
void deleteSLL(LIST &l);
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
        if(!p){
            cout<<"Not enough memory";
            return 0;
        }
        insertNode2Tail(l,p);
    }
    outSLL(l);
    int value;
    cout<<"which value you want me to find : ";cin>>value;
    cout<<"c)Value "<<value<<" have(1) or dont(0) in NODE : "<<searchNode(l,value)<<endl;
    TaskD(l);
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
    cout<<"Linked list includes : ";
    while(l.pHead){
        cout<<l.pHead->data<<" ";
        l.pHead=l.pHead->pNext;
    }
    cout<<endl;
}
int searchNode(LIST l,int value){
    while(l.pHead){
        if(l.pHead->data==value) return 1;
        l.pHead=l.pHead->pNext;
    }
    return 0;
}
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}
void TaskD(LIST &l){
    cout<<"d)Linked List after SelectionSort includes : ";
    for(NODE *i=l.pHead;i!=l.pTail;i=i->pNext){
        NODE *k=i;
        for(NODE *j=i->pNext;j!=NULL;j=j->pNext){
            if(k->data>j->data){
                k=j;
            }
        }
        swap(k->data,i->data);
    }
    outSLL(l);
}
void removeAtHead(LIST &l){
    if(!l.pHead) return;
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
        outSLL(l);
        removeAtHead(l);
    }
}