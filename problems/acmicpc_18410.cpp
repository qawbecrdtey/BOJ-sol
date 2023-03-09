#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto b = new int[m];
    for(int i = 0; i < m; i++) cin >> b[i];
    auto c = new int[n + m];
    merge(a, a + n, b, b + m, c);
    for(int i = 0; i < n + m; i++) cout << c[i] << '\n';
}