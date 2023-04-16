#include<iostream>
#include<conio.h>
using namespace std;
int n=0; // khai báo biến toàn cục - (chứa số lượng phần tử trong danh sách)
struct node{
    int data; // dữ liệu trong 1 cái node (tùy thuộc vào ycbt)
    struct node *pNext; // con trỏ dùng để liên kết các Node với nhau
};
typedef struct node NODE; // thay thế "struct node" thành "NODE"

// Hàm khai báo cấu trúc của dslk đơn
struct list{
    NODE *pHead; // node quản lí đầu danh sách
    NODE *pTail; // node quản lí cuối danh sách
};
typedef struct list LIST; // thay thế "struct list" thành "LIST"

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
    return NULL;
    // exit(1);
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

// hàm xóa đầu
void XoaDau(LIST &l){
    //Nếu danh sách rỗng
    if(l.pHead=NULL){
        return;
    }
    else{
        NODE *p;
        p=l.pHead; // node p là node sẽ xóa
        l.pHead=l.pHead->pNext; //cập nhật lại l.pHead là phần tử kế tiếp
        delete p;
    }
}

// hàm xóa cuối
void XoaCuoi(LIST &l){
    //Nếu danh sách rỗng
    if(l.pHead=NULL){
        return;
    }
    if(l.pHead->pNext==NULL){
        XoaDau(l);
        return;
    }
    // duyệt từ đầu danh sách đến kế cuối 
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        // phát hiện thằng kế cuối
        if(k->pNext==l.pTail){
            delete l.pTail; // xóa đi phần tử cuối
            k->pNext=NULL; // cho con trỏ của node kế cuối trỏ đến vùng nhớ NULL
            l.pTail=k;// Cập nhật lại l.pTail
            return;
        }
    }
}

// hàm xóa 1 node nằm sau node q trong danh sách
void XoaSau(LIST &l,NODE *q){
    // duyệt danh sách từ đầu đến cuối để tìm node q
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        if(k->data==q->data){
            NODE *g =k->pNext; // node g chính là node nằm sau node k <=> node mà ta sẽ xóa  
            k->pNext=g->pNext; // cập nhật mối liên kết giữa node k (node q) với node sau node g
            delete g; // xóa node nằm sau node q
        }
    }
}
// Hàm xuất dslk đơn
void XuatDanhSach(LIST l){
    // for(int i=0;i<n;i++) 
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        cout<<k->data<<" ";
    }
}

// hàm xóa 1 node có hóa k bất kì
void XoaNodeCoKhoaKBatKi(LIST &l,int x){
    //nếu danh sách rỗng thì không làm gì hết
    if(l.pHead==NULL){
        return;
    }
    // nếu node cần xóa nằm đầu danh sách
    if(l.pHead->data==x){
        XoaDau(l);
        return;
    }
    if(l.pTail->data==x){
        XoaCuoi(l);
        return;
    }
    NODE *g=new NODE; // node g là node trỏ đến node nằm trước node cần xóa : x
    //duyệt danh sách liên kết đơn để tìm
    for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        //phát hiện phần tử cần xóa
        if(k->data==x){ 
            g->pNext=k->pNext; // cập nhật mối liên kết giữa node k với node sau node h
            delete k; // xóa node nằm sau node q
            return;
        }
        g=k; // cho node g trỏ đến node k
    }
}
// Hàm thêm node p vào sau node q (nằm trong dslk đơn)
void ThemNode_pVaoSauNode_q(LIST &l,NODE *p){
    int x;
    cout<<"\nNhap gia tri node q : ";
    cin>>x;
    NODE *q;
    q=KhoiTaoNODE(x);
    // Nếu danh sách chỉ có 1 phần tử và phần tử đó cũng chính là node q -> bài toán trở thành kĩ thuật thêm vào cuối danh sách
    if(q->data==l.pHead->data&&l.pHead->pNext==NULL){
        ThemVaoCuoi(l,p);
    }
    else{
        // duyệt từ đầu danh sách đến cuối danh sách để tìm node q (có 2 phần tử trở lên)
        for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
            // Nếu node q có tồn tại thì thêm node p vào sau node q
            if(q->data==k->data){
                NODE *h;
                h=KhoiTaoNODE(p->data); // Khởi tạo node h mới để thêm vào sau node q
                NODE *g;
                g=k->pNext; // gán node g trỏ đến node nằm sau node q
                h->pNext=g; // Bước 1: Tạo mối liên kết từ node h đến node g <=> cũng chính là tạo mối liên kết từ node h đến node nằm sau node q
                k->pNext=h; // Bước 2: Tạo mối liên kết từ node q đến node h <=> chính là node k đến node h
            }
        }
    }
}

