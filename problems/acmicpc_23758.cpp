#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 0;
    int const N = ((n + 1) >> 1);
    for(int i = 0; i < N; i++) {
        res += __builtin_clz(a[i]);
    }
    cout << 31 * N - res + 1;
}