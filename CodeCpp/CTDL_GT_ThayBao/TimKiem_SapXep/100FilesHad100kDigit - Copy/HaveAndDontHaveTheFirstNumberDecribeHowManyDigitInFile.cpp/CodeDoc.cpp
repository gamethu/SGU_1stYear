#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<string.h>
#include<math.h>
#include<time.h> // Hàm tính thời gian chạy thuật toán
#define MAX 100001
void InterchangeSort(int *&a,int num);
void BubbleSort(int *&a, int num);
void ShakerSort(int *&a,int num);
void InsertSort(int *&a,int num);

int BinarySearchForPosition(int *a,int num,int x);
void BinaryInsertSort(int *&a,int num);

void ShellSort(int *&a,int num,int h[],int k);
void SelectionSort(int *&a,int num);

void InsertHeap(int *&a,int left,int right);
void CreateHeap(int *&a,int num);
void HeapSort(int *&a,int num);

void QuickSort(int *&a,int left,int right);

void merge(int *&a,int left,int mid,int right);
void MergeSort(int *&a,int left,int right);

int Digit(int num,int k);
int countDigit(int num);
int getMaxDigit(int *a,int num);
void returnValue(int *&a,int *b[10],int t[10]);
void send2Box(int *a,int *b[],int num,int t[10],int k);
void RadixSort(int *&a,int num);    

void swap(int &a,int &b);
using namespace std;
int main(){  
    int FileNumber=1;
    double s=0;
    float best=pow(10,6);
    float worst=0;
    while(FileNumber<=100){ // tạo tối đa 100 file
        clock_t start, end;   // Khai báo biến thời gian
        double time_use;      // Thời gian sử dụng
    FILE *fp;
    char filename[1];
    // khai báo chuỗi kí tự "filename chỉ có 1 phần tử" vì "trong mỗi vòng lặp chỉ có tối đa 1 phần tử có tên là filename được sử dụng để gán làm file"
    sprintf(filename, "filename%d.txt",FileNumber); //tạo tên file dựa trên số thứ tự FileNumber
    fp=fopen(filename,"rt"); // gán tên file đã tạo ở trên vào mở file mới để đọc dữ liệu
    if(!fp){
        cout<<"Cant open this file";
        exit(0);
    }
    //Cách 1 : Đọc file đã có dòng mô tả mô tả phần tử tối đa có trong file
    //
    int num;
    fscanf(fp,"%d",&num); 
    //
    //Cách 2 : Đọc file không có dòng mô tả mô tả phần tử tối đa có trong file
    /*
    int num=0;
    int temp;
    while(!feof(fp)){
       fscanf(fp," %d",&temp);
       num++;
    }
    fseek(fp,1,0);
    */
    if(num<=0){
        cout<<"Data error";
        fclose(fp);
        exit(0);
    }
    int *a;
    a=new int[num]; // khai báo num khối nhớ kiểu int cho con trỏ a
    if(!a){
        cout<<"Not enough memory!";
        fclose(fp);
        exit(0);
    }
    int temp;
    for(int i=0;i<num;i++){
        fscanf(fp," %d",&temp);
        a[i]=temp;
    }
    fclose(fp);
    start = clock();     // Lấy thời gian trước khi thực hiện thuật toán

    // InterchangeSort(a,num);
    // BubbleSort(a,num);
    // ShakerSort(a,num);
    // InsertSort(a,num);
    // BinaryInsertSort(a,num);

    int h[3]={5,3,1};
    int k;
    ShellSort(a,num,h,3);

    // SelectionSort(a,num);
    // HeapSort(a,num); 
    // QuickSort(a,0,num-1); // Cách 1 // Cách 2 // Đang xài cách 1
    // MergeSort(a,0,num-1);
    /// RadixSort(a,num);
    
    end = clock();  // lấy thời gian sau khi thực hiện 
    time_use=(double)(end-start)/CLOCKS_PER_SEC;    //Tính thời gian sử dụng
    if(time_use>worst) worst=time_use;
    if(time_use<best) best=time_use;
    s=s+time_use;
    cout<<"Time processcing of file number "<<FileNumber<<" : "<<time_use<<"s"<<endl;
    delete []a;
    FileNumber++;
    if(FileNumber>100){
        cout<<"Average time processing : "<<(s*1.0)/(FileNumber-1)<<"s"<<endl;
        cout<<"Slowest time processing could have : "<<worst<<"s"<<endl;
        cout<<"Fastest time processing could have : "<<best<<"s"<<endl;
        delete []a;// xóa bộ nhớ cấp phát khi đã đủ 100 file
    }
    }
    cout<<"Finished!";  
    return 0;
}
void swap(int &a,int &b){
    int temp=a;
        a=b;
        b=temp;
}

//                                                                INTERCHANGE SORT

void InterchangeSort(int *&a,int num){
    for(int i=0;i<num-1;i++){
        for(int j=i+1;j<num;j++)
            if(a[i]>a[j]) swap(a[i],a[j]); // Hoán vị hai phần tử ở vị trí i j
    }
}
                                                                    
//                                                                INTERCHANGE SORT                     

//                                                                BUBBLE SORT

void BubbleSort(int *&a, int num){
    for(int i=0;i<num;i++){
        for(int j=num-1;j>i;j--){
            if(a[j-1]>a[j]) swap(a[j-1],a[j]);
        }
    }
}
 
//                                                                BUBBLE SORT

