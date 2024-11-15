#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    ll i = 0; while(i * (i + 1) / 2 <= n) i++;
    cout << i - 1;
}
