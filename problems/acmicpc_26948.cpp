#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n + 4]{}; a[1] = 1, a[2] = 2, a[3] = 4;
    for(int i = 4; i <= n; i++) a[i] = a[i - 1] + a[i - 2] + a[i - 3];
    cout << a[n];
}