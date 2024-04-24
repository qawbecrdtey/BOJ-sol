#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int m, n; cin >> m >> n;
    map<string, int> mp;
    int idx = 0;
    while(n--) {
        string s; cin >> s; mp[std::move(s)] = idx++;
    }
    vector<pair<string, int>> v;
    v.reserve(mp.size());
    for(auto &p : mp) {
        v.emplace_back(p);
    }
    sort(v.begin(), v.end(), [](auto const &a, auto const &b) { return a.second < b.second; });
    for(int i = 0; i < m && i < v.size(); i++) {
        cout << v[i].first << '\n';
    }
}