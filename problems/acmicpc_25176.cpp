#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long n, r = 1; cin >> n; for(long long i = 1; i <= n; i++) r *= i; cout << r;
}