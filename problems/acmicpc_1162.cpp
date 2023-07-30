#include <array>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
using ll = long long;
struct dist_data {
    ll free_pass;
    ll dist;
    bool operator<(dist_data const &rhs) const { return dist > rhs.dist || (dist == rhs.dist && free_pass > rhs.free_pass); }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, m, k; cin >> n >> m >> k;
    auto v = new vector<pair<ll, ll>>[n + 1];
    for(ll i = 0; i < m; i++) {
        ll x, y, z; cin >> x >> y >> z;
        v[x].emplace_back(y, z);
        v[y].emplace_back(x, z);
    }
    priority_queue<pair<dist_data, ll>> pq;
    pq.push({{0, 0}, 1});
    auto visited = new bool*[n + 1];
    for(ll i = 1; i <= n; i++) {
        visited[i] = new bool[k + 1]();
    }
    while(!pq.empty()) {
        auto [d, now] = pq.top(); pq.pop();
        if(visited[now][d.free_pass]) continue;
        visited[now][d.free_pass] = true;
        if(now == n) {
            cout << d.dist;
            return 0;
        }
        for(auto [next, dist] : v[now]) {
            if(!visited[next][d.free_pass]) {
                pq.push({{d.free_pass, d.dist + dist}, next});
            }
            if(d.free_pass < k && !visited[next][d.free_pass + 1]) {
                pq.push({{d.free_pass + 1, d.dist}, next});
            }
        }
    }
}