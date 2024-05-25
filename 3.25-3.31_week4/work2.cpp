#include<iostream>
#include<math.h>
using namespace std;

double getdis(int x, int y){
    double dis = sqrt(pow(x,2)+pow(y,2));
    return dis;
}

double getdis(int x, int y, int z){
    double dis = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    return dis;
}

double getdis(double x, double y){
    double dis = sqrt(pow(x,2)+pow(y,2));
    return dis;
}

double getdis(double x, double y, double z){
    double dis = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    return dis;
}

int main(){
    cout << "Distance from (1.5, -1.5) to origin: " << getdis(1.5,-1.5) << endl;
    cout << "Distance from (1, 1, 1) to origin: " << getdis(1,1,1) << endl;
    return 0;
}