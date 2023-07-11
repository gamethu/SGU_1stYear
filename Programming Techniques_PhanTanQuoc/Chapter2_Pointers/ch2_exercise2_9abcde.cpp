// 20 10 30 16 8 40 25 6 7 19 37 1 4 18 27 14 3
#include<iostream>
#include<math.h>
using namespace std;
struct node{
    int data;
    node *pLeft;
    node *pRight;
};
typedef node NODE;
typedef NODE *TREE;
void initTree(TREE &t);
NODE *initNodeTREE(int x);
void insertNode2Tree(TREE &t,NODE *p);
void NLR(TREE t);
int prime(int x);
void countPrimeNode(TREE t,int &count);
void TaskA(TREE t);
NODE* search_Xvalue(TREE t,int x);
void TaskB(TREE t);
void searchWay2_Xvalue(TREE t,int x);
void TaskC(TREE t);
void findRank_Xvalue(TREE t,int x,int &rankXvalue);
void TaskD(TREE t);
int findTreeHigh(TREE t);
void TaskE(TREE t);
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
    cout<<"All tree node processing : ";NLR(t);cout<<endl;
    TaskA(t);
    TaskB(t);
    TaskC(t);
    TaskD(t);
    TaskE(t);
    deleteTREE(t);
    return 0;
}
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
    if(!t) t=p;
    else if(p->data>t->data) insertNode2Tree(t->pRight,p);
    else if(p->data<t->data) insertNode2Tree(t->pLeft,p);
}
void NLR(TREE t){
    if(t){
        cout<<t->data<<" ";
        NLR(t->pLeft); 
        NLR(t->pRight); 
    }
}
int prime(int x){
    if(x<2)return 0;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return 0;
    }
    return 1;
}
void countPrimeNode(TREE t,int &count){
    if(t){
        if(prime(t->data)==1) count++;
        countPrimeNode(t->pLeft,count);
        countPrimeNode(t->pRight,count); 
    }
}
void TaskA(TREE t){
    int count=0;
    countPrimeNode(t,count);
    cout<<"a)Number of prime node : "<<count<<endl;
}
NODE *search_Xvalue(TREE t,int x){
    if(!t) return NULL;
    else if(x<t->data)search_Xvalue(t->pLeft,x);
    else if(x>t->data)search_Xvalue(t->pRight,x);
    else return t;
}
void TaskB(TREE t){
    cout<<"Value need to find: ";
    int x;
    cin>>x;
    NODE *p=search_Xvalue(t,x);
    if(!p){
        cout<<"b)X not found"<<endl;
    }
    else{
        cout<<"b)X found"<<endl; 
    }
}
void searchWay2_Xvalue(TREE t,int x){
    if(!t) return;
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
void TaskC(TREE t){
    cout<<"Find way to node:";
    int x;
    cin>>x;
    if(!search_Xvalue(t,x)){
        cout<<"c)Way from root to X value not found!!!"<<endl;
        return;
    }
    cout<<"c)Way from root to X value : ";
    searchWay2_Xvalue(t,x);cout<<endl;
}
void findRank_Xvalue(TREE t,int x,int &rankXvalue){
    if(!t) return;
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
void TaskD(TREE t){
    cout<<"Rank value X need to find : ";
    int x;
    cin>>x;
    if(!search_Xvalue(t,x)){
        cout<<"d)Rank X value not found!!!"<<endl;
        return;
    }
    int rankXvalue=-1;
    findRank_Xvalue(t,x,rankXvalue);
    cout<<"d)Rank value X : "<<rankXvalue<<endl;
}
int findTreeHigh(TREE t){
    if(!t)return 0;
    else{  
        long hl=findTreeHigh(t->pLeft);
        long hr=findTreeHigh(t->pRight);
        return 1+((hl<hr)?hr:hl);
    } 
}
void TaskE(TREE t){
    cout<<"e)Tree high : "<<findTreeHigh(t);
}
void deleteTREE(TREE &t){
    if(t){
        deleteTREE(t->pLeft);
        deleteTREE(t->pRight);
        delete t;
    }
}