#include<stdlib.h>
#include<iostream>
using namespace std;

void fibonacci(int n){
    n-=2;
    int i = 0, j = 1;
    cout << i << " " << j << " ";
    while(n--){
        cout << (i+=j) << " ";
        if (n<1)
        {
            break;
        }
        n--;
        cout << (j+=i) << " ";
    }
}

int main(){
    int n;
    cin >> n;
    fibonacci(n);
    cout << endl;
    return 0;
}