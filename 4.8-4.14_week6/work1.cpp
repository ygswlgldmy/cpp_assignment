#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    double calculateArea() {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
};

int main() {
    double side1, side2, side3;
    cout << "�����������ε�����: " << endl;
    cin >> side1 >> side2 >> side3;

    Triangle triangle(side1, side2, side3);

    if ((side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2)) {
        double area = triangle.calculateArea();
        cout << "������������ܹ��������Σ��������: " << area << endl;
    } else {
        cout << "����������߲��ܹ��������Ρ�" << endl;
    }

    return 0;
}