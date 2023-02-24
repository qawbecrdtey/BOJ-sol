#include <cmath>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }
        long double res = 0;
        for(int i = 1; i <= n; i++) res += log10l(i);
        cout << (long long)ceill(res) << '\n';
    }
}