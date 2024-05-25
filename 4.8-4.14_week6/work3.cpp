#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    Student() {
        id = 20220101;
        name = "张三峰";
        sex = "男";
        age = 19;
        specialty = "电子与计算机";
    }

    void printInfo() {
        cout << "学号：" << id << " ";
        cout << "姓名：" << name << " ";
        cout << "性别：" << sex << " ";
        cout << "年龄：" << age << " ";
        cout << "专业：" << specialty << endl;
    }

private:
    int id;
    string name;
    string sex;
    int age;
    string specialty;
};

int main() {
    Student student;
    student.printInfo();
    return 0;
}