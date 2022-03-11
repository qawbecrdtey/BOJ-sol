#include <iostream>
using namespace std;
int main() {
    int prev = -1000001, now;
    while(cin >> now) {
        if(prev > now) {
            cout << "Bad";
            return 0;
        }
        prev = now;
    } cout << "Good";
}