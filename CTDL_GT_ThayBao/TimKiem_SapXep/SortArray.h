#include"MyArray.h"

/* Các hàm sắp xếp mảng dùng 11 thuật toán sắp xếp trong lý thuyết
1. Interchange Sort
2. Bubble Sort
3. Shaker Sort
4. Insert Sort
5. Binary Insert Sort
6. Shell Sort
7. Select Sort
8. Heap Sort
9. Quick Sort
10. Merge Sort
11. Radix Sort
*/
//Nhóm 1. Các thuật toán dựa trên ý tưởng làm giảm số nghịch thế trong mảng
void interchangeSort(MyArray);
void bubbleSort(MyArray); // cải tiến của Bubble Sort để giảm bớt số lần lặp lại khi dữ liệu đã được sắp xếp cục bộ
void shakerSort(MyArray);

//Nhóm 2. Các thuật toán dựa trên ý tưởng xây dựng mảng mới có thứ tự từ mảng ban đầu
void insertSort(MyArray);
void binarySort(MyArray);  // cải tiến bằng cách áp dụng hàm tìm kiếm nhị phân
void shellSort(MyArray); // cải tiến bằng cách giảm bớt số nghịch thế trước khi thực sự sắp xếp
void selectSort(MyArray); 
void heaptSort(MyArray); // cải tiến của Select Sort, thông tin các lần tìm kiếm trước được lưu trữ lại // để áp dụng cho các lần tiếp theo

// Nhóm 3. Các thuật toán dựa trên ý tưởng "chia để trị" để sắp xếp mảng
void qSort(MyArray);
void QuickSort(MyArray,int,int);
void mSort(MyArray);
void MergeSort(MyArray,int,int);

// Nhóm 4. Dựa trên nguyên tắc chính là phân loại và trình tự phân loại
void radixSort(MyArray);