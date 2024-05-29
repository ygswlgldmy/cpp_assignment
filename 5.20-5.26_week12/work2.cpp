#include<iostream>
using namespace std;

class shape{
    public:
        float area;
        float perimeter;
        virtual void display() {
            cout << "面积为：" << area << "，" << "周长为：" << perimeter << endl;
        }
};

class circle : public shape {
    public:
        float radius;
        void display() override {
            cout << "圆半径为：" << radius << "，" << "周长为：" << 2 * 3.14 * radius << "，" << "面积为：" << 3.14 * radius * radius << endl;
        }
        void getradius(){
            cin >> radius;
        }
};

class rectangle : public shape {
    public:
        float width;
        float height;
        void display() override {
            cout << "矩形长为：" << width << "，" << "宽为：" << height << "，" << "周长为：" << 2 * (width + height) << "，" << "面积为：" << width * height << endl;
        }
        void getwh(){
            cin >> width >> height;
        }
};

void show(shape& s){
    s.display();
}

int main(){
    circle c;
    rectangle r;
    cout << "请输入圆的半径：" << endl;
    c.getradius();
    cout << "请输入矩形的长和宽，用空格隔开：" << endl;
    r.getwh();
    show(c);
    show(r);
    return 0;
}