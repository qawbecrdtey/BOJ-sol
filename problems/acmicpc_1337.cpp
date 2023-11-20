#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int m = 5;
    for(int i = 0; i < n; i++) {
        int cnt = 4;
        for(int j = 1; j < 5; j++) {
            cnt -= binary_search(a + i, a + n, a[i] + j);
        }
        m = min(m, cnt);
    } cout << m;
}