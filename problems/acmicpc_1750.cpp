#include <iostream>
#include <numeric>
#include <map>
using namespace std;
using ll = long long;
static constexpr ll M = 10000003;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    map<int, ll> s; int n; cin >> n; s[0] = 1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        map<int, ll> t;
        for(auto [now, cnt] : s) {
            t[now] = (t[now] + cnt) % M;
            t[gcd(now, x)] = (t[gcd(now, x)] + cnt) % M;
        } s = std::move(t);
    } cout << s[1];
}