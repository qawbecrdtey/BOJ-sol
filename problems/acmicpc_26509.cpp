#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t; while(t--) {
        int a[6]; for(int &i : a) cin >> i;
        sort(a, a + 3); sort(a + 3, a + 6);
        if(a[0] == a[3] && a[1] == a[4] && a[2] == a[5] && a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) cout << "YES\n";
        else cout << "NO\n";
    }
}