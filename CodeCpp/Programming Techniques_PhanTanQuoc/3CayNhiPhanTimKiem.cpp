#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
// đề bài : nhập vào cây nhị phân các số nguyên . Xuất ra màn hình các phần tử của cây nhị phân
struct node{
    int data; // dữ liệu của node => dữ liệu mà node sẽ lưu trữ
    struct node *pLeft; // node liên kết bên trái của cây <=> cây con trái
    struct node *pRight; // node liên kết bên phải của cây <=> cây con phải
};
typedef node NODE;
typedef NODE* TREE;

// khởi tạo cây
void initTree(TREE &t){
    t=NULL; // cây rỗng
}

// hàm thêm phần tử x vào cây nhị phân
void insertNode2Tree(TREE &t,int x){
    // nếu cây rỗng
    if(t==NULL){
        NODE *p;
        p=new NODE; // khởi tạo 1 cái node để thêm vào cây
        p->data=x; // thêm dữ liệu x vào data
        p->pLeft=NULL;
        p->pRight=NULL;
        t=p; // node p chính là node gốc <=> x là node gốc
    }
    else{ // cây tồn tại phần tử
        // nếu phần tử thêm vào mà nhỏ hơn node gốc => thêm nó vào bên trái 
        if(x<t->data){
            insertNode2Tree(t->pLeft,x); // duyệt qua trái để thêm phần tử x
        }
        else if(x>t->data){// nếu phần tử thêm vào mà lớn hơn node gốc => thêm nó vào bên phải
            insertNode2Tree(t->pRight,x); // duyệt qua phải để thêm phần tử x
        }
    }
}

//hàm xuất cây nhị phân theo NLR
void NLR(TREE t){
    // nếu cây còn phần tử thì tiếp tục duyệt
    if(t!=NULL){
        cout<<t->data<<" "; // xuất dữ liệu trong node
        NLR(t->pLeft); // duyệt qua trái
        NLR(t->pRight); // duyệt qua phải
    }
}

//hàm xuất cây nhị phân theo NRL
void NRL(TREE t){
    // nếu cây còn phần tử thì tiếp tục duyệt
    if(t!=NULL){
        cout<<t->data<<" "; // xuất dữ liệu trong node
        NRL(t->pRight); // duyệt qua phải
        NRL(t->pLeft); // duyệt qua trái
    }
}

//hàm xuất cây nhị phân theo LNR <=> từ bé đến lớn
void LNR(TREE t){
    // nếu cây còn phần tử thì tiếp tục duyệt
    if(t!=NULL){
        LNR(t->pLeft); // duyệt qua trái
        cout<<t->data<<" "; // xuất dữ liệu trong node
        LNR(t->pRight); // duyệt qua phải
    }
}

//hàm xuất cây nhị phân theo LNR <=> Từ lớn đến bé
void RNL(TREE t){
    // nếu cây còn phần tử thì tiếp tục duyệt
    if(t!=NULL){
        RNL(t->pRight); // duyệt qua phải
        cout<<t->data<<" "; // xuất dữ liệu trong node
        RNL(t->pLeft); // duyệt qua trái
    }
}

//hàm xuất cây nhị phân theo LNR <=> Từ lớn đến bé
void LRN(TREE t){
    // nếu cây còn phần tử thì tiếp tục duyệt
    if(t!=NULL){
        LRN(t->pLeft); // duyệt qua trái
        LRN(t->pRight); // duyệt qua phải
        cout<<t->data<<" "; // xuất dữ liệu trong node
    }
}

//hàm xuất cây nhị phân theo LNR <=> Từ lớn đến bé
void RLN(TREE t){
    // nếu cây còn phần tử thì tiếp tục duyệt
    if(t!=NULL){
        LRN(t->pRight); // duyệt qua phải
        LRN(t->pLeft); // duyệt qua trái
        cout<<t->data<<" "; // xuất dữ liệu trong node
    }
}

// đề bài : nhập vào cây nhị phân các số nguyên . Xuất ra có bao nhiêu số nguyên tố trong cây
// hàm kiểm tra số nguyên tố
int snt(int x){
 if(x<2) return 0;
 for(int i=2;i<=sqrt(x);i++){
    if(x%i==0)return 0;
 }
 return 1;
}

// hàm đếm số lượng số nguyên tố 
void countPrimeNumber(TREE t,int &dem){
    if(t!=NULL){
        if(snt(t->data)==1){
            dem++;
        }
        countPrimeNumber(t->pLeft,dem); // duyệt qua trái
        countPrimeNumber(t->pRight,dem); // duyệt qua phải
    }
}

// nếu node có tồn tại trong cây thì trả về cái node đó - còn không tồn tại thì trả về NULL
NODE* search(TREE t,int x){
    // nếu cây rỗng
    if(t==NULL){
        return NULL;
    }
    else{
        // nếu phần tử cần tìm kiếm mà nhỏ hơn node gốc thì duyệt(đệ quy) sang bên trái để tìm
        if(x<t->data)search(t->pLeft,x);
        else if(x>t->data)search(t->pRight,x);
        else{// trả về nút cần tìm kiếm
            return t;
        }
    }
}

