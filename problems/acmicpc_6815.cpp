#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll a, b; cin >> a >> b;
    ll cnt{};
    for(ll i = 1; i * i * i * i * i * i <= b; i++) {
        cnt += (i * i * i * i * i * i >= a);
    } cout << cnt;
}