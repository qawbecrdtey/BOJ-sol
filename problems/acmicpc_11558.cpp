#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new int[n + 1];
        auto visited = new bool[n + 1]();
        for(int i = 1; i <= n; i++) cin >> a[i];
        int now = 1;
        int cnt = 0;
        while(!visited[now] && now != n) {
            visited[now] = true;
            cnt++;
            now = a[now];
        }
        cout << (now == n ? cnt : 0) << '\n';
        delete[] a;
        delete[] visited;
    }
}