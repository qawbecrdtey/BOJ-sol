#include <iostream>
using namespace std;
using ll = long long;
ll combi[31][31];
ll comb(ll n, ll k) {
    if(combi[n][k]) return combi[n][k];
    if(k > n) return 0;
    if(k == n || k == 0 || n <= 1) return combi[n][k] = 1;
    return combi[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    cout << comb(m - 1, n - 1);
}