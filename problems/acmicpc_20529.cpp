#include <iostream>
#include <string>
using namespace std;
inline int d(string const &a, string const &b) {
    return (a[0] != b[0]) + (a[1] != b[1]) + (a[2] != b[2]) + (a[3] != b[3]);
}
inline int d(string const &a, string const &b, string const &c) {
    return d(a, b) + d(b, c) + d(c, a);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new string[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        int dist = 1000000;
        if(n > 32) { cout << "0\n"; goto END; }
        for(int i = 2; i < n; i++) {
            for(int j = 1; j < i; j++) {
                for(int k = 0; k < j; k++) {
                    dist = min(dist, d(a[i], a[j], a[k]));
                }
            }
        }
        cout << dist << '\n';
    END:delete[] a;
    }
}