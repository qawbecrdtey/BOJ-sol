#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, l; cin >> n >> l;
    int res = 0, cnt = 0;
    while(n--) {
        string s; cin >> s;
        int loc = 0;
        auto it = s.begin();
        while(it != s.end()) {
            int add = 0;
            while(it != s.end() && *it == '0') ++it;
            while(it != s.end() && *it == '1') add = 1, ++it;
            loc += add;
        }
        if(loc < res) continue;
        if(loc == res) cnt++;
        else res = loc, cnt = 1;
    }
    cout << res << ' ' << cnt;
}