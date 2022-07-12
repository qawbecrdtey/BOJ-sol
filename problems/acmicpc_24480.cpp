#include <iostream>
#include <set>
#include <vector>
using namespace std;
void dfs(set<int, greater<>> const *s, vector<int> &visited, int now, int &cnt) {
    visited[now] = cnt++;
    for(auto next : s[now]) {
        if(visited[next]) continue;
        dfs(s, visited, next, cnt);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    auto s = new set<int, greater<>>[n + 1];
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        s[x].insert(y);
        s[y].insert(x);
    }
    vector<int> visited(n + 1);
    int cnt = 1;
    dfs(s, visited, k, cnt);
    for(int i = 1; i <= n; i++) {
        cout << visited[i] << '\n';
    }
}