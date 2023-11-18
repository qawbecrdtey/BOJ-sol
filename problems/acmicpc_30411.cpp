#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll n, k; cin >> n >> k;
    ll const a = n / 2;
    if(a * (n - a) < k) {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    ll cnt = 0;
    for(ll i = 1; i <= a; i++) {
        for(ll j = a + 1; j <= n; j++) {
            if(cnt == k) return 0;
            cout << '\n' << i << ' ' << j;
            cnt++;
        }
    }
}