// Hàm thêm node p vào trước node q (nằm trong dslk đơn)
void ThemNode_pVaoTruocNode_q(LIST &l,NODE *p){
    int x;
    cout<<"\nNhap gia tri node q : ";
    cin>>x;
    NODE *q;
    q=KhoiTaoNODE(x);
    // Nếu danh sách chỉ có 1 phần tử và phần tử đó cũng chính là node q -> bài toán trở thành kĩ thuật thêm vào đầu danh sách
    if(q->data==l.pHead->data&&l.pHead->pNext==NULL){
        ThemVaoDau(l,p);
    }
    else{
        NODE *g;
        g=new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
        // duyệt từ đầu danh sách đến cuối danh sách để tìm node q (có 2 phần tử trở lên)
        for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
            // Nếu node q có tồn tại thì thêm node p vào trước node q
            if(q->data==k->data){
                NODE *h;
                h=KhoiTaoNODE(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h mới
                // thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
                h->pNext=k; // Bước 1: Tạo mối liên kết từ nối h đến node k <=> cũng chính là tạo mối liên kết từ node h đến node nằm sau node q
                g->pNext=h; // Bước 2: Tạo mối liên kết từ node g đến node p <=> chính là node k đến node g
            }
        g=k; // giữ liên kết với cái node nằm trước node q trong danh sách
        }
    }
}
/*CÁch 1
//Hàm thêm 1 node p vào 1 vị trí vt trong danh sách l
void ThemNode_pVaoViTriBatKi(LIST &l,NODE *p,int vt,int n){

    // danh sách đang rỗng
    if(l.pHead==NULL||vt==1){
        //thêm node p vào đầu danh sách l
        ThemVaoDau(l,p);
    }
    else if(vt==n+1){
        // thêm node p vào cuối danh sách l
        ThemVaoCuoi(l,p);
    }
    else{ // vt nằm trong đoạn [2,n]
    int dem=0; // xác định vt cần thêm
        NODE *g;
        g=new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
        // duyệt từ đầu danh sách đến cuối danh sách để tìm node q <=> tìm ra vị trí vt cần thên node q vào
        for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
            dem++;
            // tìm vị trí vt cần thêm
            if(dem==vt){
                NODE *h;
                h=KhoiTaoNODE(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h mới
                // thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
                h->pNext=k; // Bước 1: Tạo mối liên kết từ nối h đến node k <=> cũng chính là tạo mối liên kết từ node h đến node nằm sau node q
                g->pNext=h; // Bước 2: Tạo mối liên kết từ node g đến node p <=> chính là node k đến node g
                break;
            }
        g=k; // giữ liên kết với cái node nằm trước node q trong danh sách
        }
    }
}
*/
//CÁCh 2: sử dụng biến toàn cục
//Hàm thêm 1 node p vào 1 vị trí vt trong danh sách l
void ThemNode_pVaoViTriBatKi(LIST &l,NODE *p,int vt){

    // danh sách đang rỗng
    if(l.pHead==NULL||vt==1){
        //thêm node p vào đầu danh sách l
        ThemVaoDau(l,p);
    }
    else if(vt==n+1){
        // thêm node p vào cuối danh sách l
        ThemVaoCuoi(l,p);
    }
    else{ // vt nằm trong đoạn [2,n]
    int dem=0; // xác định vt cần thêm
        NODE *g;
        g=new NODE; // node g chính là node giữ liên kết với cái node nằm trước node q trong danh sách
        // duyệt từ đầu danh sách đến cuối danh sách để tìm node q <=> tìm ra vị trí vt cần thên node q vào
        for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
            dem++;
            // tìm vị trí vt cần thêm
            if(dem==vt){
                NODE *h;
                h=KhoiTaoNODE(p->data); // mỗi lần phát hiện 1 node q thì ta khởi tạo 1 node p mới <=> khởi tạo node h mới
                // thực hiện bài toán thêm node p vào sau node g là ra vấn đề <=> thêm node p vào trước node q
                h->pNext=k; // Bước 1: Tạo mối liên kết từ nối h đến node k <=> cũng chính là tạo mối liên kết từ node h đến node nằm sau node q
                g->pNext=h; // Bước 2: Tạo mối liên kết từ node g đến node p <=> chính là node k đến node g
                break;
            }
        g=k; // giữ liên kết với cái node nằm trước node q trong danh sách
        }
    }
}

