#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto v = new vector<int>[n + 1];
    auto u = new vector<int>[n + 1];
    auto deg = new int[n + 1]();
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        u[y].push_back(x);
        deg[y]++;
    }
    vector<int> s;
    for(int i = 1; i <= n; i++) {
        if(!deg[i]) s.push_back(i);
    }
    vector<int> top_sort(1);
    while(!s.empty()) {
        auto const now = s.back(); s.pop_back();
        top_sort.push_back(now);
        for(auto const next : v[now]) {
            if(!--deg[next]) s.push_back(next);
        }
    }
    auto inv = new int[n + 1];
    for(int i = 1; i <= n; i++) {
        inv[top_sort[i]] = i;
    }
    auto range = new int[n + 1]();
    for(int i = 1; i <= n; i++) {
        int idx = 0;
        for(auto const next : u[i]) {
            if(idx < inv[next]) idx = inv[next];
        }
        if(idx + 1 < inv[i]) {
            range[idx + 1]++;
            range[inv[i]]--;
        }
        idx = n + 1;
        for(auto const next : v[i]) {
            if(idx > inv[next]) idx = inv[next];
        }
        if(inv[i] + 1 < idx) {
            range[inv[i] + 1]++;
            range[idx]--;
        }
    }
    vector<int> res;
    for(int i = 1; i <= n; i++) {
        range[i] += range[i - 1];
        if(!range[i]) {
            res.push_back(top_sort[i]);
        }
    }
    cout << res.size();
    if(res.empty()) return 0;
    sort(res.begin(), res.end());
    cout << '\n';
    for(auto const now : res) {
        cout << now << ' ';
    }
}