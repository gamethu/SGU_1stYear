#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ctime>
#include<conio.h>
#include<string.h>
#include<math.h>
#define num 100000 // số phần tử tối đa có trong file
using namespace std;
int main(){  
    int FileNumber=1;
    while(FileNumber<=100){ // tạo tối đa 100 file
    // khai báo chuỗi kí tự "filename chỉ có 1 phần tử" vì "trong mỗi vòng lặp chỉ có tối đa 1 phần tử có tên là filename được sử dụng để gán làm file"
    char filename[1];
    sprintf(filename, "filename%d.txt",FileNumber); //tạo tên file dựa trên số thứ tự FileNumber
    FILE *fp;
    fp=fopen(filename,"wt"); // gán tên file đã tạo ở trên vào file mới để ghi dữ liệu
    if(!fp){
        cout<<"Cant open this file";
        exit(0);
    }
    int *a;
    a=new int[num]; // khai báo num khối nhớ kiểu int cho con trỏ a
    if(!a){
        cout<<"Not enough memory!";
        exit(0);
    }
    //
    fprintf(fp,"%d",num); // ghi vào file dòng đầu tiên là số lượng phần tử có trong mảng
    fprintf(fp,"\n");
    //
    for(int i=1;i<=num;i++){
        int x=rand()-rand();
        if(x==0){
            i--;
            break;
        }
        fprintf(fp," %d",x);
        int k=sqrt(num);
        if(i%k==0)fprintf(fp,"\n"); // cứ 10 phần tử liên tiếp thì xuống 1 dòng
    }
    FileNumber++;
    if(FileNumber>100)delete []a;// xóa bộ nhớ cấp phát khi đã đủ 100 file
    }
    cout<<"Finished!";  
    return 0;
}
