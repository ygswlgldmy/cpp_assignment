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
			cout << "ѧ�� [id=" << id << ", name=" << name << ", birthday=" << bir << ", major=" << major << ", score=" << score << "]" << endl;
		}
};

class Teacher : public Person {
	public:
		string title;
		double salary;
		void display() override{
			cout << "��ʦ [id=" << id << ", name=" << name << ", birthday=" << bir << ", title=" << title << ", salary=" << salary << "]" << endl;
		}
};

int main(){
	int n,type;
	cout<<"¼���ʦ��ѧ����Ϣ����ʾ"<<endl;
	cout<<"¼�������"<<endl;
	cin >> n;

 	for(int i=0;i<n;i++){	
        cout<<"����ѧ����Ϣ����0����ʦ����1"<<endl;
        cin>>type;
		if(type == 0){
			cout << "����ѧ����ѧ��(����)��������������ݡ�רҵ����ѧ�ɼ����ÿո����" << endl;
			Student* stu = new Student();
			cin >> stu->id >> stu->name >> stu->bir >> stu->major >> stu->score;
			stu->display();
			delete stu;
		}else if(type == 1){
			cout << "�����ʦ�Ĺ���(����)��������������ݡ�ְ�ƺ͹��ʣ��ÿո����" << endl;
			Teacher* tea = new Teacher();
			cin >> tea->id >> tea->name >> tea->bir >> tea->title >> tea->salary;
			tea->display();
			delete tea;
		}
	}
	return 0;
}