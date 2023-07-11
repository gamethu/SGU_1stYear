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
void separateSLL(LIST l,LIST &l1,LIST &l2){
    while(l.pHead){
        if((l.pHead->data)%2==0){
            NODE *p=initNode(l.pHead->data);
            insertNode2Tail(l1,p);
        }
        else{
            NODE *p=initNode(l.pHead->data);
            insertNode2Tail(l2,p);
        }
        l.pHead=l.pHead->pNext;
    }
}
void removeAtHead(LIST &l){
    if(!l.pHead) return;
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
        cout<<"Node number "<<i<<" value : ";
        cin>>x;
        NODE *p=initNode(x);
        if(!p){
            cout<<"Not enough memory";
            return 0;
        }
        insertNode2Tail(l,p);
    }
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
