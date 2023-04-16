// 20 10 30 16 8 40 25 6 7 19 37 1 4 18 27 14 3
#include<iostream>
#include<math.h>
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
int snt(int x){
    if(x<2)return 0;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return 0;
    }
    return 1;
}
int count=0;
void countPrimeNode(TREE t,int &count){
    if(t!=NULL){
        if(snt(t->data)==1){
            count++;
        }
        countPrimeNode(t->pLeft,count); 
        countPrimeNode(t->pRight,count); 
    }
}
NODE* search_Xvalue(TREE t,int x){
    if(t==NULL){
        return NULL;
    }
    else if(x<t->data)search_Xvalue(t->pLeft,x);
    else if(x>t->data)search_Xvalue(t->pRight,x);
    else return t;
}
void searchWay2_Xvalue(TREE t,int x){
    if(t==NULL){
        return;
    }
    else if(x<t->data){
        cout<<t->data<<" ";
        searchWay2_Xvalue(t->pLeft,x);
    }
    else if(x>t->data){
        cout<<t->data<<" ";
        searchWay2_Xvalue(t->pRight,x);
    }
    else{
        cout<<t->data<<" ";  
        return;
    } 
}
int rankXvalue=-1;
void findRank_Xvalue(TREE t,int x,int &rankXvalue){
    if(t==NULL){
        return;
    }
    else if(x<t->data){
        rankXvalue++;
        findRank_Xvalue(t->pLeft,x,rankXvalue);
    }
    else if(x>t->data){
        rankXvalue++;
        findRank_Xvalue(t->pRight,x,rankXvalue);
    }
    else{  
        rankXvalue++;
        return;
    } 
}
int findTreeHigh(TREE t){
    if(t==NULL){
        return 0;
    }
    else{  
        long hl=findTreeHigh(t->pLeft);
        long hr=findTreeHigh(t->pRight);
        return 1+((hl<hr)?hr:hl);
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
    cout<<"All tree node processing : ";
    NLR(t);cout<<endl;
    countPrimeNode(t,count);
    cout<<"a)Number of prime node : "<<count<<endl;
    cout<<"Value X need to find : ";
    int x;
    cin>>x;
    NODE *p;
    p=search_Xvalue(t,x);
    if(p==NULL){
        cout<<"b)X not found"<<endl;
    }
    else{
        cout<<"b)X found"<<endl; 
    }
    cout<<"c)Way from root to X value : ";
    searchWay2_Xvalue(t,x);cout<<endl;
    cout<<"Rank value X need to find : ";
    cin>>x;
    findRank_Xvalue(t,x,rankXvalue);
    cout<<"d)Rank value X : "<<rankXvalue<<endl;
    cout<<"e)Tree high : "<<findTreeHigh(t);
    return 0;
}