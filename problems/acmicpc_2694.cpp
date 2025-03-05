#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        auto a = new int[n + 1]; a[0] = 0;
        int m = 0;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            m = max(a[i], m);
            a[i] += a[i - 1];
        }
        int i = 1;
        while(a[i] < m) i++;
        for(; i < n; i++) {
            if(a[n] % a[i]) continue;
            if(a[n] < (a[i] << 1)) { i = n; break; }
            int k = i;
            for(int j = (a[i] << 1); j <= a[n]; j += a[i]) {
                while(k <= n && a[k] < j) k++;
                if(a[k] != j) goto C;
            }
            break;
C:          continue;
        }
        cout << a[i] << '\n';
        delete[] a;
    }
}
