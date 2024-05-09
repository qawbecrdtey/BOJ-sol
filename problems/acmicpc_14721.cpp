#include <iostream>
#include <limits>
#include <utility>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<ll, ll>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ll RSS = numeric_limits<ll>::max();
    ll resA = -1, resB = -1;
    for(ll A = 1; A <= 100; A++) {
        for(ll B = 1; B <= 100; B++) {
            ll res = 0;
            for(int i = 0; i < n; i++) {
                res += (a[i].second - a[i].first * A - B) * (a[i].second - a[i].first * A - B);
            }
            if(res < RSS) {
                resA = A;
                resB = B;
                RSS = res;
            }
        }
    }
    cout << resA << ' ' << resB;
}
