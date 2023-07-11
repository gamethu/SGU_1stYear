#include"MyArray.h"
//Hàm initArray dùng để khởi tạo ban đầu 
void initArray(MyArray &ma){
    ma.a= ;
    ma.num= ;
}

// Hàm readArrayFromFile dùng để đọc một mảng từ một tập tin văn bản // có tên là chuỗi filename
// tập tin này dạng có hai dòng
// dòng đầu tiên mô tả số lượng phần tử mảng
// dòng thứ hai mô tả các phần tử của mảng
MyArray readArrayFromFile(char*fileName){
    FILE*fp;
    MyArray temp;
    int buf;
    initArray(temp);
    fopen_s(&fp,fileName,"rt"); // Mở tập tin để đọc
    if(!fp){
        printf("Cannot open file..."); // Lỗi không thể mở tập tin
        return temp;
    }
    fscanf_s(fp,"%d",&temp.num); //Đọc số phần tử của mảng.
// Bạn phải kiểm tra tính hợp lệ của số phần tử
// Tạo mảng tạm để đọc dữ liệu
// Kiểm tra có đủ bộ nhớ để tạo được mảng tạm hay không
    // Đọc từng phần tử vào mảng tạm đã tạo
    for(int i=0;i<temp.num;i++){
      ...
    }
    fclose(fp); // Đóng tập tin
    return temp; // Trả kết quả ra
}
// Hàm writeArrayToFile dùng để ghi một mảng ra một tập tin văn bản có tên là chuỗi fileName
int writeArrayToFile(MyArray as,char*fileName){
    FILE*fp;
    fopen_s(&fp,fileName,"wt"); // Mở tập tin để ghi
    // Kiểm tra có mở tập tin để ghi được hay không
    // Ghi số phần tử của mảng vào tập tin
    // Ghi từng phần tử của mảng vào tập tin
    fclose(fp);
    return 0;
}

// Hàm displayArray dùng để xuất mảng ra màn hình
void displayArray(MyArray ma){
    
}

// Hàm deleteArray dùng để xóa mảng khỏi bộ nhớ
void deleteArray(MyArray &ma){
    
}

// Hàm coppyArray dùng để sao chép mảng ban đầu, kết quả trả về là một // mảng mới
MyArray coppyArray(MyArray as){
    // Tạo một struct MyArray để sao chép
    // Sao chép từng phần tử của mảng
    // Trả mảng kết quả về   
}

// Hàm coppyArray(MyArray as,int left,int right) dùng để sao chép mảng
// ban đầu từ phần tử ở vị trí left đến phần tử ở vị trí right
MyArray coppyArray(MyArray as,int left,int right){
    
}