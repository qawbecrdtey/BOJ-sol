#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    auto a = new int[t]();
    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        while(n--) { int x; cin >> x; a[i] += x; }
    }
    sort(a, a + t);
    long long res = 0;
    long long sum = 0;
    for(int i = 0; i < t; i++) res += (sum += a[i]);
    cout << res;
}