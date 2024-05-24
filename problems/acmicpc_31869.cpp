#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
struct info {
    int w, d, p;
    bool operator<(info const &i) const noexcept {
        return to_int() < i.to_int();
    }
    int to_int() const noexcept { return w * 7 + d; }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    map<string, info> m;
    for(int i = 0; i < n; i++) {
        string name; int w, d, p;
        cin >> name >> w >> d >> p;
        m[std::move(name)] = info{w, d, p};
    }
    for(int i = 0; i < n; i++) {
        string name; int p;
        cin >> name >> p;
        if(auto it = m.find(name); it == m.end() || it->second.p > p) {
            m.erase(it);
        }
    }
    vector<int> v;
    for(auto const &[key, val] : m) {
        v.push_back(val.to_int());
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> res;
    int start = 0;
    for(int i = 1; i < v.size(); i++) {
        if(v[i - 1] + 1 != v[i]) {
            res.push_back(i - start);
            start = i;
        }
    }
    if(start != v.size()) {
        res.push_back(v.size() - start);
    }
    if(res.empty()) cout << 0;
    else cout << *max_element(res.begin(), res.end());
}
