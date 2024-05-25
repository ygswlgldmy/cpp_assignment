#include<iostream>
using namespace std;

int main(){
    int a[][4] = {{1,2}, {3,4,5}, {6,7,8,9}, {10,11}};
    cout << "2d-array:" << endl;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4 ; j++){
            if(a[i][j] == 0){
                break;
            }
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}