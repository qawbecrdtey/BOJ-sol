#include <iostream>
using namespace std;
using ll = long long;
static constexpr ll M = 1000000009;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    auto a = new ll[100001]; a[0] = 1; a[1] = 1;
    for(int i = 2; i <= 100000; i++) a[i] = (a[i - 1] + a[i - 2]) % M;
    auto b = new ll[100001]; b[0] = 1; b[1] = 1; b[2] = 2; b[3] = 4;
    for(int i = 4; i <= 100000; i++) b[i] = (b[i - 1] + b[i - 2] + b[i - 3] + b[i - 4]) % M;
    int t; cin >> t; while(t--) {
        int n; cin >> n; cout << (a[n] * b[n]) % M << '\n';
    }
}