#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m, p; cin >> n >> m >> p;
    auto a = new int[m + 1]();
    while(n--) {
        int x, y; cin >> x >> y;
        if(a[y]) continue;
        a[y] = x;
    }
    auto visited = new bool[m + 1]();
    int cnt = 0;
    int now = p;
    while(a[now]) {
        if(visited[now]) {
            cout << -1;
            return 0;
        }
        visited[now] = true;
        now = a[now];
        cnt++;
    } cout << cnt;
}