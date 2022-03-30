#include <iostream>
#include <string>
using namespace std;
inline bool is_palindrome(string const &s) {
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - 1 - i]) return false;
    } return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; getline(cin, s);
        if(s.empty()) getline(cin, s);
        for(char &c : s) if(c >= 'A' && c <= 'Z') c += 'a' - 'A';
        if(is_palindrome(s)) cout << "Yes\n"; else cout << "No\n";
    }
}