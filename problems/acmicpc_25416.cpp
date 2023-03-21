#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a[5][5]; bool visited[5][5]{};
    for(auto &i : a) for(int &j : i) cin >> j;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            visited[i][j] = (a[i][j] == -1);
        }
    }
    int r, c; cin >> r >> c;
    queue<pair<int, pair<int, int>>> q; q.push({0, {r, c}});
    while(!q.empty()) {
        auto const [cnt, pos] = q.front(); q.pop();
        if(visited[pos.first][pos.second]) continue;
        visited[pos.first][pos.second] = true;
        if(a[pos.first][pos.second] == 1) {
            cout << cnt;
            return 0;
        }
        if(pos.first && !visited[pos.first - 1][pos.second]) q.push({cnt + 1, {pos.first - 1, pos.second}});
        if(pos.second && !visited[pos.first][pos.second - 1]) q.push({cnt + 1, {pos.first, pos.second - 1}});
        if(pos.first < 4 && !visited[pos.first + 1][pos.second]) q.push({cnt + 1, {pos.first + 1, pos.second}});
        if(pos.second < 4 && !visited[pos.first][pos.second + 1]) q.push({cnt + 1, {pos.first, pos.second + 1}});
    } cout << "-1";

}