//                                                               SHAKER SORT
// hv = hoan vi
void ShakerSort(int *&a,int num){
    int up=0,down=num-1,hv=0;
    while(up<down){
        for(int i=up;i<down;i++){
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
                hv=i;
            }
        }
        down=hv;
        for(int j=down;j>up;j--){
            if(a[j-1]>a[j]){
                swap(a[j-1],a[j]);
                hv=j;
            }
        }
        up=hv;
    }
}
               
//                                                               SHAKER SORT

//                                                               INSERT SORT

void InsertSort(int *&a,int num){
    for(int i=1;i<num;i++){
        int x=a[i],j=i-1;
        while(x<a[j]&&j>=0){
            swap(a[j+1],a[j]); // a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

//                                                              INSERT SORT

//                                                            BINARY INSERT SORT  

int BinarySearchForPosition(int *a,int num,int x){
    int left=0;
    int right=num-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(x=a[mid]) return mid;
        if(x<a[mid]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}

void BinaryInsertSort(int *&a,int num){
    for(int i=1;i<num;i++){
        int x=a[i];
        int k=BinarySearchForPosition(a,i,x);
        for(int j=i;j>k;j--){
            a[j]=a[j-1];
        }
        a[k]=x;
    }
}

//                                                             BINARY INSERT SORT  

//                                                               SHELL SORT 

void ShellSort(int *&a,int num,int h[],int k){
    int p,j,t,x;
    for(p=0;p<k;p++){
        t=h[p];
        for(int i=t;i<num;i++){
            x=a[i];
            j=i;
            while((x<a[j-t])&&j>=t){
                a[j]=a[j-t];
                j-=t;
            }
            a[j]=x;
        }
    }
}

//                                                               SHELL SORT

//                                                              SELECTION SORT

void SelectionSort(int *&a,int num){
    for(int i=0;i<num-1;i++){
        int k=i;
        for(int j=i+1;j<num;j++){
            if(a[k]>a[j]){ 
                k=j;
                swap(a[k],a[i]);
            }
        }
    }
}

//                                                               SELECTION SORT

//                                                            HEAP SORT

void InsertHeap(int *&a,int left,int right){
    int p;
    p=2*left;
    if(p>right) return;
    if(p<right) 
     if(a[p]<a[p+1]) p++;
    if(a[left]<a[p]){
        swap(a[left],a[p]);
        InsertHeap(a,p,right);
    }
}

void CreateHeap(int *&a,int num){
    for(int k=(num+1)/2;k>=0;k--){
        InsertHeap(a,k,num-1);
    }
}
void HeapSort(int *&a,int num){
    CreateHeap(a,num);
    for(int i=num-1;i>0;i--){
        swap(a[0],a[i]);
        InsertHeap(a,0,i-1);
    }
}

//                                                               HEAP SORT

//                                                           QUICK SORT
// Cách 1:
//
void QuickSort(int *&a,int left,int right){
    int x=a[(left+right)/2];
    int i=left;
    int j=right;
    while(i<j){
        while(a[i]<x)i++;
        while(a[j]>x)j--;
        if(i<=j) swap(a[i++],a[j--]);
    }
    if(left<j) QuickSort(a,left,j);
    if(i<right) QuickSort(a,i+1,right);
}
//
// Cách 2:
/*

void QuickSort(int *&a,int left,int right){
    if(left<right){
        int x=a[left],i=left-1,j=right+1;
        while(i<j){
            while(a[++i]<x);
            while(a[--j]>x);
        }
        QuickSort(a,left,j);
        QuickSort(a,j+1,right);
    }
}

*/
//                                                           QUICK SORT

//                                                           MERGE SORT

void merge(int *&a,int left,int mid,int right){
    int k=left;
    int i=left;
    int j=mid+1;
    int b[MAX];
    while(k<=mid&&j<=right){
        if(a[k]<=a[j]) b[i++]=a[k++];
        else b[i++]=a[j++];
    }
    if(j<=right) for(int h=j;h<=right;h++) b[i++]=a[h];
    if(k<=mid) for(int h=k;h<=mid;h++) b[i++]=a[h];
    for(int s=left;s<=right;s++) a[s]=b[s];
}

void MergeSort(int *&a,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        MergeSort(a,left,mid);
        MergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}

//                                                           MERGER SORT

//                                                         RADIX SORT

int Digit(int num,int k){
    int value=1;
    for(int i=0;i<k;i++){
        value*=10;
    }
    return (num/value)%10;
}

int countDigit(int num){
    int count=0;
    while(num){
        num/=10;
        count++;
    }
    return count;
}

int getMaxDigit(int *a,int num){
    int maxDigit=a[0];
    for(int i=1;i<num;i++){
        if(maxDigit>a[i]) maxDigit=a[i];
    }
    return maxDigit;
}

void returnValue(int *&a,int *b[10],int t[10]){
    int j=0;
    for(int i=0;i<10;i++){
        if(t[i]!=0){
            for(int k=0;k<t[i];k++) a[j++]=b[i][k];
            t[i]=0;
        }
    }
}

void send2Box(int *a,int *b[],int num,int t[10],int k){
    for(int i=0; i<num;i++){
        int temp=Digit(a[i],k);
        b[temp][t[temp]++]=a[i];
    }
}

void RadixSort(int *&a,int num){
    int *Box[10],number[10],i;
    for(int i=0;i<10;i++){
     Box[i]=new int[num];
     if(Box[i]==NULL){
        cout<<"Not enough memory!";
        exit(0);
     }
     number[i]=0;
    }
    int k=countDigit(getMaxDigit(a,num));
    for(int t=0;t<k;t++){
        send2Box(a,Box,num,number,t);
        returnValue(a,Box,number);
    }
    for(int i=0;i<10;i++) delete Box[i];
}

//                                                           RADIX SORT       