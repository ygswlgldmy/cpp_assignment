#include<iostream>
using namespace std;

void month_show(int n){
   const char* c[] = {"January", "February", "March", "April", "May", "June", "July", "Aguest", "September", "October", "November", "December"};
    if(n <= 0 || n >= 13){
        cout << "intput error" << endl;
    }else{
        cout << c[n-1] << endl;
    }
}

int main(){
    int n;
    char c;
    while(1){
        cout << "请输入月份？" << endl;
        cin >> n;
        month_show(n);
        cout << "继续输入吗（Y/N)?" << endl;
        cin >> c;
        if (c == 'N')
        {
            break;
        }
    }
    return 0;
}