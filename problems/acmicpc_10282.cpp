#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct info {
    int next;
    int time;
    bool operator<(info const &i) const { return time > i.time; }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, d, c; cin >> n >> d >> c;
        auto v = new vector<info>[n + 1];
        for(int i = 0; i < d; i++) {
            int a, b, s; cin >> a >> b >> s;
            v[b].push_back({a, s});
        }
        priority_queue<info> pq;
        pq.push({c, 0});
        auto visited = new bool[n + 1]();
        int cnt = 0;
        int restime = 0;
        while(!pq.empty()) {
            auto [now, time] = pq.top(); pq.pop();
            if(visited[now]) continue;
            cnt++;
            visited[now] = true;
            restime = max(restime, time);
            for(auto [next, nexttime] : v[now]) {
                if(visited[next]) continue;
                pq.push({next, time + nexttime});
            }
        }
        cout << cnt << ' ' << restime << '\n';
        delete[] visited;
        delete[] v;
    }
}