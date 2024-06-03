#include<iostream>
#include <string>
#include <sstream>
using namespace std;

template <typename T>
void myswap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void myswap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

bool Toint(const std::string& str, int& result) {
    std::istringstream iss(str);
    return iss >> result && iss.eof();
}

int main() {
    string a, b;
    int x, y;
    cin >> a >> b;
    if(Toint(a, x) && Toint(b, y)){
        cout << "Before swap (x, y): " << x << ", " << y << endl;
        myswap(x, y);
        cout << "After swap (x, y): " << x << ", " << y << endl;
    } else {
        cout << "Before swap (s1, s2): " << a << ", " << b << endl;
        myswap(a, b);
        cout << "After swap (s1, s2): " << a << ", " << b << endl;
    }
    return 0;
}
