#include <iostream>
#include <queue>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b; cin >> a >> b;
    ll c = a, d = b;
    queue<ll> qa, qb;
    for(ll i = 2; i * i <= c; i++) {
        while(c % i == 0) qa.push(i), c /= i;
    }
    if(c != 1) qa.push(c);
    for(ll i = 2; i * i <= d; i++) {
        while(d % i == 0) qb.push(i), d /= i;
    }
    if(d != 1) qb.push(d);
    while(a != b) {
        if(a > b) {
            a /= qa.front(); qa.pop();
        }
        else {
            b /= qb.front(); qb.pop();
        }
    }
    cout << a;
}
