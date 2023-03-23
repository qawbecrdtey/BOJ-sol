#include <iostream>
#include <vector>
using namespace std;
int min_val(vector<int> const *v, int const *cost, bool *visited, int now, int prev) {
    visited[now] = true;
    int res = cost[now];
    for(int next : v[now]) {
        if(visited[next]) continue;
        res = min(res, min_val(v, cost, visited, next, now));
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    auto cost = new int[n + 1];
    for(int i = 1; i <= n; i++) cin >> cost[i];
    auto v = new vector<int>[n + 1];
    while(m--) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    auto visited = new bool[n + 1]();
    int res = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) res += min_val(v, cost, visited, i, 0);
    } if(res <= k) cout << res; else cout << "Oh no";
}