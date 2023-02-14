#include <iostream>
using namespace std;
int fib(int n) {
    int a = 1, b = 1;
    for(int i = 3; i <= n; i++) {
        int tmp = (a + b) % 1000000007; a = b; b = tmp;
    } return b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; cout << fib(n) << ' ' << max(0, n - 2);
}