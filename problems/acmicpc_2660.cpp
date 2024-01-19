#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int bfs(vector<int> const *v, int n, int s) {
    queue<pair<int, int>> q;
    q.emplace(s, 0);
    vector<bool> visited(n + 1);
    int res = 0;
    while(!q.empty()) {
        auto [now, now_dist] = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        res = now_dist;
        for(auto next : v[now]) {
            if(visited[next]) continue;
            q.emplace(next, now_dist + 1);
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto v = new vector<int>[n + 1];
    int x, y; while(cin >> x >> y) {
        if(x == -1 && y == -1) break;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    auto a = new int[n + 1];
    int m = n + 1;
    for(int i = 1; i <= n; i++) {
        a[i] = bfs(v, n, i);
        if(m > a[i]) m = a[i];
    }
    cout << m << ' ';
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        if(a[i] == m) res.push_back(i);
    }
    cout << res.size() << '\n';
    for(auto now : res) {
        cout << now << ' ';
    }
}