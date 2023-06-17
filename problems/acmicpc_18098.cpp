#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n]; for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    auto p = unique(a, a + n);
    cout << (upper_bound(a, p, n) - a);
}