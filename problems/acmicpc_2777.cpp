#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int n; cin >> n;
        if(n == 1) {
            cout << "1\n";
            continue;
        }
        int a[4]{};
        for(auto [i, idx] : {make_pair(2, 0), make_pair(3, 1), make_pair(5, 2), make_pair(7, 3)}) {
            while(!(n % i)) {
                n /= i;
                a[idx]++;
            }
        }
        if(n != 1) {
            cout << "-1\n";
            continue;
        }
        int res = a[2] + a[3];
        res += a[0] / 3; a[0] %= 3;
        res += a[0] / 2; a[0] %= 2;
        res += a[1] / 2; a[1] %= 2;
        res += max(a[0], a[1]);
        cout << res << '\n';
    }
}
