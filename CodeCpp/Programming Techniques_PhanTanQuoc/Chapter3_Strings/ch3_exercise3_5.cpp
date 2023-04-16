#include<iostream>
#include<cstring>
using namespace std;
void findLongestWord_Kword(char s[]){
    // tìm từ dài nhất
    strcat(s," ");
    int LongestWord=0,numWord=0,countChar=0;
    for(int i=0;i<strlen(s);i++){
        if(!isspace(s[i]))countChar++;
        else{
            numWord++;
            if(countChar>LongestWord){
                LongestWord=countChar;
                countChar=0;
            }
        }
    }
    // tìm số lượng xuất hiện của từ
    int times=0;
    countChar=0;
    int vitri=1;
    int max=0;
    for(int i=1;i<=numWord;i++){
        for(int j=0;j<strlen(s)-1;j++){
            if(!isspace(s[j]))countChar++;
            else{
                if(countChar==i){
                    times++;
                    countChar=0;
                }
            }
        }
        cout<<"Tu loai "<<i<<" xuat hien : "<<times<<endl;
        if(times>max){
            max=times;
            vitri=i;
        }
        times=0;
        countChar=0;
    }
    cout<<"Tu loai "<<vitri<<" xuat hien nhieu nhat voi so lan la : "<<max<<endl;
}
int main(){
    char s[256];
    cout<<"Nhap chuoi : ";
    fflush(stdin);gets(s);
    findLongestWord_Kword(s);
    return 0;
}