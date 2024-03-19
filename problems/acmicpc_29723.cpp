#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        string s; int x; cin >> s >> x; mp[s] = x;
    }
    int res = 0;
    for(int i = 0; i < k; i++) {
        string s; cin >> s;
        auto it = mp.find(s);
        res += it->second;
        mp.erase(it);
    }
    vector<int> v;
    for(auto [s, val] : mp) {
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    m -= k;
    int res_lo = res, res_hi = res;
    for(int i = 0; i < m; i++) {
        res_lo += v[i];
        res_hi += v[v.size() - i - 1];
    }
    cout << res_lo << ' ' << res_hi;
}