#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    ll m = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x; sum += x, m = max(m, x);
    }
    if(sum == 1 || m * 2 <= sum) cout << "Happy";
    else cout << "Unhappy";
}