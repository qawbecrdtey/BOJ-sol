#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int r, c; cin >> r >> c;
        auto v = new vector<pair<int, int>>[r * c];
        for(int i = 0; i < r; i++) {
            for(int j = 1; j < c; j++) {
                int x; cin >> x;
                v[i * c + j - 1].emplace_back(i * c + j, x);
                v[i * c + j].emplace_back(i * c + j - 1, x);
            }
        }
        for(int i = 1; i < r; i++) {
            for(int j = 0; j < c; j++) {
                int x; cin >> x;
                v[(i - 1) * c + j].emplace_back(i * c + j, x);
                v[i * c + j].emplace_back((i - 1) * c + j, x);
            }
        }
        auto visited = new bool[r * c]();
        priority_queue<pair<int, int>> pq;
        pq.emplace(0, 0);
        long long res = 0;
        while(!pq.empty()) {
            auto [cost, now] = pq.top(); pq.pop();
            if(visited[now]) continue;
            visited[now] = true;
            res -= cost;
            for(auto [next, next_cost] : v[now]) {
                if(visited[next]) continue;
                pq.emplace(-next_cost, next);
            }
        }
        cout << res << '\n';
        delete[] visited;
        delete[] v;
    }
}