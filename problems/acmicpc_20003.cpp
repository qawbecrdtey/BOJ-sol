#include <stdio.h>
#include <utility>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}
int main() {
    int n;
    scanf("%d", &n);
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    ll l = a[0].second;
    for(int i = 1; i < n; i++) {
        l = lcm(l, a[i].second);
    }
    ll g = a[0].first * l / a[0].second;
    for(int i = 1; i < n; i++) {
        g = gcd(g, a[i].first * l / a[i].second);
    }
    ll gg = gcd(g, l);
    printf("%lld %lld", g / gg, l / gg);
    delete[] a;
}