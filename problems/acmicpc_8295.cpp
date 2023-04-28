#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, p; cin >> n >> m >> p;
    int cnt = 0;
    for(int wl = 0; wl < n; wl++) {
        for(int wr = wl + 1; wr <= n; wr++) {
            for(int cl = 0; cl < m; cl++) {
                for(int cr = cl + 1; cr <= m; cr++) {
                    cnt += ((cr - cl + wr - wl) * 2 >= p);
                }
            }
        }
    } cout << cnt;
}