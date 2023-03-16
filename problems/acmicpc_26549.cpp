#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        auto a = new string[n];
        auto visited = new bool*[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            visited[i] = new bool[m];
            for(int j = 0; j < m; j++) visited[i][j] = (a[i][j] == '#');
        }
        int total_space = 0;
        int sections = 0;
        for(int i = 1; i < n - 1; i++) {
            for(int j = 1; j < m - 1; j++) {
                if(visited[i][j]) continue;
                sections++;
                vector<pair<int, int>> v;
                v.emplace_back(i, j);
                while(!v.empty()) {
                    auto const [nowx, nowy] = v.back(); v.pop_back();
                    if(visited[nowx][nowy]) continue;
                    visited[nowx][nowy] = true;
                    total_space++;
                    if(nowx && !visited[nowx - 1][nowy]) v.emplace_back(nowx - 1, nowy);
                    if(nowy && !visited[nowx][nowy - 1]) v.emplace_back(nowx, nowy - 1);
                    if(nowx < n && !visited[nowx + 1][nowy]) v.emplace_back(nowx + 1, nowy);
                    if(nowy < m && !visited[nowx][nowy + 1]) v.emplace_back(nowx, nowy + 1);
                }
            }
        }
        cout << sections << " section" << (sections == 1 ? "" : "s") << ", " << total_space << " space" << (total_space == 1 ? "" : "s") << '\n';
    }
}