#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, c; cin >> n >> c;
        cout << (n + c - 1) / c << '\n';
    }
}