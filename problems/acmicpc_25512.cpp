#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
pair<ll, ll> f(vector<int> const *v, pair<ll, ll> const *cost, int now, int prev) {
    pair<ll, ll> res = {cost[now].first, cost[now].second};
    for(int next : v[now]) {
        if(next == prev) continue;
        auto const p = f(v, cost, next, now);
        res.first += p.second;
        res.second += p.first;
    } return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto v = new vector<int>[n];
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    auto cost = new pair<ll, ll>[n];
    for(int i = 0; i < n; i++) cin >> cost[i].first >> cost[i].second;
    auto const p = f(v, cost, 0, -1);
    cout << min(p.first, p.second);
}