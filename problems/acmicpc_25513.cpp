#include <iostream>
#include <memory>
#include <queue>
using namespace std;
static constexpr int n = 5;
int bfs(int const a[n][n], pair<int, int> s, pair<int, int> const &e) {
    auto const visited = make_unique<bool[]>(n * n);
    queue<pair<int, pair<int, int>>> q;
    q.emplace(0, std::move(s));
    while(!q.empty()) {
        auto const [nowdist, now] = q.front(); q.pop();
        auto const nowidx = now.first * n + now.second;
        if(visited[nowidx]) continue;
        visited[nowidx] = true;
        if(now == e) {
            return nowdist;
        }
        if(now.first && !visited[(now.first - 1) * n + now.second] && a[now.first - 1][now.second] != -1) q.push({nowdist + 1, {now.first - 1, now.second}});
        if(now.second && !visited[now.first * n + now.second - 1] && a[now.first][now.second - 1] != -1) q.push({nowdist + 1, {now.first, now.second - 1}});
        if(now.first < n - 1 && !visited[(now.first + 1) * n + now.second] && a[now.first + 1][now.second] != -1) q.push({nowdist + 1, {now.first + 1, now.second}});
        if(now.second < n - 1 && !visited[now.first * n + now.second + 1] && a[now.first][now.second + 1] != -1) q.push({nowdist + 1, {now.first, now.second + 1}});
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[n][n];
    pair<int, int> arr[7];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
            switch(a[i][j]) {
                case 1: arr[1] = {i, j}; break;
                case 2: arr[2] = {i, j}; break;
                case 3: arr[3] = {i, j}; break;
                case 4: arr[4] = {i, j}; break;
                case 5: arr[5] = {i, j}; break;
                case 6: arr[6] = {i, j}; break;
                default: break;
            }
        }
    }
    cin >> arr[0].first >> arr[0].second;
    int res = 0;
    for(int i = 1; i <= 6; i++) {
        if(int const dist = bfs(a, arr[i - 1], arr[i]); dist == -1) {
            cout << "-1";
            return 0;
        }
        else {
            res += dist;
        }
    }
    cout << res;
}
