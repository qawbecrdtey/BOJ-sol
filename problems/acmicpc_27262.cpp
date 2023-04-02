#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k, a, b; cin >> n >> k >> a >> b;
    cout << (k - 1) * b + (n - 1) * b << ' ' << (n - 1) * a;
}