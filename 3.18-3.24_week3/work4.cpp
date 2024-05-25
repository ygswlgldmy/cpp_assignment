#include<iostream>
#include<string>
using namespace std;

typedef struct{
    long int student_number;
    string name;
    string gender;
    int age;
}Student;

int main(){
    Student student[3] = {{2022101,"张三","男",19}, {2022102,"李四","女",18},  {2022103,"王五","女",19}};
    Student *p = student;
    cout << "通过指针访问结构体数组成员：" << endl;
    for(size_t i = 0; i<sizeof(student)/sizeof(student[0]); i++){
        cout << "学号: " << p->student_number << ", " 
        << "姓名: " << p->name << ", "
        << "性别: " << p->gender << ", " 
        << "年龄: " << p->age <<endl;
        p++;
    }
    return 0;
}