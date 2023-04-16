// 20 10 30 16 8 40 25 6 7 19 37 1 4 18 27 14 3
#include<iostream>
#define COUNT 10
using namespace std;
struct node{
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef node NODE;
typedef NODE* TREE;
void initTree(TREE &t){
    t=NULL;
}
NODE *initNodeTREE(int x){
    NODE *p;
    p=new NODE;
    if(!p){
        cout<<"Not enough memory";
        exit(0);
    }
    p->data=x;
    p->pLeft=NULL;
    p->pRight=NULL;
    return p;
}
void insertNode2Tree(TREE &t,NODE *p){
    if(t==NULL){
        t=p;
    }
    else if(p->data>t->data) insertNode2Tree(t->pRight,p);
    else if(p->data<t->data) insertNode2Tree(t->pLeft,p);
}
void NLR(TREE t){
    if(t!=NULL){
        cout<<t->data<<" ";
        NLR(t->pLeft); 
        NLR(t->pRight); 
    }
}
void NRL(TREE t){
    if(t!=NULL){
        cout<<t->data<<" ";
        NRL(t->pRight);
        NRL(t->pLeft);  
    }
}
void LNR(TREE t){
    if(t!=NULL){
        LNR(t->pLeft); 
        cout<<t->data<<" ";
        LNR(t->pRight); 
    }
}
void LRN(TREE t){
    if(t!=NULL){
        LRN(t->pLeft); 
        LRN(t->pRight);
        cout<<t->data<<" "; 
    }
}
void RNL(TREE t){
    if(t!=NULL){
        RNL(t->pRight); 
        cout<<t->data<<" ";
        RNL(t->pLeft); 
    }
}
void RLN(TREE t){
    if(t!=NULL){ 
        RLN(t->pRight);
        RLN(t->pLeft);
        cout<<t->data<<" "; 
    }
}
int dem=0;
void sumpNode(TREE t,int &dem){
    if(t!=NULL){
        dem=dem+t->data;
        sumpNode(t->pLeft,dem); 
        sumpNode(t->pRight,dem); 
    }
}
int MAX=INT_MIN;
void findMax(TREE t){
    if(t!=NULL){
        if(MAX<t->data){
            MAX=t->data;   
        }
        findMax(t->pLeft); 
        findMax(t->pRight); 
    }
}
int countNode=0;
void countnumNodeTree(TREE t,int &countNode){
    if(t!=NULL){
        countNode++;
        countnumNodeTree(t->pLeft,countNode); 
        countnumNodeTree(t->pRight,countNode); 
    }
}
int countLeafNode=0;
void countnumLeafNodeTree(TREE t,int &countLeafNode){
    if(t!=NULL){
        if(t->pLeft==NULL&&t->pRight==NULL){ 
        countLeafNode++;
        }
        countnumLeafNodeTree(t->pLeft,countLeafNode); 
        countnumLeafNodeTree(t->pRight,countLeafNode); 
    }
}
int count1LeafNode=0;
void countnum1LeafNodeTree(TREE t,int &count1LeafNode){
    if(t!=NULL){
        if((t->pLeft!=NULL&&t->pRight==NULL)||(t->pLeft==NULL&&t->pRight!=NULL)){ 
            count1LeafNode++;
        }
        countnum1LeafNodeTree(t->pLeft,count1LeafNode); 
        countnum1LeafNodeTree(t->pRight,count1LeafNode); 
    }
}
int count2LeafNode=0;
void countnum2LeafNodeTree(TREE t,int &count2LeafNode){
    if(t!=NULL){
        if(t->pLeft!=NULL&&t->pRight!=NULL){ 
            count2LeafNode++;
        }
        countnum2LeafNodeTree(t->pLeft,count2LeafNode); 
        countnum2LeafNodeTree(t->pRight,count2LeafNode); 
    }
}
void print2DUtil(TREE t,int space){
    if(!t) return;
    space+=COUNT;
    print2DUtil(t->pRight,space);
    cout<<endl;
    for(int i=COUNT;i<space;i++){
        cout<<t->data<<endl;
        print2DUtil(t->pLeft,space);
    }
}
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
        NODE *p;
        p=initNodeTREE(x);
        insertNode2Tree(t,p);
    }
    cout<<"a)All tree processing : "<<endl;
    cout<<"NLR : ";NLR(t);cout<<endl;
    cout<<"NRL : ";NRL(t);cout<<endl;
    cout<<"LNR : ";LNR(t);cout<<endl;
    cout<<"LRN : ";LRN(t);cout<<endl;
    cout<<"RNL : ";RNL(t);cout<<endl;
    cout<<"RLN : ";RLN(t);cout<<endl;
    sumpNode(t,dem);
    cout<<"b)Sump tree value : "<<dem<<endl;
    findMax(t);
    cout<<"c)Max node found in tree : "<<MAX<<endl;
    countnumNodeTree(t,countNode);
    cout<<"d)Number of node in tree : "<<countNode<<endl;
    countnumLeafNodeTree(t,countLeafNode);
    cout<<"e)Number of 0 leaf node in tree : "<<countLeafNode<<endl;
    countnum1LeafNodeTree(t,count1LeafNode);
    cout<<"f)Number of 1 leaf node in tree : "<<count1LeafNode<<endl;
    countnum2LeafNodeTree(t,count2LeafNode);
    cout<<"g)Number of 2 leaf node in tree : "<<count2LeafNode<<endl;
    int space;
    print2DUtil(t,space);
    return 0;
}
