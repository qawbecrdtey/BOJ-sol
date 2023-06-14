#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s, t; getline(cin, s); getline(cin, t);
    for(char c : t) {
        if(c >= 'A' && c <= 'Z') cout << (char)(s[c - 'A'] + 'A' - 'a');
        else if(c >= 'a' && c <= 'z') cout << s[c - 'a'];
        else cout << c;
    }
}