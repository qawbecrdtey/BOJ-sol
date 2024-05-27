#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
inline int sq(int x) { return x * x; }
inline int d2(pair<int, int> const &a) { return sq(a.first) + sq(a.second); }
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    vector<pair<int, int>> v;
    for(int w = 1; w <= 150; w++) {
        for(int h = 1; h < w; h++) {
            v.emplace_back(w, h);
        }
    }
    auto const comp = [](auto const &a, auto const &b) {
        return d2(a) < d2(b) || (d2(a) == d2(b) && a.second < b.second);
    };
    sort(v.begin(), v.end(), comp);
    pair<int, int> p;
    while(cin >> p.second >> p.first) {
        if(!p.first && !p.second) return 0;
        auto it = upper_bound(v.begin(), v.end(), p, comp);
        cout << it->second << ' ' << it->first << '\n';
    }
}
