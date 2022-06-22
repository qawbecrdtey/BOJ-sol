#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    long long x = 1; while(n--) {
        long long y; cin >> y;
        x = (x * y) % m;
    } cout << x;
}