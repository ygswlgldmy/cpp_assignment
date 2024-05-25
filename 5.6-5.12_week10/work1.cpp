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
    cout << "两个整数相加结果: " << add(x, y) << endl;
    cout << "两个浮点数相加结果: " << add(a, b) << endl;
    cout << "两个字符串连接结果: " << add(s1, s2) << endl;
    return 0;
}