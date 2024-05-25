#include<iostream>
#include <cmath>
using namespace std;

class Point{
    public:
        float x, y;
        Point(float x , float y) : x(x), y(y) {
            cout << "Բ��Ϊ��x="<< x << ",  "<< "y=" << y << endl;
        }
};

class Circle{
    public:
        float x, y, x1, y1;
        Circle(float x, float y, float x1, float y1) : x(x), y(y), x1(x1), y1(y1){
            output(getR(x, y, x1, y1), getArea(getR(x, y, x1, y1)));
        }
        float getR(float x, float y, float x1, float y1){
            return sqrt((x-x1)*(x-x1) + (y-y1)*(y-y1));
        }
        float getArea(float r){
            return 3.14 * r * r;
        }
        void output(float r, float area){
            cout << "�뾶Ϊ" << r << ", Բ���Ϊ��" << area << endl;
        }
};

int main(){
    float x, y, x1, y1;
    cout << "������Բ������(x,y)��Բ����һ��(x1,y1)" << endl;
    cin >> x >> y >> x1 >> y1;
    Point p1(x, y);
    Circle c1(x, y, x1, y1);
    return 0;
}