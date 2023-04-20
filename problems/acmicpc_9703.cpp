#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; for(int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        int n; cin >> n;
        auto a = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    if(a[i] + a[k] == a[j] * 2) {
                        cout << "NO\n";
                        goto END;
                    }
                }
            }
        }
        cout << "YES\n";
    END: continue;
    }
}