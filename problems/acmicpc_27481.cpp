#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    string t(10, '0');
    for(char c : s) {
        switch(c) {
            case 'L':
                for(int i = 0; i <= 9; i++) {
                    if(t[i] == '0') {
                        t[i] = '1';
                        break;
                    }
                } break;
            case 'R':
                for(int i = 9; i >= 0; i--) {
                    if(t[i] == '0') {
                        t[i] = '1';
                        break;
                    }
                } break;
            case '0': t[0] = '0'; break;
            case '1': t[1] = '0'; break;
            case '2': t[2] = '0'; break;
            case '3': t[3] = '0'; break;
            case '4': t[4] = '0'; break;
            case '5': t[5] = '0'; break;
            case '6': t[6] = '0'; break;
            case '7': t[7] = '0'; break;
            case '8': t[8] = '0'; break;
            case '9': t[9] = '0'; break;
            default: __builtin_unreachable();
        }
    } cout << t;
}