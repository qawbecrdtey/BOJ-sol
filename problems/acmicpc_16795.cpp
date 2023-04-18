#include <iostream>
#include <vector>
using namespace std;
void dfs(string const *s, vector<int> *v, bool *visited, int depth, int now, int prev) {
    for(int i = 0; i < depth; i++) cout << '.';
    cout << s[now] << '\n';
    for(int next : v[now]) dfs(s, v, visited, depth + 1, next, now);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto s = new string[n + 1];
    auto v = new vector<int>[n + 1];
    for(int i = 1; i <= n; i++) {
        int x; cin >> x >> s[i];
        if(i == 1) continue;
        v[x].push_back(i);
    }
    auto visited = new bool[n + 1]();
    dfs(s, v, visited, 0, 1, 0);
}