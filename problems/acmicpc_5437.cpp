#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int p, n; cin >> p >> n;
        auto a = new int[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n, [](int a, int b) { return a > b; });
        int const x = n / (p + 1);
        int sum = 0;
        for(int i = 0; i < x; i++) {
            sum += a[i];
        }
        cout << sum << '\n';
        delete[] a;
    }
}
