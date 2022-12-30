#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; long long res = 0;
    for(int i = 1; i * i <= n; i++) {
        res += n / i - i + 1;
    } cout << res;
}