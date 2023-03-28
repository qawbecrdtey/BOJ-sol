#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, p; cin >> n >> p;
    int lo = n / 3, hi = (n + 1) / 3;
    if(lo < p && n - hi >= p) cout << "YES";
    else cout << "NO";
}