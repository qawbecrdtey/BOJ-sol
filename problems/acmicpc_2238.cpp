#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int u, n; cin >> u >> n;
    map<int, vector<string>> m;
    for(int i = 0; i < n; i++) {
        string s; int x; cin >> s >> x;
        m[x].push_back(std::move(s));
    }
    auto v = min_element(m.begin(), m.end(), [](auto const &a, auto const &b) {
        return a.second.size() < b.second.size();
    });
    for(auto &[now, vec] : m) {
        if(v->second.size() == vec.size()) {
            cout << vec[0] << ' ' << now;
            return 0;
        }
    }
    __builtin_unreachable();
}