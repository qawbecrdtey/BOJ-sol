#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto b = new int[n];
    for(int i = 0; i < n; i++) cin >> b[i];
    auto map = new int[n + 1];
    for(int i = 0; i < n; i++) map[a[i]] = i;
    for(int i = 0; i < n; i++) b[i] = map[b[i]];
    vector<int> v;
    auto p = new int[n]();
    for(int i = 0; i < n; i++) {
        if(v.empty() || v.back() < b[i]) {
            p[i] = v.size();
            v.push_back(b[i]);
            continue;
        }
        v[p[i] = std::lower_bound(v.begin(), v.end(), b[i]) - v.begin()] = b[i];
    }
    vector<int> res(v.size());
    int cur = v.size() - 1;
    for(int i = n - 1; i >= 0 && cur >= 0; i--) {
        if(p[i] != cur) continue;
        res[cur] = b[i];
        cur--;
    }
    cout << res.size() << '\n';
    for(auto &now : res) now = a[now];
    sort(res.begin(), res.end());
    for(auto now : res) cout << now << ' ';
}
