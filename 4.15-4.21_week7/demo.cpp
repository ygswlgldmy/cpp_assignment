#include <iostream>
using namespace std;

class Person {
public:
    Person() { cout << "Person无参构造函数的调用" << endl; }
    
    Person(string name) : p_Name(name) {
        cout << "Person的含参构造函数的调用" << endl;
    }
    
    ~Person() {
        cout << "调用析构函数." << endl;
    }

    Person(string name, int age, string sex) : p_Name(name), p_Age(age), p_Sex(sex) {
        cout << "Person的全参构造函数的调用" << endl;
    }
    
    Person(const Person& p) {
        p_Name = p.p_Name;
        p_Age = p.p_Age;
        p_Sex = p.p_Sex;
        cout << "Person的拷贝构造函数的调用" << endl;
    }
    
    void prt() {
        cout << "姓名：" << p_Name << ",年龄：" << p_Age << "，性别：" << p_Sex << endl;
    }

private:
    string p_Name;
    int p_Age;
    string p_Sex;
};

int main() {
    Person p10;
    Person p11("黎明");
    Person p12("张钰", 18, "女");
    Person p13(p12);
    p12.prt();
    p13.prt();
}
