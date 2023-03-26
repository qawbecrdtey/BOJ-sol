#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000007;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; ll sum{}, sum2{};
    for(int i = 0; i < n; i++) {
        ll x; cin >> x; sum = (sum + x) % M; sum2 = (sum2 + x * x) % M;
    } ll const res = ((sum * sum) % M - sum2 + M) % M;
    if(res & 1) cout << ((res + M) >> 1); else cout << (res >> 1);
}