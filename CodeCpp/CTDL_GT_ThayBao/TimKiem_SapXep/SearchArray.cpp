#include"SearchArray.h"

//Hàm tìm kiếm tuần tự, sinh viên tự cài đặt theo hướng dẫn trong lý thuyết
int LSearch(int *a,int n,int x){
    for(int i=0;i<n;i++){
        if(a[i] /* Thỏa điều kiện nào đó */) return i;
    }
    return -1;
}

// Hàm tìm kiếm nhị phân, sinh viên tự cài đặt theo hướng dẫn trong lý thuyết
int BSearch(int *a,int n,int x){
    int left=0;
    int right=n-1;
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