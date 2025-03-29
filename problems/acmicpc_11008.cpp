#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s, ss; cin >> s >> ss;
        int idx = 0, cnt = 0;
        while(idx < s.size()) {
            if(s.substr(idx, ss.size()) == ss) {
                idx += ss.size();
            }
            else idx++;
            cnt++;
        }
        cout << cnt << '\n';
    }
}
