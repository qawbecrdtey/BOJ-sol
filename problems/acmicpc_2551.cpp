#include <algorithm>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new ll[n];
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    ll first = a[(n - 1) / 2];
    ll mean = sum / n;
    ll mod = sum % n;
    if(mod > n / 2) mean++;
    cout << first << ' ' << mean;
}
