#include <iostream>
#include <optional>
#include <vector>
using namespace std;
optional<bool> dfs(vector<pair<int, bool>> const *v, int now, int prev, int dst, bool ccw) {
    if(now == dst) return ccw;
    for(auto [next, dir] : v[now]) {
        if(next == prev) continue;
        auto res = dfs(v, next, now, dst, ccw ^ dir);
        if(res.has_value()) return res;
    }
    return nullopt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto v = new vector<pair<int, bool>>[n + 1];
    for(int i = 1; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    cout << dfs(v, 1, -1, n, false).value();
}