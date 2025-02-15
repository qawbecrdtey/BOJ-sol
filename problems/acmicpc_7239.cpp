#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 0, r = n - 1;
    while(l <= r) {
        cout << a[l++] << ' ';
        if(l > r) break;
        cout << a[r--] << ' ';
    }
}
