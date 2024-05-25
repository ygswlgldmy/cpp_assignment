#include <iostream>
using namespace std;

class Complex {
public:
    double a, b;
    Complex operator--() {
        --a;
        return *this;
    }
    Complex operator--(int) {
        Complex temp(*this);
        a--;
        return temp;
    }
    Complex operator-(const Complex& c) {
        Complex result;
        result.a = a - c.a;
        result.b = b - c.b;
        return result;
    }
};

ostream& operator<<(ostream& os, const Complex& c) {
    os << "(" << c.a << "," << c.b << ")";
    return os;
}
istream& operator>>(istream& is, Complex& c) {
    char temp;
    is >> c.a >> temp >> c.b;
    return is;
}

int main() {
    Complex a, b;
    char n;
    cin >> a >> n >> b;
    cout << a-b << endl;
    return 0;
}