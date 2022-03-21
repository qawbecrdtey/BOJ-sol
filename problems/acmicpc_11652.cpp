#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<ll, int> m;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x; m[x]++;
    }
    vector<pair<int, ll>> v;
    v.reserve(m.size());
    for(auto [x, y] : m) v.emplace_back(y, x);
    sort(v.begin(), v.end(), [](pair<int, ll> const &a, pair<int, ll> const &b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    cout << v[0].second;
}