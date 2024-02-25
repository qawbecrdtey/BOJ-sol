#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
struct info {
    int to;
    int ignored;
    long long cost;
    [[nodiscard]] bool operator()(info const &a, info const &b) {
        return a.cost > b.cost || (a.cost == b.cost && a.ignored > b.ignored);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, p, k; cin >> n >> p >> k;
    auto v = new vector<pair<int, int>>[n + 1];
    for(int i = 0; i < p; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    auto visited = new bool*[n + 1]; // [idx][#ignored]
    for(int i = 1; i <= n; i++) {
        visited[i] = new bool[k + 1]();
    }
    fill(visited[1] + 1, visited[1] + k + 1, true);
    priority_queue<info, vector<info>, info> pq;
    pq.push(info{1, 0, 0});
    auto result = new long long[k + 1];
    fill(result, result + k + 1, -1);
    while(!pq.empty()) {
        auto const [now_to, now_ignored, now_cost] = pq.top(); pq.pop();
        if(visited[now_to][now_ignored]) continue;
        visited[now_to][now_ignored] = true;
        if(now_to == n) {
            result[now_ignored] = now_cost;
        }
        for(auto const [next_to, next_cost] : v[now_to]) {
            if(!visited[next_to][now_ignored]) {
                pq.push({next_to, now_ignored, max<long long>(now_cost, next_cost)});
            }
            if(now_ignored < k && !visited[next_to][now_ignored + 1]) {
                pq.push({next_to, now_ignored + 1, now_cost});
            }
        }
    }
    cout << *min_element(result, result + k + 1);
}