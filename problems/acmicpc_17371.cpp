#include <cmath>
#include <iostream>
#include <limits>
using namespace std;
inline int sq(int n) { return n * n; }
inline int d2(pair<int, int> const &a, pair<int, int> const &b) {
    return sq(a.first - b.first) + sq(a.second - b.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    auto res2 = numeric_limits<int>::max();
    pair<int, int> res;
    for(int i = 0; i < n; i++) {
        int dist2 = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            dist2 = max(dist2, d2(a[i], a[j]));
        }
        if(res2 > dist2) {
            res2 = dist2;
            res = a[i];
        }
    }
    cout << res.first << ' ' << res.second;
}