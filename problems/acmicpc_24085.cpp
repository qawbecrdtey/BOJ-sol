#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<int, int> m;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; m[x]++;
    }
    vector<pair<int, int>> v{make_move_iterator(m.begin()), make_move_iterator(m.end())};
    sort(v.begin(), v.end(), [](pair<int, int> const &a, pair<int, int> const &b) {
        return a.second < b.second || (a.second == b.second && a.first < b.first);
    });
    cout << v[0].first;
}
