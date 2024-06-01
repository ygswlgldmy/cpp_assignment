#include<iostream>
#include<ctime>
#include<vector>
using namespace std;

class Date {
    public:
        int year, month, day;
        vector<int> systime;
        Date() {
            cout << "Date constructor !" << endl;
        }
        Date(int yy, int mm, int dd) : year(yy), month(mm), day(dd) {
            cout << "Date constructor with parameters !" << endl;
        }
        void getSystemTime(){
            time_t now = time(0);
            tm *lctm = localtime(&now);
            int year = 1900 + lctm->tm_year;
            int month = 1 + lctm->tm_mon;
            int day = lctm->tm_mday;
            systime = {year, month, day};
        }
        virtual ~Date(){
            cout << "Date destructing !" << endl;
        }
};

class BirthDate : public Date{
    public:
        BirthDate() : Date() {
            getSystemTime();
            cout << "BirthDate constructor !" << endl;
        }
        BirthDate(int yy, int mm, int dd) : Date(yy, mm, dd) {
            getSystemTime();
            cout << "BirthDate constructor with parameters !" << endl;
        }
        int calcAge(){
            int age = systime[0] - year;
            if(systime[1] < month || (systime[1] == month && systime[2] < day)){
                age--;
            }
            return age;
        }
        virtual ~BirthDate(){
            cout << "BirthDate destructing !" << endl;
        }
};

class Person{  
    protected:
        string name;
        char gender;
        BirthDate birthDate;
    public:
        Person() : birthDate() {
            cout << "Person constructor !" << endl;
        }
        Person(string n, char g, int yy, int mm, int dd) : name(n), gender(g), birthDate(yy, mm, dd) {
            cout << "Person constructor with parameters !" << endl;
        }
        Person(const Person &p) : name(p.name),gender(p.gender),birthDate() {
            birthDate.year = p.birthDate.year;
            birthDate.month = p.birthDate.month;
            birthDate.day = p.birthDate.day;
            cout << "Person copy constructor !" << endl;
        }
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
        virtual void display(){
            cout << "Name: " << name << endl;
            if(gender == 'M'){
                cout << "Gender: Male" << endl;
            }else {
                cout << "Gender: Female" << endl;
            } 
            cout << "Birth Date: " << birthDate.year << "-" << birthDate.month << "-" << birthDate.day << endl;
            cout << "Age: " << birthDate.calcAge() << endl;
        }
        virtual ~Person(){
            cout << "Person destructing !" << endl;
        }
};

class Student : virtual public Person{
    protected:
        int studentld;
        float score;
    public :
        string course;
        Student() : Person() {
            cout << "Student constructor !" << endl;
        }
        Student(int id, string n, char g, int y, int m, int d, float s) : studentld(id), Person(n, g, y, m, d) , score(s) {
            cout << "Student constructor with parameters !" << endl;
        }
        void display() override {
            cout << "Student ID: " << studentld << endl;
            Person::display();
            cout << "Score: " << score << endl;
        }
        friend istream& operator>>(istream& is, Student &st){
            is >> st.studentld >> st.name >> st.gender >> st.birthDate.year >> st.birthDate.month >> st.birthDate.day >> st.score;
            return is;
        }
        friend ostream& operator<<(ostream& os, Student &st){
            os << "Student ID: " << st.studentld << endl;
            st.Person::display();
            os << "Score: " << st.score << endl;
            return os;
        }
        virtual ~Student(){
            cout << "Student destructing !" << endl;
        }
};

class Staff : virtual public Person{
    protected:
        float staffId;
        float subsidy;
    public:
        Staff() : Person() {
            cout << "Staff constructor !" << endl;
        }
        Staff(float id, string n, char g, int yy, int mm, int dd, float ss) : staffId(id), subsidy(ss), Person(n, g, yy, mm, dd) {
            cout << "Staff constructor with parameters !" << endl;
        }
        void display() override {
            cout << "Staff ID: " << staffId << endl;
            Person::display();
            cout << "Subsidy: " << subsidy << endl;
        }
        virtual ~Staff(){
            cout << "Staff destructing !" << endl;
        }
};

class Teacher : public Staff{
    protected:
        string password;
        string course;
    public:
        Teacher() : Staff() {
            cout << "Teacher constructor !" << endl;
        }
        Teacher(float id, string n, char g, int yy, int mm, int dd, float ss, string c, string p) : Staff(id, n, g, yy, mm, dd, ss), course(c), password(p), Person(n, g, yy, mm, dd) {
            cout << "Teacher constructor with parameters !" << endl;
        }
        bool checkPassword(string pass){
            return pass==password ? true:false;
        }
        string getPassword(){
            return password;
        }
        virtual ~Teacher(){
            cout << "Teacher destructing !" << endl;
        }
    friend istream& operator>>(istream& is, Teacher &te){
        is >> te.staffId >> te.name >> te.gender >> te.birthDate.year >> te.birthDate.month >> te.birthDate.day >> te.subsidy >> te.course;
        return is;
    }
    friend ostream& operator<<(ostream& os,Teacher &te){
        os << "Student ID: " << te.staffId << endl;
        te.Person::display();
        os << "Subsidy: " << te.subsidy << endl;
        os << "Course: " << te.course << endl;
        os << "Password: " << te.password << endl;
        return os;
    }
};

class Tutor : public Student, public Teacher{
    public:
        Tutor() : Student(), Teacher() {
            cout << "Tutor constructor !" << endl;
        }
        Tutor(int id, string name, char g, int y, int m, int d, float sc, float ss, string c, string p) : Student(id, name, g, y, m, d, sc),Teacher(id, name, g, y, m, d, ss, c, p), Person(name, g, y, m, d) {
            cout << "Tutor constructor with parameters !" << endl;
        }
        void display() override {
            Student::display();
            cout << "Subsidy: " << subsidy << endl;
            cout << "Course: " << Teacher::course << endl;
            cout << "Password: " << getPassword() << endl;
        }
        virtual ~Tutor(){
            cout << "Tutor destructing !" << endl;
        }
        friend istream& operator>>(istream& is, Tutor &tu){
            is >> tu.studentld >> tu.name >> tu.gender >> tu.birthDate.year >> tu.birthDate.month >> tu.birthDate.day >> tu.score >> tu.subsidy >> tu.Teacher::course >> tu.password;
            return is;
        }
        friend ostream& operator<<(ostream& os, Tutor &tu){
            tu.display();
            return os;
        }
};

int main() {

    string name;
    int id,y,m,d;
    char g;
    float sc; //score
    float ss; //subsidy
    string c; //course
    string p; //password

    cin >> id >> name >> g >> y >> m >> d >> sc >> ss >> c >> p;
    Tutor* tutor = new Tutor(id,name,g,y,m,d,sc,ss,c,p);
    tutor->display();
    
    Tutor* ttr = new Tutor(); 
    cin >> *ttr;
    cout << *ttr;

    Person person = *tutor;
    person.display();

    Staff* tt = tutor;
    tt->display();
    delete tt;
    
    Student& stt = *ttr;
    stt.display();
    delete &stt;

    return 0;
}