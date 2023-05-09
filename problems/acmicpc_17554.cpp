#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    auto a = new int[n + 1];
    fill(a + 1, a + n + 1, 1);
    int cur = n;
    int diff;
    int m = n;
    for(int i = 0; i < k; i++) {
        diff = 0;
        int x; cin >> x;
        for(int j = x; j <= n; j += x) {
            if(a[j]) {
                diff--;
                a[j] = 0;
            }
            else {
                diff++;
                a[j] = 1;
            }
        }
        cur += diff;
        m = min(m, cur);
    } cout << n - m;
}