#include<iostream>
#include<stdio.h>
using namespace std;

class Room {
    public:
        string SittingRoom = "家里的客厅";
        friend void getRoom(const Room &room) {
            cout << "友元函数正在访问:" << room.SittingRoom << endl;
            cout << "友元函数正在访问:" << room.BedRoom << endl;
        }
    private:
        string BedRoom = "家里的卧室";
};

int main(){
    class Room room;
    getRoom(room);
    return 0;
}