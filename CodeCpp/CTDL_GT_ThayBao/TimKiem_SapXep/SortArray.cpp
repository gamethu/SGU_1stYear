#include"SortArray.h"

void swap(int &a,int &b){
    int temp=a;
        a=b;
        b=temp;
}

void InterchangeSort(int *&a,int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j]) swap(i,j); // Hoán vị hai phần tử ở vị trí i j
    }
}

void BubbleSort(int *&a, int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(a[j-1]>a[j]) swap(a[j-1],a[j]);
        }
    }
}

// hv = hoan vi
int ShakerSort(int *&a,int n){
    int up=0,down=n-1,hv=0;
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

void InsertSort(int *&a,int n){
    for(int i=1;i<n;i++){
        int x=a[i],j=i-1;
        while(x<a[j]&&j>=0){
            swap(a[j+1],a[j]); // a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

void BinaryInsertSort(int *&a,int n){
    for(int i=1;i<n;i++){
        x=a[i];
        k=BSearch(ad,i,x);
        for(int j=i;j>k;j--){
            a[j]=a[j-1];
        }
        a[k]=x;
    }
}

void ShellSort(int *&a,int n,int h[],int k){
    int p,j,t,x;
    for(p=0;p<k;p++){
        t=h[p];
        for(int i=t;i<n;i++){
            x=aa[i];
            j=i;
            while((x<a[j-t])&&j>=t){
                ad.a[j]=ad.a[j-step.a[k]];
                j-=t;
            }
            a[j]=x;
        }
    }
}

void SelectionSort(int *&a,int n){
    for(int i=0;i<n-1;i++){
        int k=i;
        for(int j=i+1;j<n;j++){
            if(a[k]>a[j]){ 
                k=j;
                swap(a[k],a[i]);
            }
        }
    }
}

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

void CreateHeap(int *&a,int n){
    for(int k=(n+1)/2;k>=0;k--){
        InsertHeap(a,k,n-1);
    }
}
void HeapSort(int *&a,int n){
    CreateHeap(a,n);
    for(int i=n-1;i>0;i--){
        swap(a[0],a[i]);
        InsertHeap(a,0,i-1);
    }
}

// Cách 1:
void QuickSort(int *&a,int left,int right){
    int x=a[(left+right)/2];
    int i=left;
    int j=right;
    while(i<j){
        while(a[i]<x)i++;
        while(a[j]>x)j--;
        if(i<j) swap(a[i],a[j]);
    }
    if(left<j) QuickSort(a,left,j);
    if(i<right) QuickSort(a,i+1,right);
}

// Cách 2:
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

int Digit(int n,int k){
    int value=1;
    for(int i=0;i<k;i++){
        value*=10;
    }
    return (n/value)%10;
}

int countDigit(int n){
    int count=0;
    while(n){
        n/=10;
        count++;
    }
    return count;
}

int getMaxDigit(int *a,int n){
    int maxDigit=a[0];
    for(int i=1;i<n;i++){
        if(maxDigit>a[i]) maxDigit=a[i];
    }
    return maxDigit;
}

void returnValue(int *&a,int *b[10];int t[10]){
    int j=0;
    for(int i=0;i<100;i++){
        if(t[i]!=0){
            for(int k=0;k<t[i];k++) a[j++]=b[i][k];
            t[i]=0;
        }
    }
}

void send2Box(int *a,int *b[],int n,int t[10],int k){
    for(int i=0;i<n;i++){
        int temp=Digit(a[i],k);
        b[temp][t[temp]++]=a[i];
    }
}

void RadixSort(int *&a,int n){
    int *Box[10],number[10],i;
    for(int i=0;i<10;i++){
        Box[i]=new int[n];
    }
    if(Box[i]==NULL){
        cout<<"Not enough memory!";
        exit(0);
    }
    number[i]=0;
    int k=countDigit(getMaxDigit(a,n));
    for(int t=0;t<k;t++){
        send2Box(a,Box,n,number,t);
        returnValue(a,Box,number);
    }
    for(int i=0;i<10;i++) delete Box[i];
}
