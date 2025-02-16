#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; while(cin >> n >> m) {
        if(!n && !m) return 0;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int x; cin >> x;
                mp[x]++;
            }
        }
        vector<pair<int, int>> v(make_move_iterator(mp.begin()), make_move_iterator(mp.end()));
        sort(v.begin(), v.end(), [](pair<int, int> const &a, pair<int, int> const &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
        cout << v[1].first;
        for(int i = 2; i < v.size() && v[i].second == v[i - 1].second; i++) {
            cout << ' ' << v[i].first;
        }
        cout << '\n';
    }
}
