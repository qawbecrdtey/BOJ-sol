#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; string s; cin >> n >> s;
    auto v = new vector<int>[n + 1];
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y; v[x].push_back(y); v[y].push_back(x);
    }
    auto visited = new bool[n + 1]{};
    ll res = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i - 1] == '0') continue;
        queue<int> q;
        visited[i] = true;
        for(int const next : v[i]) {
            ll cnt = 1;
            if(!visited[next]) q.push(next);
            while(!q.empty()) {
                int const now = q.front(); q.pop();
                if(s[now - 1] == '1') {
                    cnt++;
                    continue;
                }
                visited[now] = true;
                for(int const next_ : v[now]) {
                    if(!visited[next_]) q.push(next_);
                }
            }
            res += cnt * (cnt - 1);
        }
    } cout << res;
}