#include <iostream>
#include <vector>
#include <memory>
using namespace std;
void dfs(unique_ptr<vector<int>[]> &v, unique_ptr<int[]> &visit, unique_ptr<int[]> &depth, unique_ptr<int[]> &first, int const now, int const d, int& idx) {
    visit[idx] = now;
    depth[idx] = d;
    first[now] = idx;
    for(auto next : v[now]) {
        idx++;
        dfs(v, visit, depth, first, next, d + 1, idx);
        idx++;
        visit[idx] = now;
        depth[idx] = d;
    }
}
void init(unique_ptr<int[]> &t, unique_ptr<int[]> &a, int const tidx, int const l, int const r) {
    if(l == r) { t[tidx] = l; return; }
    auto const m = (l + r) / 2;
    init(t, a, tidx << 1, l, m);
    init(t, a, (tidx << 1) + 1, m + 1, r);
    auto const x = t[tidx << 1];
    auto const y = t[(tidx << 1) + 1];
    t[tidx] = (a[x] < a[y] ? x : y);
}
int mini(unique_ptr<int[]> &t, unique_ptr<int[]> &a, int const tidx, int const start, int const end, int const l, int const r) {
    if(end < l || r < start) return 0;
    if(start <= l && r <= end) return t[tidx];
    auto const m = (l + r) / 2;
    auto const x = mini(t, a, tidx << 1, start, end, l, m);
    auto const y = mini(t, a, (tidx << 1) + 1, start, end, m + 1, r);
    if(!x) return y;
    if(!y) return x;
    return a[x] < a[y] ? x : y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        auto v = make_unique<vector<int>[]>(n + 1);
        auto deg = make_unique<int[]>(n + 1);
        for(int i = 1; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            deg[y]++;
        }
        int root = 0;
        for(int i = 1; i <= n; i++) {
            if(!deg[i]) {
                root = i;
                break;
            }
        }
        auto const N = (n << 1) - 1;
        auto visit = make_unique<int[]>(n * 2);
        auto depth = make_unique<int[]>(n * 2);
        auto first = make_unique<int[]>(n + 1);
        auto t = make_unique<int[]>(N * 4);
        int idx = 1;
        dfs(v, visit, depth, first, root, 1, idx);
        init(t, depth, 1, 1, N);
        int s, e;
        cin >> s >> e;
        if(first[s] > first[e]) swap(s, e);
        idx = mini(t, depth, 1, first[s], first[e], 1, N);
        cout << visit[idx] << '\n';
    }
}