//hàm giải phóng vùng nhớ cho danh sách liên kết đơn
void Giai_Phong_Danh_Sach(LIST &l){
    // //duyệt từ đầu danh sách đến cuối danh sách
    // for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
        
    //     delete k; // giải phóng từng cái node trong danh sách
    // }
    NODE *k=NULL;
    while(l.pHead!=NULL){
        k=l.pHead;
        l.pHead=l.pHead->pNext;
        delete k;
    }
}
// menu
void Menu(LIST &l){
    int luachon;
    while(69){
        system("cls");
        cout<<"\n\n\t============Menu==============";
        cout<<"\n\n\t1. Them node vao danh sach";
        cout<<"\n\t2. Xuat danh sach lien ket don";
        cout<<"\n\t3. Them node p vao sau node q trong danh sach";
        cout<<"\n\t4. Them node p vao truoc node q trong danh sach";
        cout<<"\n\t5. Them node p vao vi tri bat ki trong danh sach";
        cout<<"\n\t6. Xoa dau danh sach";
        cout<<"\n\t7. Xoa cuoi danh sach";
        cout<<"\n\t8. Xoa node sau node q trong danh sach";
        cout<<"\n\t9. Xoa node co khoa k bat ki trong danh sach";
        cout<<"\n\t0. Thoat";
        cout<<"\n\n\t============Menu==============";
        cout<<"\nNhap n : ";
        cin>>luachon;
        if(luachon<0||luachon>9){
            cout<<"Lua chon khong hop le!";
        }
        if(luachon==1){
            int x;
            cout<<"Nhap gia tri so nguyen : ";
            cin>>x;
            NODE *p;
            p=KhoiTaoNODE(x); // khởi tạo 1 cái node
            ThemVaoCuoi(l,p); // thêm node vào cuối danh sách
            n++; // cách 2
        }
        else if(luachon==2){
            XuatDanhSach(l); 
            getch();
        }
        else if(luachon==3){
            cout<<"Nhap gia tri node p can them vao sau : ";
            int x;
            cin>>x;
            NODE *p;
            p=KhoiTaoNODE(x);
            ThemNode_pVaoSauNode_q(l,p); // thêm node p vào sau node q trong danh sách l
            n++;
        }
        else if(luachon==4){
            cout<<"Nhap gia tri node p can them vao truoc : ";
            int x;
            cin>>x;
            NODE *p;
            p=KhoiTaoNODE(x);
            ThemNode_pVaoTruocNode_q(l,p); // thêm node p vào trước node q trong danh sách l
            n++;
        }
        else if(luachon==5){
            // cách 1
            // int n=0;
            // //vòng lặp lấy số lượng node trong danh sách
            // for(NODE *k=l.pHead;k!=NULL;k=k->pNext){
            //  n++;
            // }
            //khởi tạo giá trị cho node p
            int x;
            cout<<"Nhap gia tri node p can them : ";
            cin>>x;
            NODE *p;
            p=KhoiTaoNODE(x);
            // nhập vị trí cần thêm cho node p => cần kiểm tra điều kiện
            int vt;
            do
            {
                cout<<"\nNhap vi tri can them node p : ";
                cin>>vt;
                if(vt<1||vt>n+1){
                    cout<<"\nVi tri can them phai nam trong doan [1;"<<n+1<<"]";
                    getch();
                }
            } while (vt<1||vt>n+1);
        //ThemNode_pVaoViTriBatKi(l,p,vt); cách 1
        ThemNode_pVaoViTriBatKi(l,p,vt);// cách 2
        n++;
        }
        else if(luachon==6){
            XoaDau(l);
        }
        else if(luachon==7){
            XoaCuoi(l);
            n--;
        }
        else if(luachon==8){
            int x;
            cout<<"\nNhap node q : ";
            cin>>x;
            NODE *q=KhoiTaoNODE(x);
            XoaSau(l,q);
        }
        else if(luachon==9){
            int x;
            cout<<"\nNhap node can xoa : ";
            cin>>x;
            NODE *q=KhoiTaoNODE(x);
            XoaNodeCoKhoaKBatKi(l,x);
        }
        else{
            break; // thoát khỏi vòng lặp hiện tại
        }
    }
}

int main(){
    LIST l;
    KhoiTaoDSLK(l); // khởi tạo dslk đơn trước khi thao tác với danh sách
    Menu(l);
    Giai_Phong_Danh_Sach(l);
    return 0;
}