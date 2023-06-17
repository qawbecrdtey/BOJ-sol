#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n, s; cin >> n >> s;
        auto a = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int v = *max_element(a, a + n);
        cout << (v * s + 999) / 1000 << '\n';
        delete[] a;
    }
}