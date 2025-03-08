#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long n, k, d, s; cin >> n >> k >> d >> s;
    long long const x = n * d - k * s;
    cout.precision(12);
    if(x < 0 || x > 100 * (n - k)) cout << "impossible";
    else cout << fixed << static_cast<long double>(x) / (n - k);
}
