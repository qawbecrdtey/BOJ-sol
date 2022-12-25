#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    for(char c : s) {
        switch(c) {
            case 'a': cout << '4'; break;
            case 'e': cout << '3'; break;
            case 'i': cout << '1'; break;
            case 'o': cout << '0'; break;
            case 's': cout << '5'; break;
            default: cout << c; break;
        }
    }
}