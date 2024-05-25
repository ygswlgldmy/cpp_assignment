#include<iostream>
using namespace std;

int main(){
    string str;
    getline(cin, str);
    for(size_t p = 0; p<str.size(); p++){
        if(str.at(p) >= 'a' && str.at(p) <= 'z'){
            str.at(p) -= 32;
        }
    }
    cout << str << endl;
    return 0;
}