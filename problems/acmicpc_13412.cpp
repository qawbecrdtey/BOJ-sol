#include <iostream>
#include <numeric>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, cnt{}; cin >> n;
        for(int i = 1; i * i <= n; i++) {
            if(n % i) continue;
            if(gcd(i, n / i) == 1) cnt++;
        } cout << cnt << '\n';
    }
}