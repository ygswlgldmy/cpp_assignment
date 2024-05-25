#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "Person�޲ι��캯���ĵ���" << endl; }
    
    Person(string name) : p_Name(name) {
        cout << "Person�ĺ��ι��캯���ĵ���" << endl;
    }
    
    ~Person() {
        cout << "������������." << endl;
    }

    Person(string name, int age, string sex) : p_Name(name), p_Age(age), p_Sex(sex) {
        cout << "Person��ȫ�ι��캯���ĵ���" << endl;
    }
    
    Person(const Person& p) {
        p_Name = p.p_Name;
        p_Age = p.p_Age;
        p_Sex = p.p_Sex;
        cout << "Person�Ŀ������캯���ĵ���" << endl;
    }
    
    void prt() {
        cout << "������" << p_Name << ",���䣺" << p_Age << "���Ա�" << p_Sex << endl;
    }

private:
    string p_Name;
    int p_Age;
    string p_Sex;
};

int main() {
    Person p10;
    Person p11("����");
    Person p12("����", 18, "Ů");
    Person p13(p12);
    p12.prt();
    p13.prt();
}
