#include <iostream>
#include <string>
using namespace std;
bool is_palindrome(string const &s) {
    for(int i = 0; i < s.size() / 2; i++) {
        if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        auto s = new string[n];
        for(int i = 0; i < n; i++) {
            cin >> s[i];
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                auto const str = s[i] + s[j];
                if(is_palindrome(str)) {
                    cout << str << '\n';
                    goto END;
                }
            }
        }
        cout << 0 << '\n';
    END:delete[] s;
    }
}