#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(!i || s[i - 1] != s[i]) cout << s[i];
        } cout << '\n';
    }
}