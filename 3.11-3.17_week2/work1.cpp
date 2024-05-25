#include <iostream>
#include <vector>
#include<sstream>
using namespace std;

int main() {
    int count = 0;
    vector<string> array1;
    vector<string> array2;
    string str, element;
    getline(cin, str);
    istringstream iss1(str);
    while(iss1 >> element){
        array1.push_back(element);
    }
    getline(cin, str);
    istringstream iss2(str);
    while(iss2 >> element){
        array2.push_back(element);
    }
    for (size_t i = 0; i < array1.size(); i++) {
        swap(array1[i], array2[i]);
    }
    cout << "Array1: {";
    for(const auto& str : array1){
        if(count>1){
            break;
        }
        cout << "\"" << str << "\"" << ", ";
        count++;
    }
    cout << "\"" << array1.at(2) << "\"";
    cout << "}" << endl;
    count = 0;
    cout << "Array2: {";
    for(const auto& str : array2){
        if(count>1){
            break;
        }
        cout << "\"" << str << "\"" << ", ";
        count++;
    }
    cout << "\"" << array2.at(2) << "\"";
    cout << "}" << endl;
    return 0;
}