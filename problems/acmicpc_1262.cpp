#include <iostream>
using namespace std;
inline int dist(int const x1, int const y1, int const x2, int const y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
inline char diamond(int const n, int const r, int const c) {
    if(int const d = dist(r, c, n - 1, n - 1); d >= n) return '.';
    else return static_cast<char>('a' + d % 26);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, r1, c1, r2, c2; cin >> n >> r1 >> c1 >> r2 >> c2;
    int const N = n * 2 - 1;
    for(int i = r1; i <= r2; i++) {
        for(int j = c1; j <= c2; j++) {
            cout << diamond(n, i % N, j % N);
        }
        cout << '\n';
    }
}