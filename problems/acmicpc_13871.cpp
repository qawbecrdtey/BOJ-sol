#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, c, s; cin >> n >> c >> s;
    int cnt = 0, cur = 1;
    for(int i = 0; i <= c; i++) {
        cnt += (cur == s);
        if(i == c) break;
        int x; cin >> x;
        cur = (cur + n + x - 1) % n + 1;
    } cout << cnt;
}