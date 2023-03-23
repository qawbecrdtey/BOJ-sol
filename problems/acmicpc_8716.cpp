#include <iostream>
using namespace std;
int main() {
    long long a[4], b[4]; for(auto &i : a) cin >> i; for(auto &i : b) cin >> i;
    long long c[4]; c[0] = max(a[0], b[0]); c[1] = min(a[1], b[1]); c[2] = min(a[2], b[2]); c[3] = max(a[3], b[3]);
    if(c[0] >= c[2] || c[1] <= c[3]) cout << 0;
    else cout << (c[2] - c[0]) * (c[1] - c[3]);
}