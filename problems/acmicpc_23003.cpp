#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ':';
        int n; string s; cin >> n >> s; int res = 1;
        for(int i = 0; i < n; i++) {
            if(!i || s[i] <= s[i - 1]) cout << ' ' << (res = 1);
            else cout << ' ' << ++res;
        }
        cout << '\n';
    }
}
