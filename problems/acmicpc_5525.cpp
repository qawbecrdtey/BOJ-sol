#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; string s; cin >> n >> m >> s;
    int res = 0;
    int idx = 0;
    while(idx < m) {
        while(idx < m && s[idx] == 'O') idx++;
        if(idx == m) break;
        int cnt = 0;
        while(idx < m - 2 && s[idx + 1] == 'O' && s[idx + 2] == 'I') idx += 2, cnt++;
        res += max(0, cnt - n + 1);
        idx++;
    }
    cout << res;
}