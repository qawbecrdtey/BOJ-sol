#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using ll = long long;
using namespace std;
struct uf {
    ll n;
    ll *root;
    uf(ll n) : n(n), root(new ll[n]) {
        for(ll i = 0; i < n; i++) {
            root[i] = i;
        }
    }
    ll find(ll a) {
        if(root[a] == a) return a;
        return root[a] = find(root[a]);
    }
    void merge(ll a, ll b) {
        auto x = find(a);
        auto y = find(b);
        if(x == y) return;
        root[x] = y;
    }
    bool check(ll a, ll b) {
        return find(a) == find(b);
    }
};
pair<ll, ll> tree(vector<pair<ll, ll>> *v, ll n, ll now, ll prev) { // longest path of tree, longest path from a
    vector<ll> a; // longest path from a
    ll max = 0;
    for(int i = 0; i < v[now].size(); i++) {
        if(v[now][i].second == prev) continue;
        auto p = tree(v, n, v[now][i].second, now);
        a.emplace_back(p.second + v[now][i].first);
        if(max < p.first) max = p.first;
    }
    if(a.empty()) return { 0, 0 };
    if(a.size() == 1) return { a.front() > max ? a.front() : max, a.front() };
    sort(a.begin(), a.end());
    if(max < a[a.size() - 1] + a[a.size() - 2]) max = a[a.size() - 1] + a[a.size() - 2];
    return { max, a[a.size() - 1] };
}
int main(){
    ll n, k;
    cin >> n >> k;
    auto v = new vector<pair<ll, ll>>[n];
    priority_queue<pair<ll, pair<ll, ll>>> pq;
    for(int i = 0; i < k; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        pq.push(make_pair(-c, make_pair(a, b)));
    }
    uf u(n);
    ll sum = 0;
    while(!pq.empty()) {
        auto const now = pq.top(); pq.pop();
        if(u.check(now.second.first, now.second.second)) continue;
        sum -= now.first;
        u.merge(now.second.first, now.second.second);
        v[now.second.first].emplace_back(-now.first, now.second.second);
        v[now.second.second].emplace_back(-now.first, now.second.first);
    }
    auto p = tree(v, n, 0, -1);
    cout << sum << '\n' << p.first;
    delete[] v;
}