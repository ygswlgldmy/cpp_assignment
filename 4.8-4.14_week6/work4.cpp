#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;
    double height;

public:
    Rectangle(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    double getSurfaceArea() {
        return 2 * (length*width + length*height + width*height);
    }

    double getVolume() {
        return length*width*height;
    }
};

int main() {
    double length = 12.5;
    double width = 25.2;
    double height = 32.8;

    Rectangle rectangle(length, width, height);

    cout << "矩形体的表面积：" << rectangle.getSurfaceArea() << endl;
    cout << "矩形体的体积：" << rectangle.getVolume() << endl;

    return 0;
}