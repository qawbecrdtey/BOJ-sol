#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m; n += m;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    vector<int> v[101];
    for(int i = 1; i < 100; i++) {
        for(int j = 1; j <= 6 && i + j <= 100; j++) {
            int dst = i + j;
            for(int k = 0; k < n; k++) {
                if(a[k].first == dst) {
                    dst = a[k].second;
                    break;
                }
            }
            v[i].push_back(dst);
        }
    }
    queue<pair<int, int>> q;
    vector<bool> visited(101);
    q.push({ 1, 0 });
    while(!q.empty()) {
        auto const [now, dist] = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(now == 100) {
            cout << dist;
            return 0;
        }
        for(auto next : v[now]) {
            if(!visited[next]) q.push({ next, dist + 1 });
        }
    }
}