#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> passed(vector<int> const *v, int const s, int const e, int const prev) {
    if(s == e) return {e};
    for(auto const next : v[s]) {
        if(next == prev) continue;
        auto res = passed(v, next, e, s);
        if(res.empty()) continue;
        res.push_back(s);
        return res;
    }
    return {};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, s, e; cin >> n >> s >> e;
    auto v = new vector<int>[n + 1];
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    auto pass = passed(v, s, e, -1);
    reverse(pass.begin(), pass.end());
    for(int i = 0; i < pass.size() - 1; i++) {
        if(i & 1) {
            if(v[pass[i]].size() > 2) {
                cout << "Second";
                return 0;
            }
        }
        else {

        }
    }
    cout << "First";
}