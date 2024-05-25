#include<iostream>
#include<iomanip>
using namespace std;

typedef struct{
    char name[50];
    int age;
    char gender[10];
    float score;
    char address[100];
}Student;

void Mysort(Student *a){
    for(int i = 0; i<5; i++){
        for(int j = i+1; j<5; j++){
            if(a[i].score<a[j].score){
                Student temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    cout << fixed << setprecision(2);
    Student students[5] = {
        {"Zhang San", 20, "male", 85, "Beijing"},
        {"Li Si", 22, "male", 92, "Shanghai"},
        {"Wang Wu", 19, "female", 78, "Guangzhou"},
        {"Zhao Liu", 21, "female", 95, "Shenzhen"},
        {"Qian Qi", 20, "male", 88, "Chengdu"}
    };
    cout << "Before sorted:" << endl;
    for(int p = 0; p<5; p++){
        cout << "Name: " << students[p].name << ", " << "Age: " << students[p].age << ", " << "Gender: " << students[p].gender
        << ", " << "Score: " << students[p].score << ", " << "Address: " << students[p].address << endl;
    }
    Mysort(students);
    cout << "After sorted:" << endl;
    for(int p = 0; p<5; p++){
        cout << "Name: " << students[p].name << ", " << "Age: " << students[p].age << ", " << "Gender: " << students[p].gender
        << ", " << "Score: " << students[p].score << ", " << "Address: " << students[p].address << endl;
    }
    return 0;
}