#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b, k; cin >> a >> b >> k;
    if(b % a) {
        cout << "-1";
        return 0;
    }
    vector<ll> v;
    ll const x = b / a;
    for(ll i = 1; i * i <= x; i++) {
        if(x % i) continue;
        v.push_back(i);
        if(i * i != x) v.push_back(x / i);
    }
    sort(v.begin(), v.end());
    if(v.size() < k) {
        cout << "-1";
        return 0;
    }
    cout << v.front() * a << ' ' << v.back() * a;
    for(ll i = 1; i < k - 1; i++) {
        cout << ' ' << v[i] * a;
    }
}
