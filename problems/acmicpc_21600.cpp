#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int prev = 0;
    int m = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        prev = min(prev + 1, x);
        m = max(m, prev);
    }
    cout << m;
}