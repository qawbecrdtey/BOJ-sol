#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto const a = new string[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int idx = 0;
    pair<int, int> p[2];
    for(int i = 0; i < n - 1; i++) {
        if(idx == 2) break;
        if(a[i][0] == '.') p[idx++] = { i, 0 };
        if(a[n - i - 1][m - 1] == '.') p[idx++] = { n - i - 1, m - 1 };
    }
    for(int i = 0; i < m - 1; i++) {
        if(a[n - 1][i] == '.') p[idx++] = { n - 1, i };
        if(a[0][m - i - 1] == '.') p[idx++] = { 0, m - i - 1 };
    }
    auto const visited = new pair<int, int>*[n];
    for(int i = 0; i < n; i++) {
        visited[i] = new pair<int, int>[m];
        fill_n(visited[i], m, make_pair(-1, -1));
    }
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({ { -2, -2 }, p[0] });
    while(!q.empty()) {
        auto const [prev, now] = q.front(); q.pop();
        if(visited[now.first][now.second] != make_pair(-1, -1)) continue;
        visited[now.first][now.second] = prev;
        if(now == p[1]) break;
        if(now.first && visited[now.first - 1][now.second] == make_pair(-1, -1) && a[now.first - 1][now.second] != '+') {
            q.push({ now, {now.first - 1, now.second } });
        }
        if(now.second && visited[now.first][now.second - 1] == make_pair(-1, -1) && a[now.first][now.second - 1] != '+') {
            q.push({ now, { now.first, now.second - 1 } });
        }
        if(now.first < n - 1 && visited[now.first + 1][now.second] == make_pair(-1, -1) && a[now.first + 1][now.second] != '+') {
            q.push({ now, { now.first + 1, now.second } });
        }
        if(now.second < m - 1 && visited[now.first][now.second + 1] == make_pair(-1, -1) && a[now.first][now.second + 1] != '+') {
            q.push({ now, { now.first, now.second + 1 } });
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == '.') a[i][j] = '@';
        }
    }
    auto now = p[1];
    while(now != make_pair(-2, -2)) {
        a[now.first][now.second] = '.';
        now = visited[now.first][now.second];
    }
    for(int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
}