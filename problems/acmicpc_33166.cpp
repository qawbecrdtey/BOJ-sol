#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int p, q, a, b; cin >> p >> q >> a >> b;
    if(q < p) cout << q * a;
    else cout << p * a + b * (q - p);
}
