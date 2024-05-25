#include<iostream>
#include<algorithm>
using namespace std;

void Mysort(){
    const char *s[] = {"China","America","Japan","France","Germany","Canada"};
    int count = sizeof(s) / sizeof(s[0]);
    cout << "排序前：" << endl;
    for(int i = 0; i < count-1; i++){
        cout << s[i] << "   ";
    }
    cout << s[count-1] << endl;
    sort(s, s+count, less<string>());
    cout << "排序后：" << endl;
    for(int i = 0; i < count-1; i++){
        cout << s[i] << "   ";
    }
    cout << s[count-1] << endl;
}

int main(){
    Mysort();
    return 0;
}