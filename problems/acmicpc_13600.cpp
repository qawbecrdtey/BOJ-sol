#include <algorithm>
#include <iostream>
using namespace std;
static constexpr int fact[] {1, 2, 6, 24, 120, 720, 5040, 40320, 362800};
int main() {
    int n; cin >> n;
    int cnt = 0;
    while(n) {
        n = n - fact[((upper_bound(fact, fact + 9, n) - 1) - fact)];
        cnt++;
    } cout << cnt;
}