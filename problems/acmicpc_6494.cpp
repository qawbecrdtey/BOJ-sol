#include <iostream>
#include <numeric>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; while(cin >> n >> m) {
        if(!n && !m) return 0;
        auto const a = new int[n];
        int sum = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> a[i];
            }
            sum += a[i];
        }
        for(int i = 0; i < n; i++) {
            int const g = gcd(sum, a[i]);
            cout << a[i] / g << " / " << sum / g << '\n';
        }
        delete[] a;
    }
}