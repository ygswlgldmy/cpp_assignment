#include<iostream>
#include <cmath>
using  namespace std;

template <typename T>
class Point {
    public:
        T x, y, z;
        Point(T x, T y, T z): x(x), y(y), z(z) {}
        virtual void Point_coordinates() {
            cout << "Point coordinates: (" << x << ", " << y << ", " << z << ")" << endl;
        }
        virtual ~Point() {}
};

template <typename T>
class Sphere : public Point<T> {
    public:
        T r;
        Sphere(T x, T y, T z, T r): Point<T>(x ,y, z), r(r) {}
        void Point_coordinates() override {
            cout << "Sphere center coordinates: (" << this->x << ", " << this->y << ", " << this->z << ")" << endl;
            cout << "Sphere radius: " << r << endl;
            cout << "Sphere volume: " << 4.0/3.0*M_PI*r*r*r << endl;
            cout << "Sphere surface area: " << 4.0*M_PI*r*r << endl;
        }
};

int main(){
    int x1,y1,z1;
    double x2,y2,z2,r;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2 >> r;
    Point<int>* p1 = new Point<int>(x1, y1, z1);
    p1->Point_coordinates();
    delete p1;
    Sphere<double>* p2 = new Sphere<double>(x2, y2, z2, r);
    p2->Point_coordinates();
    delete p2;
    return 0;
}