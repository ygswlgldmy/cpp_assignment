#include<iostream>
#include<stdio.h>
using namespace std;

class Room {
    public:
        string SittingRoom = "����Ŀ���";
        friend void getRoom(const Room &room) {
            cout << "��Ԫ�������ڷ���:" << room.SittingRoom << endl;
            cout << "��Ԫ�������ڷ���:" << room.BedRoom << endl;
        }
    private:
        string BedRoom = "���������";
};

int main(){
    class Room room;
    getRoom(room);
    return 0;
}