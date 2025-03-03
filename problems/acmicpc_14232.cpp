#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll x; cin >> x;
    vector<ll> v;
    for(ll i = 2; i * i <= x; i++) {
        while(x % i == 0) v.push_back(i), x /= i;
    }
    if(x != 1) v.push_back(x);
    cout << v.size() << '\n';
    for(ll const now : v) cout << now << ' ';
}
