#include<iostream>
using namespace std;
struct node{
    int data; // dữ liệu trong 1 cái node (tùy thuộc vào ycbt)
    struct node *pNext; // con trỏ dùng để liên kết các Node với nhau
};
typedef node NODE; // thay thế "struct node" thành "NODE"

// Hàm khai báo cấu trúc của dslk đơn
struct list{
    NODE *pHead; // node quản lí đầu danh sách
    NODE *pTail; // node quản lí cuối danh sách
};
typedef list LIST; // thay thế "struct list" thành "LIST"

void KhoiTaoDSLK(LIST &l){
    // cho 2 node trỏ đến NULL - vì danh sách liên kết đơn chưa có phần tử
    l.pHead=NULL;
    l.pTail=NULL;
}

// Hàm khởi tạo 1 cái node
NODE *KhoiTaoNODE(int x){ // kiểu dữ liệu x giống data
NODE *p;
p=new NODE; // cấp phát vùng nhớ cho NODE p
if(!p){
    cout<<"Not enough memory";
    exit(0);
}
p->data=x; // truyền giá trị x vào cho data
p->pNext=NULL; // đầu tiên khai báo node thì node đó chưa có liên kết với NODE nào hết -> Con trỏ của nó sẽ trỏ đến NULL
return p; // trả về NODE p vừa khởi tạo
}

// Hàm thêm node vào đầu danh sách liên kết
void ThemVaoDau(LIST &l,NODE *p){
    // Danh sách đang rỗng
    if(l.pHead==NULL){
        l.pHead=l.pTail=p; // node đầu cũng chính là node cuối và là p
    }
    else{
        p->pNext=l.pHead; // Cho con trỏ của node cần thêm là node p liên kết với node đầu - pHead
        l.pHead=p; // cập nhật lại pHead chính là node p
    }
}

// Hàm thên node p vào cuối danh sách liên kết đơn
void ThemVaoCuoi(LIST &l,NODE *p){
    // Danh sách đang rỗng
    if(l.pHead==NULL){
        l.pHead=l.pTail=p; // node đầu cũng chính là node cuối và là p
    }
    else{
        l.pTail->pNext = p; // Cho con trỏ của pTail liên kết với node p
        l.pTail=p; // cập nhật lại p chính là node pTail
    }
}

// Hàm xuất dslk đơn
void XuatDanhSach(LIST l){
    // for(int i=0;i<n;i++) 
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        cout<<k->data<<" ";
    }
}

//  Hàm tìm giá trị lớn nhất trong danh sách
int TimMax(LIST l){
    int max=l.pHead->data; // giả sử node đầu là node lớn nhất
    // bắt đầu duyệt từ node thứ 2 để kiểm tra
    for(NODE *k=l.pHead->pNext;k!=NULL;k=k->pNext){
        if(max<k->data){
            max=k->data; // cập nhật lại giá trị max
        }
    }
    return max;
}
int main(){
    LIST l;
    KhoiTaoDSLK(l); // khởi tạo dslk đơn trước khi thao tác với danh sách

    int n;
    cout<<"Nhap so luong node can them : ";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cout<<endl;
        cout<<"Nhap gia tri so nguyen : ";
        cin>>x;
        NODE *p=KhoiTaoNODE(x); // Khởi tạo 1 cái node số nguyên
        //ThemVaoDau(l,p); // Thêm node p vào đầu dslk đơn
        ThemVaoCuoi(l,p); // Thêm node p vào cuối dslk đơn
    }
    cout<<"\n\n\t DANH SACH LIEN KET DON\n";
    XuatDanhSach(l);
    cout<<"\n\n\t GIA TRI LON NHAT\n";
    cout<<TimMax(l);
    return 0;
}