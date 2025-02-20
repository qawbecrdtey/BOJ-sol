#include <iostream>
using namespace std;
using ll = long long;
bool is_prime(ll n) {
    for(ll i = 2; i * i <= n; i++) {
        if(n % i) continue;
        return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n; if(n <= 1) { cout << "BROKEN"; return 0; }
    if(is_prime(n)) cout << "SAFE";
    else cout << "BROKEN";
}
