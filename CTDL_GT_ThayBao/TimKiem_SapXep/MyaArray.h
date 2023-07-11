struct MyArray{
    int *a;
    int num;
};
// Khai báo prototype
void initArray(MyArray &);
MyArray readArrayFromFile(char*);
int writeArrayToFile(MyArray,char*);
void displayArray(MyArray);
void deleteArray(MyArray&);
MyArray coppyArray(MyArray);
MyArray coppyArray(MyArray,int,int);
