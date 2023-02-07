#include <iostream>
#include <stack>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        stack<pair<ll, int>> s;
        auto a = new ll[n + 1]; a[0] = 10001;
        s.emplace(10001, 0);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            while(s.top().first <= a[i]) {
                s.pop();
            } s.emplace(a[i], i);
        } ll res = 0;
        while(s.size() > 1) {
            auto const [now, nowidx] = s.top(); s.pop();
            for(int i = s.top().second + 1; i < nowidx; i++) {
                res += now - a[i];
            }
        } cout << res << '\n';
        delete[] a;
    }
}