#include <iostream>
using namespace std;
inline int dist(pair<int, int> const *a, int i, int j) {
    return abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
}
void print(pair<int, int>** from, pair<int, int> p) {
    if(from[p.first][p.second] == make_pair(0, 1)) {
        cout << '\n' << (p.second != 1) + 1;
        return;
    }
    print(from, from[p.first][p.second]);
    cout << '\n' << (p.second != from[p.first][p.second].second)  + 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, w; cin >> n >> w;
    auto a = new pair<int, int>[w + 2];
    auto dp = new int*[w + 2];
    auto from = new pair<int, int>*[w + 2]();
    a[0] = { 1, 1 }; a[1] = { n, n };
    for(int i = 0; i < w + 2; i++) {
        dp[i] = new int[w + 2];
        from[i] = new pair<int, int>[w + 2]();
        fill(dp[i], dp[i] + w + 2, 1234567891);
    } dp[0][1] = 0; dp[2][1] = dist(a, 0, 2);
    for(int i = 2; i < w + 2; i++) {
        cin >> a[i].first >> a[i].second;
        dp[0][i] = dp[0][i - 1] + dist(a, i - 1, i);
        dp[i][i - 1] = dp[0][i - 1] + dist(a, 0, i);
        from[0][i] = { 0, i - 1 };
        from[i][i - 1] = { 0, i - 1 };
    }
    for(int i = 3; i < w + 2; i++) {
        dp[i][1] = dp[i - 1][1] + dist(a, i - 1, i);
        dp[i - 1][i] = dp[i - 1][1] + dist(a, 1, i);
        from[i][1] = { i - 1, 1 };
        from[i - 1][i] = { i - 1, 1 };
    }
    for(int i = 2; i < w + 2; i++) {
        for(int j = 2; j < w + 2; j++) {
            if(i == j) continue;
            int const next = max(i, j) + 1;
            if(next == w + 2) break;
            if(int const d = dist(a, j, next); dp[i][next] > dp[i][j] + d) {
                dp[i][next] = dp[i][j] + d;
                from[i][next] = { i, j };
            }
            if(int const d = dist(a, i, next); dp[next][j] > dp[i][j] + d) {
                dp[next][j] = dp[i][j] + d;
                from[next][j] = { i, j };
            }
        }
    } int res = 1234567891;
    pair<int, int> res_p;
    for(int i = 0; i < w + 2; i++) {
        if(res > dp[i][w + 1]) {
            res = dp[i][w + 1];
            res_p = { i, w + 1 };
        }
        if(res > dp[w + 1][i]) {
            res = dp[w + 1][i];
            res_p = { w + 1, i };
        }
    } cout << res;
    print(from, res_p);
}