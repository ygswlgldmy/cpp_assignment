#include<iostream>
#include<string>
using namespace std;

class adder{
    public:
        int operator()(int x, int y){
            return x + y;
        }

        float operator()(float x, float y){
            return x + y;
        }

        string operator()(string x, string y){
            return x + y;
        }
};

int main(){
    adder add;
    int x,y;
    float a,b;
    string s1,s2;
    char n;
    cin >> x >> n >> y;
    cin >> a >> n >> b;
    cin.ignore();
    getline(cin, s1, ',');
    getline(cin, s2);
    cout << "����������ӽ��: " << add(x, y) << endl;
    cout << "������������ӽ��: " << add(a, b) << endl;
    cout << "�����ַ������ӽ��: " << add(s1, s2) << endl;
    return 0;
}