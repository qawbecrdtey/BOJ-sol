#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        ll a, b, c; cin >> a >> b >> c; if(c % gcd(a, b) == 0) cout << "Yes\n"; else cout << "No\n";
    }
}
