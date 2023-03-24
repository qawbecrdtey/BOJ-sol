#include <iostream>
#include <vector>
using namespace std;
int depth(vector<int> const *v, int dst, int now, int prev, int d) {
    if(now == dst) return d;
    for(int next : v[now]) {
        if(next == prev) continue;
        int d_ = depth(v, dst, next, now, d + 1);
        if(d_ == -1) continue;
        return d_;
    } return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    auto v = new vector<int>[n + 1];
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 0; i < n; i++) {
        int x; cin >> x; if(x == k) {
            cout << depth(v, 0, i, -1, 0);
            return 0;
        }
    }
}