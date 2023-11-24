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
    int m = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int const d = a[j] - a[i];
            int *p = a + j + 1;
            int cnt = 2;
            while(p != a + n) {
                if(auto it = lower_bound(p, a + n, a[i] + d * cnt); it == a + n || *it != a[i] + d * cnt) break;
                else { cnt++; p = it; }
            }
            m = max(m, cnt);
        }
    }
    cout << m;
}