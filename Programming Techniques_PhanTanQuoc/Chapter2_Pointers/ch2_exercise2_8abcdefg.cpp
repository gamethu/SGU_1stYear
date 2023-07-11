// 20 10 30 16 8 40 25 6 7 19 37 1 4 18 27 14 3
#include<iostream>
#define COUNT 10
using namespace std;
struct node{
    int data;
    node *pLeft;
    node *pRight;
};
typedef node NODE;
typedef NODE* TREE;
void initTree(TREE &t);
NODE *initNodeTREE(int x);
void insertNode2Tree(TREE &t,NODE *p);
void NLR(TREE t);
void NRL(TREE t);
void LNR(TREE t);
void LRN(TREE t);
void RNL(TREE t);
void RLN(TREE t);
void TaskA(TREE t);
int sumpNode(TREE t,int &dem);
void TaskB(TREE t);
int findMax(TREE t,int &max);
void TaskC(TREE t);
int countnumNodeTree(TREE t,int &countNode);
void TaskD(TREE t);
int countnumLeafNodeTree(TREE t,int &countLeafNode);
void TaskE(TREE t);
int countnum1LeafNodeTree(TREE t,int &count1LeafNode);
void TaskF(TREE t);
int countnum2LeafNodeTree(TREE t,int &count2LeafNode);
void TaskG(TREE t);
void deleteTREE(TREE &t);
int main(){
    TREE t;
    initTree(t);
    int n;
    cout<<"Number of input node : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Node "<<i<<" value : ";
        int x;
        cin>>x;
        NODE *p=initNodeTREE(x);
        if(!p){
            cout<<"Not enough memory";
            return 0;
        }
        insertNode2Tree(t,p);
    }
    TaskA(t);
    TaskB(t);
    TaskC(t);
    TaskD(t);
    TaskE(t);
    TaskF(t);
    TaskG(t);
    deleteTREE(t);
    return 0;
}
void initTree(TREE &t){
    t=NULL;
}
NODE *initNodeTREE(int x){
    NODE *p=new NODE;
    if(!p) return NULL;
    p->data=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}
void insertNode2Tree(TREE &t,NODE *p){
    if(!t) t=p;
    else if(p->data>t->data) insertNode2Tree(t->pRight,p);
    else if(p->data<t->data) insertNode2Tree(t->pLeft,p);
    else{
        cout<<"Duplicate value";
        return;   
    }
}
void NLR(TREE t){
    if(t){
        cout<<t->data<<" ";
        NLR(t->pLeft); 
        NLR(t->pRight); 
    }
}
void NRL(TREE t){
    if(t){
        cout<<t->data<<" ";
        NRL(t->pRight);
        NRL(t->pLeft);  
    }
}
void LNR(TREE t){
    if(t){
        LNR(t->pLeft); 
        cout<<t->data<<" ";
        LNR(t->pRight); 
    }
}
void LRN(TREE t){
    if(t){
        LRN(t->pLeft); 
        LRN(t->pRight);
        cout<<t->data<<" "; 
    }
}
void RNL(TREE t){
    if(t){
        RNL(t->pRight); 
        cout<<t->data<<" ";
        RNL(t->pLeft); 
    }
}
void RLN(TREE t){
    if(t){ 
        RLN(t->pRight);
        RLN(t->pLeft);
        cout<<t->data<<" "; 
    }
}
void TaskA(TREE t){
    cout<<"a)All tree processing : "<<endl;
    cout<<"NLR : ";NLR(t);cout<<endl;
    cout<<"NRL : ";NRL(t);cout<<endl;
    cout<<"LNR : ";LNR(t);cout<<endl;
    cout<<"LRN : ";LRN(t);cout<<endl;
    cout<<"RNL : ";RNL(t);cout<<endl;
    cout<<"RLN : ";RLN(t);cout<<endl;
}
int sumpNode(TREE t){
    if(!t) return 0;
    return t->data + sumpNode(t->pLeft) + sumpNode(t->pRight);
}
void TaskB(TREE t){
    cout<<"b)Sump tree value : "<<sumpNode(t)<<endl;
}
int findMax(TREE t){
    while(t){
        if(t->pRight==NULL){
            return t->data;
        }
        t=t->pRight;
    }
}
void TaskC(TREE t){
    cout<<"c)Max node found in tree : "<<findMax(t)<<endl;
}
int countnumNodeTree(TREE t){
    if(!t) return 0;
    return 1+countnumNodeTree(t->pLeft)+countnumNodeTree(t->pRight);
}
void TaskD(TREE t){
    cout<<"d)Number of node in tree : "<<countnumNodeTree(t)<<endl;
}
int countnumLeafNodeTree(TREE t){
    if(!t) return 0;
    return (t->pLeft==NULL&&t->pRight==NULL) + countnumLeafNodeTree(t->pLeft) + countnumLeafNodeTree(t->pRight);
}
void TaskE(TREE t){
    cout<<"e)Number of 0 leaf node in tree : "<<countnumLeafNodeTree(t)<<endl;
}
int countnum1LeafNodeTree(TREE t){
    if(!t) return 0;
    return (t->pLeft!=NULL&&t->pRight==NULL)||(t->pLeft==NULL&&t->pRight!=NULL) +countnum1LeafNodeTree(t->pLeft)+countnum1LeafNodeTree(t->pRight);
}
void TaskF(TREE t){
    cout<<"f)Number of 1 leaf node in tree : "<<countnum1LeafNodeTree(t)<<endl;
}
int countnum2LeafNodeTree(TREE t){
    if(!t) return 0;
    return (t->pLeft!=NULL&&t->pRight!=NULL) + countnum2LeafNodeTree(t->pLeft) + countnum2LeafNodeTree(t->pRight);
}
void TaskG(TREE t){
    cout<<"g)Number of 2 leaf node in tree : "<<countnum2LeafNodeTree(t)<<endl;
}
void deleteTREE(TREE &t){
    if(t){
        deleteTREE(t->pLeft);
        deleteTREE(t->pRight);
        delete t;
    }
}