// đề bài: tìm node có 2/1/0 con
// xuất các node có 2 con
void outNodeHad2son(TREE t){
    if(t!=NULL){
        if(t->pLeft!=NULL&&t->pRight!=NULL){
            cout<<t->data<<" ";
        }
        outNodeHad2son(t->pLeft);
        outNodeHad2son(t->pRight);
    }
}

// xuất các node có 1 con
void outNodeHad1son(TREE t){
    if(t!=NULL){
        if((t->pLeft==NULL&&t->pRight!=NULL)||(t->pLeft!=NULL&&t->pRight==NULL)){
            cout<<t->data<<" ";
        }
        outNodeHad1son(t->pLeft);
        outNodeHad1son(t->pRight);
    }
}

// xuất các node có 0 con
void outNodeHad0son(TREE t){
    if(t!=NULL){
        if(t->pLeft==NULL&&t->pRight==NULL){
            cout<<t->data<<" ";
        }
        outNodeHad0son(t->pLeft);
        outNodeHad0son(t->pRight);
    }
}

//đề bài: tìm max min trong cây
//hàm tìm phần tử lớn nhất trong cây
int MAX=INT_MIN; // gán cho biến MAX là giá trị nhỏ nhất của kiểu interger
void findMax(TREE t){
    if(t!=NULL){
        if(MAX<t->data){
            MAX=t->data;
        }
        findMax(t->pLeft);
        findMax(t->pRight);
    }
}

//hàm tìm phần tử nhỏ nhất trong cây
int MIN=INT_MAX; // gán cho biến MIN là giá trị lớn nhất của kiểu interger
void findMin(TREE t){
    if(t!=NULL){
        if(MIN>t->data){
            MIN=t->data;
        }
        findMax(t->pLeft);
        findMax(t->pRight);
    }
}
/*
 xóa 1 node bất kì trong cây nhị phân tìm kiếm 
 node x là nếu cần xóa
 1. Node có 0 con(node lá): xóa bình thường - bởi vì lúc này node x đang là node tự do
 (không tồn tại cây con trái và cây con phải)
 2. Node có 1 con: trước khi xóa x, ta chúng ta phải cập nhật mối liên kết giữa node cha của node x với node con(con trái hoặc con phải) của node x
 3. Node có 2 con: trước khi xóa thì ta phải đi tìm 1 cái node thế mạng cho node cần xóa
 - tìm node thế mạng phải đảm bảo quy tắc CNPTK
 + Tìm node trái nhất của cây con phải (cây con phải của cái node cần xóa)
 + Tìm node phải nhất của cây con trái (cây con trái của cái node cần xóa)
*/
//hàm tìm node thế mạng
void NodeTheMang(TREE &X,TREE &Y){ // NODE *Y=t->pRight;
// Cách 1: Tìm node trái nhất của cây con phải (cây con phải của cái node cần xóa)
/*
    // duyệt sang bên trái nhất của cây con phải
    if(Y->pLeft!=NULL){
        NodeTheMang(X,Y->pLeft); // tìm ra node trái nhất  
    }
    else{// đã tìm ra được node trái nhất của cây con phải
        X->data=Y->data; // cập nhật cái data của node cần xóa là data của node thế mạng
        X=Y; // cho node X(chính là node chúng ta sẽ xóa sau này) trỏ đến node thế mạng => ra khỏi hàm thì ta sẽ xóa node x
        Y=Y->pRight; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) đến NULL
        //Y->pRight: NULL
    }
*/
// Cách 2: Tìm node phải nhất của cây con trái (cây con trái của cái node cần xóa)
//
    // duyệt sang bên phải nhất của cây con trái
    if(Y->pRight!=NULL){
        NodeTheMang(X,Y->pRight); // tìm ra node phải nhất  
    }
    else{// đã tìm ra được node phải nhất của cây con trái
        X->data=Y->data; // cập nhật cái data của node cần xóa là data của node thế mạng
        X=Y; // cho node X(chính là node chúng ta sẽ xóa sau này) trỏ đến node thế mạng => ra khỏi hàm thì ta sẽ xóa node x
        Y=Y->pLeft; // bản chất chỗ này chính là cập nhật lại mối liên kết cho node cha của node thế mạng(mà chúng ta sẽ xóa) đến NULL
        //Y->pLeft: NULL
    }
//
}

