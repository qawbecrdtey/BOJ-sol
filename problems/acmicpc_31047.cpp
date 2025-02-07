#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        map<string, int> m;
        for(int i = 0; i < n; i++) {
            string s; int k; cin >> s >> k;
            m[std::move(s)] += k;
        }
        auto const sz = m.size();
        auto a = new pair<string, int>[sz];
        copy(make_move_iterator(m.begin()), make_move_iterator(m.end()), a);
        cout << sz << '\n';
        sort(a, a + sz, [](pair<string, int> const &a, pair<string, int> const &b) {
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        });
        for(int i = 0; i < sz; i++) {
            cout << a[i].first << ' ' << a[i].second << '\n';
        }
        delete[] a;
    }
}
