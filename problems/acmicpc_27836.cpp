#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, m; cin >> n >> m;
        auto a = new ll[n]; ll sumn{};
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            sumn += a[i];
        } ll avgn = (sumn - 1) / n;
        auto b = new ll[m]; ll summ{};
        for(int i = 0; i < m; i++) {
            cin >> b[i];
            summ += b[i];
        } ll avgm = summ / m;
        ll cnt{};
        for(int i = 0; i < n; i++) {
            cnt += (avgn >= a[i] && a[i] > avgm);
        } cout << cnt << '\n';
        delete[] a;
        delete[] b;
    }
}