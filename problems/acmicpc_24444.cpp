#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    auto s = new set<int>[n + 1];
    while(m--) {
        int x, y; cin >> x >> y;
        s[x].insert(y);
        s[y].insert(x);
    }
    vector<int> visited(n + 1);
    queue<int> q;
    q.push(k);
    int cnt = 1;
    while(!q.empty()) {
        auto const now = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = cnt++;
        for(int next : s[now]) {
            if(!visited[next]) q.push(next);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}