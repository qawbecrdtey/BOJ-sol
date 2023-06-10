#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto v = new vector<int>[n + 1];
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<set<int>> q;
    q.push({1});
    auto visited = new bool[n + 1]();
    while(!q.empty()) {
        int now; cin >> now;
        if(auto it = q.front().find(now); it == q.front().end()) { cout << 0; return 0; }
        else q.front().erase(it);
        if(q.front().empty()) q.pop();
        visited[now] = true;
        set<int> s;
        for(int next : v[now]) {
            if(visited[next]) continue;
            s.insert(next);
        }
        if(!s.empty()) q.push(std::move(s));
    }
    cout << 1;
}