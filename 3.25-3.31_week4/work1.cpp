#include<iostream>
#include<math.h>
using namespace std;

bool getFlag(float a, float b, float c){
    bool flag;
    if( a+b>c && a+c>b && b+c>a ){
        flag = true;
    }else flag = false;
    return flag;
}

bool getArea(float a, float b, float c, float &area){
    bool flag = getFlag(a,b,c);
    if(flag == true){
        float s = ((a+b+c)/2);
        area = sqrt(s*(s-a)*(s-b)*(s-c));
    }
    return flag;
}

bool getLength(float a, float b, float c, float &Length){
    bool flag = getFlag(a,b,c);
    if(flag == true)Length = a + b + c;
    return flag;
}

int main(){
    float a,b,c,area,length;
    cin >> a >> b >> c;
    if(getArea(a,b,c,area) == true){
        cout << "Area of the triangle:" << area << endl;
    }
    if(getLength(a,b,c,length) == true){
        cout << "Length of the triangle:" << length << endl;
    }
    return 0;
}