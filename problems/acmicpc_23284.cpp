#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void dfs(int const n, stack<int, vector<int>> s, vector<vector<int>> &v, vector<int> cur, int const idx) {
    if(idx > n) {
        while(!s.empty()) {
            int const now = s.top();
            s.pop();
            cur.push_back(now);
        }
        v.push_back(std::move(cur));
        return;
    }
    s.push(idx);
    while(true) {
        dfs(n, s, v, cur, idx + 1);
        if(s.empty()) break;
        auto const now = s.top();
        s.pop();
        cur.push_back(now);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    stack<int, vector<int>> s;
    int n; cin >> n;
    vector<vector<int>> v;
    dfs(n, s, v, {}, 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto const &vec : v) {
        for(auto const now : vec) {
            cout << now << ' ';
        }
        cout << '\n';
    }
}
