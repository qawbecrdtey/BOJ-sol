#include <iostream>
#include <string>
using namespace std;
using ld = long double;
int main() {
    cout.precision(4);
    int n; cin >> n; while(n--) {
        ld v; string s;
        cin >> v >> s;
        if(s == "kg") {
            cout << fixed << v * 2.2046 << " lb\n";
        }
        else if(s == "l") {
            cout << fixed << v * 0.2642 << " g\n";
        }
        else if(s == "lb") {
            cout << fixed << v * 0.4536 << " kg\n";
        }
        else {
            cout << fixed << v * 3.7854 << " l\n";
        }
    }
}
