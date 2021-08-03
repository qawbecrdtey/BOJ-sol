#include <queue>
#include <stdio.h>
#include <utility>
using namespace std;
int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    auto a = new char*[m];
    for(int i = 0; i < m; i++) {
        a[i] = new char[n + 1];
        scanf("%s", a[i]);
    }
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        if(a[0][i] == '0') {
            q.push({ 0, i });
            while(!q.empty()) {
                auto const now = q.front(); q.pop();
                if(a[now.first][now.second] == '1') continue;
                a[now.first][now.second] = '1';
                if(now.first == m - 1) {
                    printf("YES");
                    return 0;
                }
                if(now.first && a[now.first - 1][now.second] != '1') {
                    q.push({ now.first - 1, now.second });
                }
                if(now.second && a[now.first][now.second - 1] != '1') {
                    q.push({ now.first, now.second - 1 });
                }
                if(now.first < m - 1 && a[now.first + 1][now.second] != '1') {
                    q.push({ now.first + 1, now.second });
                }
                if(now.second < n - 1 && a[now.first][now.second + 1] != '1') {
                    q.push({ now.first, now.second + 1 });
                }
            }
        }
    }
    printf("NO");
}