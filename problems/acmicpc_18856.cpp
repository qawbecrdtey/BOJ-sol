#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; cout << n << '\n';
    for(int i = 1; i < n; i++) cout << i << ' ';
    for(int i = n; i < 1000; i++) if([](int n) { for(int i = 2; i * i <= n; i++) if(n % i == 0) return false; return true; }(i)) { cout << i; return 0; }
}