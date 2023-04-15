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
        cout<<"Not enough memory";
        exit(1);
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
    cout<<"Singe linked list includes : ";
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        cout<<k->data<<" ";
    }
    cout<<endl;
}
int main(){
    LIST l,l1,l2;
    initSLL(l);
    cout<<"Num node need to put to input : ";
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"X value need to put into : ";
        int x;
        cin>>x;
        NODE *p=initNode(x);
        insertNode2Tail(l,p);
    }
    outSLL(l);
}