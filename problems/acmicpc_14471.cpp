#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new pair<int, int>[m];
    for(int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    } sort(a, a + m); int r{};
    for(int i = m - 1; i; i--) {
        if(a[i].first >= n) continue;
        r += n - a[i].first;
    } cout << r;
}