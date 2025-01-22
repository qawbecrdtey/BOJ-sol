#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt; cin >> tt; for(int ttt = 1; ttt <= tt; ttt++) {
        cout << "Case #" << ttt << ": ";
        string s, t; cin >> s >> t;
        int i = 0, j = 0, cnt = 0;
        while(i < s.size() && j < t.size()) {
            while(j < t.size() && t[j] != s[i]) cnt++, j++;
            if(j == t.size()) goto NO;
            i++, j++;
        }
        if(i < s.size()) goto NO;
        cnt += t.size() - j;
        cout << cnt << '\n';
        continue;
NO:     cout << "IMPOSSIBLE\n";
    }
}
