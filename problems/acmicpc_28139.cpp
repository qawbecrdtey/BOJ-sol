#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
inline long double dist(pair<ll, ll> const &a, pair<ll, ll> const &b) {
    return sqrtl((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    long double sum = 0;
    auto a = new pair<ll, ll>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        for(int j = 0; j < i; j++) {
            sum += dist(a[i], a[j]);
        }
    }
    cout.precision(12);
    cout << fixed << sum * 2 / n << std::endl;
}