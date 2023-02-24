#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        if(s.size() < 3 || (s.size() == 3 && s[1] != 'O')) {
            cout << "-1\n";
            continue;
        } int res = -1;
        for(int i = 2; i < s.size(); i++) {
            if(s[i - 1] == 'O') {
                int const r = (int)s.size() + (s[i - 2] != 'M') + (s[i] != 'O') - 3;
                if(res == -1) res = r;
                else res = min(res, r);
            }
        }
        cout << res << '\n';
    }
}