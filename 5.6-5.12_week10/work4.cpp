#include<iostream>
#include<iomanip>
using namespace std;

class Timer {
    private:
        int hour, minute, second, delay;
    public:
        friend istream &operator>>(istream &is, Timer &t){
            char get;
            is >> t.hour >> get >> t.minute >> get >> t.second;
            return is;
        }
        friend ostream &operator<<(ostream &os, const Timer &t){
            os << t.hour << ":" 
               << setw(2) << setfill('0') << t.minute << ":" 
               << setw(2) << setfill('0') << t.second << endl;
            return os;
        }
        void after(){
            while(delay--){
                second++;
                if(second == 60){
                    second = 0;
                    minute++;
                    if(minute == 60){
                        minute = 0;
                        hour++;
                        if(hour == 24){
                            hour = 0;
                        }
                    }
                }
            }
        }
        void set(){
            cin >> delay;
        }
};

int main(){
    Timer t;
    cin >> t;
    t.set();
    t.after();
    cout << "Timer reading after 125 seconds: " << t;
}