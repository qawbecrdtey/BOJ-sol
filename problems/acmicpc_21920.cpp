#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if(!b) return a;
    return gcd(b, a % b);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout.precision(12);
    cout << fixed;
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    int x; cin >> x;
    long long sum = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(gcd(x, a[i]) == 1) sum += a[i], cnt++;
    } cout << (long double)(sum) / cnt;
}