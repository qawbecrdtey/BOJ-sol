#include <iostream>
#include <string>
using namespace std;
inline int hex(char n) {
    switch(n) {
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        default: __builtin_unreachable();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    for(int i = 0; i < s.size(); i += 2) {
        cout << (char)(hex(s[i]) * 16 + hex(s[i + 1]));
    }
}