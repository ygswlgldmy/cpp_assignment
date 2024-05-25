#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

class Date {
    public:
        int year, month, day;
        vector<int> systime;
        Date():year(0), month(0), day(0) {}
        void getSystemTime(){
            time_t now = time(0);
            tm *lctm = localtime(&now);
            year = 1900 + lctm->tm_year;
            month = 1 + lctm->tm_mon;
            day = lctm->tm_mday;
            systime = {year, month, day};
        }
};

class BirthDate : public Date{
    public:
        BirthDate(){
            getSystemTime();
        }
        BirthDate(int y, int m, int d){
            year = y;
            month = m;
            day = d;
            getSystemTime();
        }
        int calcAge(){
            int age = systime[0] - year;
            if(systime[1] < month || (systime[1] == month && systime[2] < day)){
                age--;
            }
            return age;
        }
};

class Person{  
    protected:
        string name;
        char gender;
        BirthDate birthDate;
    public:
        Person(){}
        int getAge(){
            return birthDate.calcAge();
        }
        friend istream &operator>>(istream &is, Person &person){
            is >> person.name >> person.gender >> person.birthDate.year >> person.birthDate.month >> person.birthDate.day;
            return is;
        }
        friend ostream &operator<<(ostream& os,Person &person){
            os << "Name: " << person.name << endl;
            if(person.gender == 'M'){
                cout << "Gender: Male" << endl;
            }else {
                cout << "Gender: Female" << endl;
            } 
            os << "Birth Date: " << person.birthDate.year << "-" << person.birthDate.month << "-" << person.birthDate.day << endl
               << "Age: " << person.getAge() << endl;
            return os;
        }
};

class Student : public Person{
    protected:
        int studentld;
        float score;
    public :
        Student(){}
        Student(int id, string n, char g, int y, int m, int d, float s) : studentld(id), score(s) {
            name = n;
            gender = g;
            birthDate.year = y;
            birthDate.month = m;
            birthDate.day = d;
        }
        void display(){
            cout << "Student ID: " << studentld << endl;
            cout << "Name: " << name << endl;
            if(gender == 'M'){
                cout << "Gender: Male" << endl;
            }else {
                cout << "Gender: Female" << endl;
            } 
            cout << "Birth Date: " << birthDate.year << "-" << birthDate.month << "-" << birthDate.day << endl;
            cout << "Age: " << birthDate.calcAge() << endl;
            cout << "Score: " << score << endl;
        }
        friend istream& operator>>(istream& is, Student &st){
            is >> st.studentld >> st.name >> st.gender >> st.birthDate.year >> st.birthDate.month >> st.birthDate.day >> st.score;
            return is;
        }
        friend ostream& operator<<(ostream& os, Student &st){
            os << "Student ID: " << st.studentld << endl;
            os << "Name: " << st.name << endl;
            if(st.gender == 'M'){
                cout << "Gender: Male" << endl;
            }else {
                cout << "Gender: Female" << endl;
            } 
            os << "Birth Date: " << st.birthDate.year << "-" << st.birthDate.month << "-" << st.birthDate.day << endl;
            os << "Age: " << st.birthDate.calcAge() << endl;
            os << "Score: " << st.score << endl;
            return os;
        }
};

int main() {
    string name;
    int id,y,m,d;
    char g;
    float s;

    cin >> id >> name >> g >> y >> m >> d >> s;

    Student student(id,name,g,y,m,d,s);
    student.display();

    Student stu;
    cin >> stu;
    cout << stu;

    return 0;
}