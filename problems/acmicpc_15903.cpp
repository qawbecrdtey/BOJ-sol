#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n, m; cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<>> pq;
    for(ll i = 0; i < n; i++) {
        ll x; cin >> x; pq.push(x);
    }
    while(m--) {
        ll const x = pq.top(); pq.pop();
        ll const y = pq.top(); pq.pop();
        ll const z = x + y;
        pq.push(z); pq.push(z);
    }
    ll res = 0;
    while(!pq.empty()) {
        res += pq.top(); pq.pop();
    }
    cout << res;
}
