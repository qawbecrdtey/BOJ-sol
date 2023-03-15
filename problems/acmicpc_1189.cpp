#include <iostream>
#include <string>
using namespace std;
using ll = long long;
ll path(int r, int c, string const *a, int fromx, int fromy, int tox, int toy, int depth, int maxdepth, bool **visited) {
    visited[fromx][fromy] = true;
    ll res = 0;
    if(fromx == tox && fromy == toy) {
        res += (depth == maxdepth);
        goto END;
    }
    if(depth == maxdepth) goto END;
    if(fromx && !visited[fromx - 1][fromy]) res += path(r, c, a, fromx - 1, fromy, tox, toy, depth + 1, maxdepth, visited);
    if(fromy && !visited[fromx][fromy - 1]) res += path(r, c, a, fromx, fromy - 1, tox, toy, depth + 1, maxdepth, visited);
    if(fromx < r - 1 && !visited[fromx + 1][fromy]) res += path(r, c, a, fromx + 1, fromy, tox, toy, depth + 1, maxdepth, visited);
    if(fromy < c - 1 && !visited[fromx][fromy + 1]) res += path(r, c, a, fromx, fromy + 1, tox, toy, depth + 1, maxdepth, visited);
END:visited[fromx][fromy] = false;
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int r, c, k; cin >> r >> c >> k;
    auto a = new string[r];
    auto visited = new bool*[r];
    for(int i = 0; i < r; i++) {
        cin >> a[i];
        visited[i] = new bool[c]();
        for(int j = 0; j < c; j++) {
            if(a[i][j] == 'T') visited[i][j] = true;
        }
    }
    cout << path(r, c, a, r - 1, 0, 0, c - 1, 1, k, visited);
}