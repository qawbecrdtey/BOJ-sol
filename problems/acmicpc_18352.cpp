#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k, x; cin >> n >> m >> k >> x;
    auto v = new vector<int>[n + 1];
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    queue<pair<int, int>> q;
    vector<bool> visited(n + 1);
    vector<int> res;
    q.push({ x, 0 });
    while(!q.empty()) {
        auto const [now, dist] = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(dist == k) {
            res.push_back(now);
            continue;
        }
        for(auto next : v[now]) {
            if(!visited[next]) q.push({ next, dist + 1 });
        }
    }
    if(res.empty()) cout << -1;
    else {
        sort(res.begin(), res.end());
        for(auto now : res) cout << now << '\n';
    }
}