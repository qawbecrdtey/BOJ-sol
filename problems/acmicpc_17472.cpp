#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
inline pair<int**, int> color(int n, int m, int **a) {
    auto color_arr = new int*[n];
    for(int i = 0; i < n; i++) {
        color_arr[i] = new int[m];
        fill(color_arr[i], color_arr[i] + m, 0);
    }
    int last_color = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!color_arr[i][j] && a[i][j]) {
                last_color++;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while(!q.empty()) {
                    auto [nowx, nowy] = q.front(); q.pop();
                    if(color_arr[nowx][nowy]) continue;
                    color_arr[nowx][nowy] = last_color;
                    if(nowx && a[nowx - 1][nowy] && !color_arr[nowx - 1][nowy]) q.emplace(nowx - 1, nowy);
                    if(nowy && a[nowx][nowy - 1] && !color_arr[nowx][nowy - 1]) q.emplace(nowx, nowy - 1);
                    if(nowx < n - 1 && a[nowx + 1][nowy] && !color_arr[nowx + 1][nowy]) q.emplace(nowx + 1, nowy);
                    if(nowy < m - 1 && a[nowx][nowy + 1] && !color_arr[nowx][nowy + 1]) q.emplace(nowx, nowy + 1);
                }
            }
        }
    }
    return { color_arr, last_color };
}
struct uf {
    int n;
    int *const root;
    uf(int n) : n(n), root(new int[n]) { for(int i = 0; i < n; i++) root[i] = i; }
    int find(int a) {
        if(a == root[a]) return a;
        return root[a] = find(root[a]);
    }
    bool merge(int a, int b) {
        int x = find(a);
        int y = find(b);
        if(x == y) return false;
        root[x] = y;
        return true;
    }
    bool check(int a, int b) { return find(a) == find(b); }
};
struct datas {
    int color1;
    int color2;
    int dist;
    bool operator<(datas const &d) const { return dist < d.dist; }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int*[n];
    for(int i = 0; i < n; i++) {
        a[i] = new int[m];
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    auto [color_arr, color_idx] = color(n, m, a);
    vector<datas> v;
    for(int i = 0; i < n; i++) {
        int j = 0;
        while(j < m) {
            if(!(j < m - 1 && color_arr[i][j] && !color_arr[i][j + 1])) { j++; continue; }
            int const start = j++;
            while(j < m && !color_arr[i][j]) j++;
            if(j == m || color_arr[i][j] == color_arr[i][start] || j - start < 3) continue;
            v.push_back({color_arr[i][j], color_arr[i][start], j - start - 1});
        }
    }
    for(int j = 0; j < m; j++) {
        int i = 0;
        while(i < n) {
            if(!(i < n - 1 && color_arr[i][j] && !color_arr[i + 1][j])) { i++; continue; }
            int const start = i++;
            while(i < n && !color_arr[i][j]) i++;
            if(i == n || color_arr[i][j] == color_arr[start][j] || i - start < 3) continue;
           v.push_back({color_arr[i][j], color_arr[start][j], i - start - 1});
        }
    }
    sort(v.begin(), v.end());
    uf u(color_idx + 1);
    int res = 0;
    for(auto [color1, color2, dist] : v) {
        if(u.merge(color1, color2)) res += dist;
    }
    for(int i = 2; i <= color_idx; i++) {
        if(u.check(1, i)) continue;
        cout << -1;
        return 0;
    }
    cout << res;
}