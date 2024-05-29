#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    if(n <= 1 || m <= 1) {
        cout << 0;
        return 0;
    }
    auto a = new int[n];
    auto b = new int[m];
    int const N = (n * (n - 1)) >> 1;
    int const M = (m * (m - 1)) >> 1;
    auto aa = new int[N];
    auto bb = new int[M];
    int idx = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < i; j++) {
            aa[idx] = a[i] - a[j];
            idx++;
        }
    }
    idx = 0;
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        for(int j = 0; j < i; j++) {
            bb[idx] = b[i] - b[j];
            idx++;
        }
    }
    sort(aa, aa + N);
    long long res = 0;
    for(int i = 0; i < M; i++) {
        res += upper_bound(aa, aa + N, bb[i]) - lower_bound(aa, aa + N, bb[i]);
    }
    cout << res;
}
