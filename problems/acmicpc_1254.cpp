#include <iostream>
#include <string>
using namespace std;
bool is_palindrome(string::iterator b, string::iterator e) {
    if(b + 1 >= e) return true;
    return *b == *(e - 1) && is_palindrome(b + 1, e - 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string s; cin >> s;
    for(int i = 0; i <= s.size(); i++) {
        if(is_palindrome(s.begin() + i, s.end())) {
            cout << s.size() + i;
            return 0;
        }
    }
}
