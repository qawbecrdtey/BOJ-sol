#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        long long n; cin >> n;
        cout << (n * (n + 1)) / 2 << ' ' << n * n << ' ' << n * (n + 1) << '\n';
    }
}