#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto slope = new long long[m];
    for(int i = 0; i < m; i++) cin >> slope[i];
    sort(slope, slope + m);
    auto a = new pair<int, int>[n];
    for(int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
    map<long long, long long> mp;
    long long res = 0;
    for(int i = 0; i < m; i++) {
        mp.clear();
        for(int j = 0; j < n; j++) {
            mp[a[j].second - slope[i] * a[j].first]++;
        }
        for(auto [k, v] : mp) {
            res += v * (v - 1);
        }
    }
    cout << res;
}
