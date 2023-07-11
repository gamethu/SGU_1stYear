#include <stdio.h>
#include <string.h>

int main() {
    int n = 5; // số lượng file
    char filename[50]; // chuỗi tên file
    char content[100]; //nội dung file
    FILE *fp; //con trỏ tập tin

    for (int i = 1; i <= n; i++) {
        sprintf(filename, "filename%d.txt", i); //tạo tên file dựa trên số thứ tự i
        fp = fopen(filename, "w"); //mở file để ghi
        sprintf(content, "This is file %d", i); //tạo nội dung file
        fputs(content, fp); //ghi nội dung vào file
        fclose(fp); // đóng file
    }

    return 0;
}