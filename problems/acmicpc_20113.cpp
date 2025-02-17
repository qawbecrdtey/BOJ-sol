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
        int x; cin >> x; if(!x) continue;
        m[x]++;
    }
    vector<pair<int, int>> v{make_move_iterator(m.begin()), make_move_iterator(m.end())};
    if(v.empty()) goto NO;
    sort(v.begin(), v.end(), [](pair<int, int> const &a, pair<int, int> const &b) {
        return a.second > b.second;
    });
    if(v[0].second == v[1].second) goto NO;
    cout << v[0].first;
    return 0;
NO: cout << "skipped";
}
