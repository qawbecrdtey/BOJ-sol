#include <iostream>
#include <set>
#include <vector>
using namespace std;
void dfs(set<int> const *s, vector<int> &visited, int now, int &order) {
    visited[now] = ++order;
    for(auto next : s[now]) {
        if(visited[next]) continue;
        dfs(s, visited, next, order);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, r; cin >> n >> m >> r;
    auto s = new set<int>[n + 1];
    vector<int> visited(n + 1);
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        s[x].insert(y);
        s[y].insert(x);
    }
    int order = 0;
    dfs(s, visited, r, order);
    for(int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}