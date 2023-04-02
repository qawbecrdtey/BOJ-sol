#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; while(n % 10 == 0) n /= 10; int cnt = 0;
    while(n) { cnt += (n % 10 == 0); n /= 10; } cout << cnt;
}