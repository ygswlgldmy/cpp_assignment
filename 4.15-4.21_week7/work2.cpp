#include <iostream>
using namespace std;

class Date {
private:
    int y, m, d;

public:
    Date(int year = 2024, int month = 4, int day = 26) : y(year), m(month), d(day) {
        cout << "���ù��캯��" << endl;
        cout << endl;
    }

    Date(const Date& other) : y(other.y), m(other.m), d(other.d) {
        cout << "����Copy���캯��" << endl;
        cout << endl;
    }

    ~Date() {
        cout << "������������" << endl;
        cout << endl;
    }

    void Prt() {
        cout << "2024��4��26��ǰ�����ҵ" << endl;
        cout << endl; 
    }
};

int main() {
    Date d1;
    Date d2(d1);
    Date d3 = d1;

    d1.Prt();
    d2.Prt();
    d3.Prt();

    return 0;
}