#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int res = min(n, m); n -= res; m -= res; res *= 10;
    if(!n) goto END;
    res += 10 * (n / 3); n -= (n / 3) * 3;
    res += 3 * (n / 2); n -= (n / 2) * 2;
    res += n;
END:cout << res;
}
