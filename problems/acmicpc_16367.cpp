#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
inline int index(int x) {
    if(x > 0) return x * 2;
    return index(-x) - 1;
}
inline int negative(int x) {
    if(x & 1) return x + 1;
    return x - 1;
}
void dfs1(vector<int> const *v, stack<int> &s, bool *visited, int now) {
    visited[now] = true;
    for(auto next : v[now]) {
        if(!visited[next]) dfs1(v, s, visited, next);
    }
    s.push(now);
}
void dfs2(vector<int> const *u, vector<int> &scv, bool *visited, int now) {
    visited[now] = true;
    for(auto next : u[now]) {
        if(!visited[next]) dfs2(u, scv, visited, next);
    }
    scv.push_back(now);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, n;
    cin >> k >> n;
    auto v = new vector<int>[k * 2 + 1];
    auto u = new vector<int>[k * 2 + 1];
    while(n--) {
        int x[3]; string s[3];
        for(int i = 0; i < 3; i++) {
            cin >> x[i] >> s[i];
            if(s[i][0] == 'B') x[i] = -x[i];
        }
        for(int i = 1; i < 3; i++) {
            for(int j = 0; j < i; j++) {
                v[index(-x[i])].push_back(index(x[j]));
                v[index(-x[j])].push_back(index(x[i]));
                u[index(x[i])].push_back(index(-x[j]));
                u[index(x[j])].push_back(index(-x[i]));
            }
        }
    }
    auto visited = new bool[k * 2 + 1]();
    stack<int> s;
    for(int i = 1; i <= k * 2; i++) {
        if(!visited[i]) dfs1(v, s, visited, i);
    }
    fill(visited, visited + k * 2 + 1, false);
    int cnt = 1;
    auto value = new int[k * 2 + 1]();
    vector<vector<int>> scc;
    while(!s.empty()) {
        auto const now = s.top(); s.pop();
        if(visited[now]) continue;
        vector<int> scv;
        dfs2(u, scv, visited, now);
        for(auto val : scv) {
            value[val] = cnt;
        } cnt++;
        scc.emplace_back(move(scv));
    }
    for(int i = 1; i <= k; i++) {
        if(value[i * 2 - 1] == value[i * 2]) {
            cout << -1;
            return 0;
        }
    }
    auto res = new int[k * 2 + 1]();
    for(auto const &scv : scc) {
        for(auto val : scv) {
            if(res[val]) {
                for(auto val1 : scv) {
                    res[val1] = 1;
                    res[negative(val1)] = 0;
                }
                break;
            }
            res[negative(val)] = 1;
        }
    }
    for(int i = 1; i <= k; i++) {
        cout << (res[i * 2] ? 'R' : 'B');
    }
}