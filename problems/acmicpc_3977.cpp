#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void dfs1(vector<int> const *v, bool *visited, int now, stack<int> &s) {
    if(visited[now]) return;
    visited[now] = true;
    for(auto next : v[now]) dfs1(v, visited, next, s);
    s.push(now);
}
void dfs2(vector<int> const *v, bool *visited, int now, vector<int> &s) {
    if(visited[now]) return;
    visited[now] = true;
    for(auto next : v[now]) dfs2(v, visited, next, s);
    s.push_back(now);
}
void dfs(vector<int> const *v, bool *visited, int now) {
    if(visited[now]) return;
    visited[now] = true;
    for(auto next : v[now]) dfs(v, visited, next);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        auto v1 = new vector<int>[n];
        auto v2 = new vector<int>[n];
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            v1[a].push_back(b);
            v2[b].push_back(a);
        }
        auto visited = new bool[n]();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) dfs1(v1, visited, i, s);
        }
        fill(visited, visited + n, false);
        vector<int> last_v;
        int cnt = 0;
        while(!s.empty()) {
            auto const now = s.top(); s.pop();
            if(visited[now]) continue;
            cnt++;
            vector<int> v;
            dfs2(v2, visited, now, v);
            last_v = std::move(v);
            break;
        }
        fill(visited, visited + n, false);
        dfs(v1, visited, last_v[0]);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                goto NO;
            }
        }
        sort(last_v.begin(), last_v.end());
        for(auto now : last_v) {
            cout << now << '\n';
        } cout << '\n';
        goto END;
    NO: cout << "Confused\n\n";
    END:delete[] visited;
        delete[] v1;
        delete[] v2;
    }
}