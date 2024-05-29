#include <iostream>
using namespace std;
bool all_equal(int const *a, int n) {
    for(int i = 1; i < n; i++) {
        if(a[i] != a[0]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int tt = 0;
    int n; while(cin >> n) {
        if(!n) return 0;
        cout << "Case " << ++tt << ": ";
        auto a = new int[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int res = 0;
        auto b = new int[n];
        while(!all_equal(a, n) && res++ < 1000) {
            for(int i = 0; i < n; i++) {
                b[i] = abs(a[i] - a[(i + 1) % n]);
            }
            copy(b, b + n, a);
        }
        delete[] b;
        if(res >= 1000) {
            cout << "not attained\n";
        }
        else {
            cout << res << " iterations\n";
        }
        delete[] a;
    }
}
