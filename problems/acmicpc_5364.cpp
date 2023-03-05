#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    int n; cin >> n;
    auto a = new pair<ll, ll>[n];
    ll res = 0x7fffffffffffffff, resi = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        if(!i) continue;
        ll const x = (a[0].first - a[i].first) * (a[0].first - a[i].first) + (a[0].second - a[i].second) * (a[0].second - a[i].second);
        if(res > x) res = x, resi = i;
    } cout << a[0].first << ' ' << a[0].second << '\n';
    cout << a[resi].first << ' ' << a[resi].second << '\n';
    printf("%.2Lf", sqrtl(res));
}