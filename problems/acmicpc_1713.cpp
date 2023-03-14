#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<pair<int, pair<int, int>>> v;
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        int j;
        if(v.empty()) {
            v.push_back({x, {1, i}});
            continue;
        }
        for(j = 0; j < v.size(); j++) {
            if(v[j].first == x) break;
        }
        if(j != v.size()) {
            v[j].second.first++;
        }
        else {
            if(v.size() != n) {
                v.push_back({x, {1, i}});
                continue;
            }
            auto it = min_element(v.begin(), v.end(), [](pair<int, pair<int, int>> const &a, pair<int, pair<int, int>> const &b) {
                return a.second.first < b.second.first || (a.second.first == b.second.first && a.second.second < b.second.second);
            });
            it->first = x;
            it->second.first = 1;
            it->second.second = i;
        }
    }
    sort(v.begin(), v.end(), [](pair<int, pair<int, int>> const &a, pair<int, pair<int, int>> const &b) {
        return a.first < b.first;
    });
    for(auto [now, _] : v) cout << now << ' ';
}