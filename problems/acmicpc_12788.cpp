#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int sum = 0;
    for(int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if(sum >= m * k) {
            cout << n - i;
            return 0;
        }
    }
    cout << "STRESS";
}