#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    while(true) {
        cin >> s;
        if(s == "0") return 0;
        int res = 1;
        for(char c : s) {
            if(c == '1') res += 3;
            else if(c == '0') res += 5;
            else res += 4;
        }
        cout << res << '\n';
    }
}