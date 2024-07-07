#include <iostream>
using namespace std;
int compute_grundy(int const *a, int n) {
    for(int i = 0; i < n; i++) {
        if(!a[i]) continue;
        return a[i] - (a[i] <= compute_grundy(a + i + 1, n - i - 1));
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[m];
    int g = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[j];
        }
        g ^= compute_grundy(a, m);
    }
    cout << (g ? "koosaga" : "cubelover");
}
