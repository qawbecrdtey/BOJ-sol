#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n; ll x = n * (n + 1) / 2; cout << x << '\n' << x * x << '\n' << x * x;
}