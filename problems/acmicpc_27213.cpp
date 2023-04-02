#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long m, n; cin >> m >> n;
    if(m == 1 || n == 1) cout << m * n;
    else cout << (m * n - (m - 2) * (n - 2));
}