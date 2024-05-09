#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = 0;
    int cur = 0;
    for(int i = 0; i < n; i++) {
        if(cur * 2 <= a[i]) {
            cur = a[i];
            res++;
        }
    }
    cout << res;
}
