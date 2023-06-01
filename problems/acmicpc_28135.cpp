#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int res = 0;
    for(int i = 0; i < n; i++) {
        res += 1 + [](int n) -> bool { while(n > 10) { if(n % 100 == 50) return true; n /= 10; } return false; }(i);
    } cout << res;
}