// hàm xóa 1 cái node bất kì trong CNPTK
void removeNode(TREE &t,int data){// data chính là giá trị của node cần xóa
    // nếu như cây rỗng
    if(t==NULL){
        return; // kết thúc hàm
    }
    else{
        //nếu data nhỏ hơn node gốc
        if(data<t->data){
            removeNode(t->pLeft,data);//duyệt sang nhánh trái của cây
        }
        else if(data>t->data) removeNode(t->pRight,data);//duyệt sang nhánh phải của cây
        else{// data==t->data - đã tìm ra node cần xóa
            NODE *X=t; // node X là node thế mạng
            // nếu như nhánh trái bằng NULL <=> đây là cây có 1 on chính là con phải
            if(t->pLeft==NULL){
                 if(t->pRight==NULL){
                      t=t->pLeft;
                      delete X;
                      exit(0);
                 }
                // duyệt sang phải cái node cần xóa để cập nhật mối liên kết giữa node cha của node cần xóa với node con của node cần xóa
                t=t->pRight; 
            }
            // nếu như nhánh phải bằng NULL <=> đây là cây có 1 on chính là con trái
            else if(t->pRight==NULL){
                // duyệt sang trái cái node cần xóa để cập nhật mối liên kết giữa node cha của node cần xóa với node con của node cần xóa
                t=t->pLeft; 
            }
            else{// node cần xóa là node có 2 con
                // Cách 1: Tìm node trái nhất của cây con phải (cây con phải của cái node cần xóa)
                /*
                NodeTheMang(X,t->pRight);
                */
                // Cách 2: Tìm node phải nhất của cây con trái (cây con trái của cái node cần xóa)
                //
                NodeTheMang(X,t->pLeft);
                //
            }
            delete X; // xóa node cần xóa
        }
    }
}
//hàm nhập dữ liệu
void Menu(TREE &t){
    while(true){
        system("cls");
        cout<<"\n\n\t\t=================Menu=================";
        cout<<"\n\t\t1.Nhap du lieu";
        cout<<"\n\t\t2.Xuat du lieu cay theo NLR:";
        cout<<"\n\t\t3.Xuat du lieu cay theo NRL:";
        cout<<"\n\t\t4.Xuat du lieu cay theo LNR:";
        cout<<"\n\t\t5.Xuat du lieu cay theo RNL:";
        cout<<"\n\t\t6.Xuat du lieu cay theo LRN:";
        cout<<"\n\t\t7.Xuat du lieu cay theo RLN:";
        cout<<"\n\t\t8.Dem so luong snt:";
        cout<<"\n\t\t9.Tim kiem phan tu trong cay nhi phan:";
        cout<<"\n\t\t10.Node co 2 con:";
        cout<<"\n\t\t11.Node co 1 con:";
        cout<<"\n\t\t12.Node co 0 con:";
        cout<<"\n\t\t13.Tim max:";
        cout<<"\n\t\t14.Tim min:";
        cout<<"\n\t\t15.Xoa node X:";
        cout<<"\n\t\t0.Exit";
        cout<<"\n\n\t\t=================End=================\n\t\t";   
        int luachon;
        cout<<"Nhap vao lua chon: ";
        cin>>luachon;
        if(luachon<0||luachon>15){
            cout<<"Lua chon khong hop le";
        } 
        else if(luachon==1){
            int x;
            cout<<"\n\t\tNhap so nguyen x: ";
            cin>>x;
            insertNode2Tree(t,x);
        }
        else if(luachon==2){
            cout<<"\n\t\tDuyet cay theo NLR: ";
            NLR(t);
            getch();
        }
        else if(luachon==3){
            cout<<"\n\t\tDuyet cay theo NLR: ";
            NRL(t);
            getch();
        }
        else if(luachon==4){
            cout<<"\n\t\tDuyet cay theo LNR: ";
            LNR(t);
            getch();
        }
        else if(luachon==5){
            cout<<"\n\t\tDuyet cay theo RNL: ";
            RNL(t);
            getch();
        }
        else if(luachon==6){
            cout<<"\n\t\tDuyet cay theo LRN: ";
            LRN(t);
            getch();
        }
        else if(luachon==7){
            cout<<"\n\t\tDuyet cay theo RLN: ";
            LRN(t);
            getch();
        }
        else if(luachon==8){
            int dem=0;
            countPrimeNumber(t,dem);
            cout<<"\n\t\tSo luong snt : "<<dem;
            getch();
        }
        else if(luachon==9){
            int x;
            cout<<"\nNhap phan tu can tim kiem : ";
            cin>>x;
            NODE *p=search(t,x);
            if(p==NULL){
                cout<<"\n\t\tX not found in tree";
            }
            else{
                cout<<"\n\t\tX found in tree";
            }
            getch();
        }
        else if(luachon==10){
            cout<<"\n\t\tNode co 2 con : ";
            outNodeHad2son(t);
            getch();
        }
        else if(luachon==11){
            cout<<"\n\t\tNode co 1 con : ";
            outNodeHad1son(t);
            getch();
        }
        else if(luachon==12){
            cout<<"\n\t\tNode co 0 con : ";
            outNodeHad0son(t);
            getch();
        }
        else if(luachon==13){
            findMax(t);
            cout<<"\n\t\tGTLN : "<<MAX;
            getch();
        }
        else if(luachon==14){
            findMin(t);
            cout<<"\n\t\tGTNN : "<<MIN;
            getch();
        }
        else if(luachon==15){
            int x;
            cout<<"\n\t\tNhap gia tri X can xoa : ";
            cin>>x;
            removeNode(t,x);
        }
        else{
            break;
        }
    }
}
int main(){
    TREE t;
    initTree(t);
    Menu(t);
    return 0;
}