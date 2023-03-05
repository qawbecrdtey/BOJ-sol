#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        long long a, b; cin >> a >> b; a += b;
        cout << (a * a * (a - 1)) / 2 << '\n';
    }
}