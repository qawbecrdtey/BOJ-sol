#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
std::size_t lis(int n, int const *a) {
    std::size_t res = 0;
    vector<int> v;
    for(int i = 0; i < n; i++, res += v.size()) {
        if(v.empty() || v.back() < a[i]) {
            v.push_back(a[i]);
            continue;
        }
        *lower_bound(v.begin(), v.end(), a[i]) = a[i];
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n; cin >> n;
        auto const a = new int[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        std::size_t res = 0;
        for(int i = 1; i <= n; i++) {
            res += lis(n - i + 1, a + i - 1);
        }
        cout << res << '\n';
        delete[] a;
    }
}