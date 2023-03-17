#include <iostream>
#include <string>
using namespace std;
inline bool is_palindrome(string const &s) {
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - i - 1]) return false;
    } return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    for(int i = 1; i < s.size(); i++) {
        if(is_palindrome(s.substr(0, i)) && is_palindrome(s.substr(i))) {
            cout << s.substr(0, i) << ' ' << s.substr(i);
            return 0;
        }
    } cout << "NO";
}