#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; if(!n) { cout << 0; return 0; }
    auto a = new int[n]; for(int i = 0; i < n; i++) cin >> a[i];
    if(n == 1) { cout << a[0]; return 0; }
    sort(a, a + n);
    int cnt = n * 3 / 20 + ((n * 3) % 20 >= 10);
    int sum = 0;
    for(int i = cnt; i < n - cnt; i++) sum += a[i];
    cout << (sum / (n - cnt * 2) + (sum % (n - cnt * 2) >= (n - cnt * 2) / 2));
}