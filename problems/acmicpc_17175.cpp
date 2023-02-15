#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int a = 1, b = 1;
    int n; cin >> n;
    for(int i = 2; i <= n; i++) {
        int const tmp = (a + b + 1) % 1000000007;
        a = b; b = tmp;
    } cout << b;
}