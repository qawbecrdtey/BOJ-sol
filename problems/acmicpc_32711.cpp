#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new ll[n];
    ll sum = 0;
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        cnt += (a[i] & 1);
    }
    if(sum & 1) { cout << 1; return 0; }
    if(cnt > 2) { cout << 1; return 0; }
    if((a[0] & 1) && (a[n - 1] & 1)) { cout << 0; return 0; }
    if(n == 1 && (a[0] & 1) == 0) { cout << 0; return 0; }
    else cout << 1;
}
