#include <iostream>
#include <string>
using namespace std;

class Score {
public:
    Score(double math, double cLanguage, double english)
        : mathScore(math), cLanguageScore(cLanguage), englishScore(english) {}

    double getMathScore() const { return mathScore; }
    double getCLanguageScore() const { return cLanguageScore; }
    double getEnglishScore() const { return englishScore; }

private:
    double mathScore;
    double cLanguageScore;
    double englishScore;
};

class Student {
public:
    Student(const string& name, const string& studentID, const Score& score)
        : studentName(name), studentID(studentID), studentScore(score) {}

    string getName() const { return studentName; }
    string getStudentID() const { return studentID; }
    Score getScore() const { return studentScore; }

private:
    string studentName;
    string studentID;
    Score studentScore;
};

int main() {
    Score score1(98.3, 98.6, 99.1);
    Score score2(98.8, 98.5, 99.5);

    Student student1("胡永", "2022011", score1);
    Student student2("李力", "2022015", score2);

    cout << "学生姓名：" << student1.getName() << "  学号：" << student1.getStudentID() << endl;
    cout << "数学：" << student1.getScore().getMathScore();
    cout << ",C语言：" << student1.getScore().getCLanguageScore();
    cout << "英语:" << student1.getScore().getEnglishScore() << endl;

    cout << endl;

    cout << "学生姓名：" << student2.getName() << "  学号：" << student2.getStudentID() << endl;
    cout << "数学：" << student2.getScore().getMathScore();
    cout << ",C语言：" << student2.getScore().getCLanguageScore();
    cout << "英语:" << student2.getScore().getEnglishScore() << endl;

    return 0;
}