#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n, m;
    cin >> t >> n;
    auto a = new int[n];
    vector<int> va, vb;
    va.reserve(n * (n + 1) / 2);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int sum = 0;
        for(int j = i; j >= 0; j--) {
            sum += a[j];
            va.emplace_back(sum);
        }
    }
    cin >> m;
    auto b = new int[m];
    vb.reserve(m * (m + 1) / 2);
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        int sum = 0;
        for(int j = i; j >= 0; j--) {
            sum += b[j];
            vb.emplace_back(sum);
        }
    }
    delete[] a;
    delete[] b;
    sort(vb.begin(), vb.end());
    long long res = 0;
    for(auto now : va) {
        res += upper_bound(vb.begin(), vb.end(), t - now) - lower_bound(vb.begin(), vb.end(), t - now);
    }
    cout << res;
}