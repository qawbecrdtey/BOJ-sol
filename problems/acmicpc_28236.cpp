#include <iostream>
using namespace std;
inline int d(pair<int, int> const &a, pair<int, int> const &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    int res{}, dist = 1000000009;
    pair<int, int> const dest { 1,  m + 1 };
    for(int i = 1; i <= k; i++) {
        pair<int, int> x; cin >> x.first >> x.second;
        int const dis = d(x, dest);
        if(dis < dist) {
            dist = dis;
            res = i;
        }
    } cout << res;
}