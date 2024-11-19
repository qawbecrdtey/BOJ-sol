#include <iostream>
#include <string>
using namespace std;
static int sqrt(int n) {
    int l = 0, r = n + 1;
    while(l < r) {
        int const m = (l + r) >> 1;
        if(m * m == n) return m;
        if(m * m < n) l = m + 1;
        else r = m;
    }
    return l;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        string s; cin >> s;
        int const n = sqrt(static_cast<int>(s.size()));
        int idx = 0;
        auto a = new char*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new char[n];
            for(int j = 0; j < n; j++) {
                a[i][j] = s[idx];
                idx++;
            }
        }
        for(int j = n - 1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                cout << a[i][j];
            }
        }
        cout << '\n';
        for(int i = 0; i < n; i++) delete[] a[i];
        delete[] a;
    }
}
