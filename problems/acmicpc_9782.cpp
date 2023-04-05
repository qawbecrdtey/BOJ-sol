#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, t = 0; while(cin >> n) {
        if(!n) return 0;
        cout << "Case " << ++t << ": ";
        auto a = new int[n];
        for(int i = 0; i < n; i++) cin >> a[i];
        if(n & 1) cout << a[n / 2] << ".0\n";
        else cout << (a[n / 2 - 1] + a[n / 2]) / 2 << '.' << (((a[n / 2 - 1] + a[n / 2]) & 1) ? 5 : 0) << '\n';
        delete[] a;
    }
}