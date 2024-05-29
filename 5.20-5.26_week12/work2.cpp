#include<iostream>
using namespace std;

class shape{
    public:
        float area;
        float perimeter;
        virtual void display() {
            cout << "���Ϊ��" << area << "��" << "�ܳ�Ϊ��" << perimeter << endl;
        }
};

class circle : public shape {
    public:
        float radius;
        void display() override {
            cout << "Բ�뾶Ϊ��" << radius << "��" << "�ܳ�Ϊ��" << 2 * 3.14 * radius << "��" << "���Ϊ��" << 3.14 * radius * radius << endl;
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
            cout << "���γ�Ϊ��" << width << "��" << "��Ϊ��" << height << "��" << "�ܳ�Ϊ��" << 2 * (width + height) << "��" << "���Ϊ��" << width * height << endl;
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
    cout << "������Բ�İ뾶��" << endl;
    c.getradius();
    cout << "��������εĳ��Ϳ��ÿո������" << endl;
    r.getwh();
    show(c);
    show(r);
    return 0;
}