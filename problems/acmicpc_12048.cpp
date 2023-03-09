#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ":\n";
        int n, q; cin >> n >> q;
        auto a = new int[n + 1]; a[0] = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        vector<long long> v{0};
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                v.push_back(a[j] - a[i]);
            }
        }
        delete[] a;
        sort(v.begin(), v.end());
        for(int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }
        while(q--) {
            int x, y; cin >> x >> y;
            cout << v[y] - v[x - 1] << '\n';
        }
    }
}