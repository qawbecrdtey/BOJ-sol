#include <iostream>
#include <queue>
#include <string>
using namespace std;
string calc(int n) {
    auto visited = new bool[n]();
    string res;
    queue<pair<int, string>> q;
    q.emplace(1 % n, "1");
    while(!q.empty()) {
        auto [now, str] = q.front(); q.pop();
        if(visited[now]) continue;
        visited[now] = true;
        if(!now) {
            res = std::move(str);
            break;
        }
        if(!visited[(now * 10) % n]) q.emplace((now * 10) % n, str + '0');
        if(!visited[((now * 10) | 1) % n]) q.emplace(((now * 10) | 1) % n, str + '1');
    }
    delete[] visited;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; while(cin >> n) {
        if(!n) return 0;
        cout << calc(n) << '\n';
    }
}