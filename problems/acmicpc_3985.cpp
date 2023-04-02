#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    auto a = new int[n + 1]();
    auto expected = new int[m + 1]();
    auto res = new int[m + 1]();
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        expected[i] = y - x + 1;
        for(int j = x; j <= y; j++) {
            if(!a[j]) {
                a[j] = i;
                res[i]++;
            }
        }
    }
    int resv = 0, resi = 0;
    for(int i = 1; i <= m; i++) {
        if(resv < expected[i]) resv = expected[i], resi = i;
    } cout << resi << '\n';
    resv = resi = 0;
    for(int i = 1; i <= m; i++) {
        if(resv < res[i]) resv = res[i], resi = i;
    } cout << resi;
}