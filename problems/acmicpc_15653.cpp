#include <array>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <utility>
using namespace std;
inline constexpr array<pair<int, int>, 4> dir {{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} }};
inline bool impossible_placement(string const *const board, int const n, int const m, pair<int, int> const pos, pair<int, int> const obs) {
    return board[pos.first][pos.second] == '#' || pos == obs;
}
inline bool is_hole(string const *const board, pair<int, int> pos) {
    return board[pos.first][pos.second] == 'O';
}
pair<pair<int, int>, bool> roll(string const *const board, int const n, int const m, pair<int, int> const cur, pair<int, int> const obs, pair<int, int> const d) {
    auto next = make_pair(cur.first + d.first, cur.second + d.second);
    if(impossible_placement(board, n, m, next, obs)) return { cur, false };
    if(is_hole(board, next)) return { { -1, -1 }, true };
    return roll(board, n, m, next, obs, d);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new string[n];
    pair<int, int> r_pos, b_pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(int j = 0; j < m; j++) {
            if(a[i][j] == 'R') { r_pos = { i, j }; a[i][j] = '.'; }
            else if(a[i][j] == 'B') { b_pos = { i, j }; a[i][j] = '.'; }
        }
    }
    auto visited = new bool***[n];
    for(int i = 0; i < n; i++) {
        visited[i] = new bool**[m];
        for(int j = 0; j < m; j++) {
            visited[i][j] = new bool*[n];
            for(int k = 0; k < n; k++) {
                visited[i][j][k] = new bool[m]();
            }
        }
    }
    queue<tuple<pair<int, int>, pair<int, int>, int>> q;
    q.emplace(r_pos, b_pos, 0);
    while(!q.empty()) {
        auto [r_now, b_now, cnt_now] = q.front(); q.pop();
        if(visited[r_now.first][r_now.second][b_now.first][b_now.second]) continue;
        visited[r_now.first][r_now.second][b_now.first][b_now.second] = true;
        for(auto d : dir) {
            auto [r_next, r_out] = roll(a, n, m, r_now, b_now, d);
            auto [b_next, b_out] = roll(a, n, m, b_now, r_next, d);
            if(!r_out) {
                tie(r_next, r_out) = roll(a, n, m, r_next, b_next, d);
            }
            if(b_out) continue;
            if(r_out) {
                cout << cnt_now + 1;
                return 0;
            }
            if(!visited[r_next.first][r_next.second][b_next.first][b_next.second]) {
                q.emplace(r_next, b_next, cnt_now + 1);
            }
        }
    }
    cout << -1;
}