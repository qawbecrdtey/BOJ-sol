#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; int a[3]{};
    while(n--) { int x; cin >> x; a[x % 3]++; }
    a[1] -= a[2]; a[0] -= a[2];
    cout << a[1] << ' ' << a[0];
}