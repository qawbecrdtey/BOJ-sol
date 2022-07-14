#include <iostream>
#include <string>
using namespace std;
inline char upper(char c) { return (c >= 'a' && c <= 'z') ? (char)(c - 'a' + 'A') : c; }
int main() {
    string s; bool flag = false;
    while(cin >> s) {
        if(flag && (s == "i" || s == "pa" || s == "te" || s == "ni" || s == "niti" || s == "a" || s == "ali" || s == "nego" || s == "no" || s == "ili")) continue;
        cout << upper(s[0]);
        flag = true;
    }
}