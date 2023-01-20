#include <algorithm>
#include <iostream>
using namespace std;
struct info {
    int t, s, d;
    bool operator<(info const &i) const { return t < i.t; }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; while(cin >> n >> m) {
        if(!n && !m) return 0;
        auto a = new info[m];
        for(int i = 0; i < m; i++) {
            cin >> a[i].t >> a[i].s >> a[i].d;
        } sort(a, a + m);
        auto infected = new bool[n + 1](); infected[1] = true;
        for(int i = 0; i < m; i++) {
            if(infected[a[i].s]) infected[a[i].d] = true;
        } int sum = 0;
        for(int i = 1; i <= n; i++) {
            sum += infected[i];
        } cout << sum << '\n';
        delete[] infected;
        delete[] a;
    }
}