#include <iostream>
using namespace std;
inline bool invalid(int x) { return x == 1 || x == 3 || x == 4; }
int main() {
    int a, b; cin >> a >> b;
    if(invalid(a)) {
        if(invalid(b)) cout << '=';
        else cout << '<';
        return 0;
    }
    if(invalid(b)) {
        cout << '>';
        return 0;
    }
    if(a == b) {
        cout << '=';
        return 0;
    }
    if(!a) {
        if(b == 5) cout << '<';
        else cout << '>';
        return 0;
    }
    if(a == 2) {
        if(!b) cout << '<';
        else cout << '>';
        return 0;
    }
    if(a == 5) {
        if(b == 2) cout << '<';
        else cout << '>';
        return 0;
    }
}
