#include <cmath>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long b, c; cin >> b >> c;
    cout.precision(15);
    cout << fixed << (b + sqrtl(b * b + 4 * c)) / 2;
}