#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    int res = 0;
    for(int i = 2; i <= n; i++) {
        res = (res + k) % i;
    }
    cout << res + 1;
}