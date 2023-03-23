#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
inline ll dist2(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        pair<ll, ll> a[4]; for(auto &i : a) cin >> i.first >> i.second;
        sort(a, a + 4);
        cout << (dist2(a[0], a[3]) == dist2(a[1], a[2]) && dist2(a[0], a[1]) == dist2(a[0], a[2])) << '\n';
    }
}