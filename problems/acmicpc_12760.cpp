#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        sort(a[i], a[i] + m);
    }
    auto b = new pair<int, int>[n];
    auto c = new int[n]();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            b[j] = {a[j][i], j};
        }
        sort(b, b + n, [](auto const &a, auto const &b) {
            return a.first > b.first;
        });
        auto const u = upper_bound(b, b + n, b[0], [](auto const &a, auto const &b) {
            return a.first > b.first;
        });
        for(auto p = b; p != u; p++) {
            c[p->second]++;
        }
    }
    map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) mp[c[i]].push_back(i);
    for(auto const v : mp.rbegin()->second) {
        cout << v + 1 << ' ';
    }
}
