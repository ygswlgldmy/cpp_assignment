#include<iostream>
using namespace std;

class Person {
	public:
		int id;
		string name;
		int bir;
		virtual void display() = 0;
		virtual ~Person() {}
};

class Student : public Person {
	public:
		string major;
		double score;
		void display() override{
			cout << "学生 [id=" << id << ", name=" << name << ", birthday=" << bir << ", major=" << major << ", score=" << score << "]" << endl;
		}
};

class Teacher : public Person {
	public:
		string title;
		double salary;
		void display() override{
			cout << "教师 [id=" << id << ", name=" << name << ", birthday=" << bir << ", title=" << title << ", salary=" << salary << "]" << endl;
		}
};

int main(){
	int n,type;
	cout<<"录入教师和学生信息并显示"<<endl;
	cout<<"录入的人数"<<endl;
	cin >> n;

 	for(int i=0;i<n;i++){	
        cout<<"输入学生信息输入0，教师输入1"<<endl;
        cin>>type;
		if(type == 0){
			cout << "输入学生的学号(数字)、姓名、出生年份、专业和入学成绩，用空格隔开" << endl;
			Student* stu = new Student();
			cin >> stu->id >> stu->name >> stu->bir >> stu->major >> stu->score;
			stu->display();
			delete stu;
		}else if(type == 1){
			cout << "输入教师的工号(数字)、姓名、出生年份、职称和工资，用空格隔开" << endl;
			Teacher* tea = new Teacher();
			cin >> tea->id >> tea->name >> tea->bir >> tea->title >> tea->salary;
			tea->display();
			delete tea;
		}
	}
	return 0;
}