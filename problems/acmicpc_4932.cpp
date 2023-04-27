#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        int n; cin >> n;
        auto a = new int*[n];
        for(int i = 0; i < n; i++) {
            a[i] = new int[n];
            for(int j = 0; j < n; j++) cin >> a[i][j];
        }
        cout << tt << ". ";
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < n; j++) {
                if(a[i][j] - a[i][j - 1] != a[0][j] - a[0][j - 1]) goto NO;
            }
        }
        cout << "YES\n";
        continue;
    NO: cout << "NO\n";
    }
}