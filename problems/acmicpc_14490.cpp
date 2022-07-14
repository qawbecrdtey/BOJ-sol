#include <cstdio>
using ll = long long;
ll gcd(ll a, ll b) {
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
    ll a, b;
    scanf("%lld:%lld", &a, &b);
    ll g = gcd(a, b);
    printf("%lld:%lld", a / g, b / g);
}