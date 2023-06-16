#include <iostream>
using namespace std;
int main() {
    int ax, ay, bx, by; cin >> ax >> ay >> bx >> by;
    while(ay > 0 && by > 0) ay -= bx, by -= ax;
    if(ay <= 0 && by <= 0) cout << "DRAW";
    else if(ay <= 0) cout << "PLAYER B";
    else cout << "PLAYER A";
}