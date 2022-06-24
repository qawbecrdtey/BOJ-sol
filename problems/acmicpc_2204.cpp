#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
inline char lower(char c) {
    return static_cast<char>((c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c);
}
inline string convert(string const &s) {
    string res;
    for(char c : s) {
        res += lower(c);
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        auto s = new string[n];
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        } sort(s, s + n, [](string const &a, string const &b) {
            return convert(a) < convert(b);
        }); cout << s[0] << '\n';
        delete[] s;
    }
}