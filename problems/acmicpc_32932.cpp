#include <algorithm>
#include <iostream>
using namespace std;
static void move(int const n, pair<int, int> const *const a, int &x, int const dx, int &y, int const dy) {
    auto const it = find(a, a + n, make_pair(x + dx, y + dy));
    if(it != a + n) return;
    x += dx; y += dy;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    auto c = new char[k + 1]; cin >> c;
    int x = 0, y = 0;
    for(int i = 0; i < k; i++) {
        switch(c[i]) {
            case 'L': move(n, a, x, -1, y, 0); break;
            case 'R': move(n, a, x, 1, y, 0); break;
            case 'U': move(n, a, x, 0, y, 1); break;
            case 'D': move(n, a, x, 0, y, -1); break;
            default: __builtin_unreachable();
        }
    }
    cout << x << ' ' << y;
}
