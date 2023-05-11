#include <iostream>
#include <limits>
using namespace std;
int dist(int **a, int n, int m, int r, int c) {
    int res = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res += (abs(r - i) + abs(c - j)) * a[i][j];
        }
    } return res;
}
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
    int res = numeric_limits<int>::max();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res = min(res, dist(a, n, m, i, j));
        }
    } cout << res;
}