#include <iostream>
#include <string>
using namespace std;
inline char change(char c) {
    if(c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    return c - 'a' + 'A';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    while(true) {
        getline(cin, s);
        if(s[0] == '#') break;
        int cnt = 0;
        for(auto it = s.begin() + 1; it != s.end(); ++it) {
            cnt += (s[0] == *it || s[0] == change(*it));
        } cout << s[0] << ' ' << cnt << '\n';
    }
}