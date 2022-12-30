#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        if(s.size() == 1) {
            cout << s << '\n';
            continue;
        }
        cout << s << '\n';
        for(int i = 1; i < s.size() - 1; i++) {
            cout << s[i] << string(s.size() - 2, ' ') << s[s.size() - i - 1] << '\n';
        } for(auto it = s.rbegin(); it != s.rend(); ++it) cout << *it; cout << '\n';
    }
}