#include <iostream>
#include <numeric>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        if(c % gcd(a, b) == 0 && (c <= a || c <= b)) cout << "YES\n";
        else cout << "NO\n";
    }
}