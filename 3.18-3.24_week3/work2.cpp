#include<iostream>
#include<cstring>
using namespace std;

void Mysort(int a[], int size){
    for(int i = 0; i < size; i++){
        for(int j = i+1; j < size; j++){
            if(a[i] > a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int a[] = {3,5,7,9,2,1,3,6,8,4};
    int size = sizeof(a) / sizeof(a[0]);
    Mysort(a,size);
    cout << "sorted array:" << endl;
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}