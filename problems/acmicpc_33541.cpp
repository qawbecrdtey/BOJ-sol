#include <iostream>
using namespace std;
bool is_special(int n) {
    int const a = n / 100;
    int const b = n % 100;
    return (a + b) * (a + b) == n;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int x; cin >> x;
    for(int i = x + 1; i < 10000; i++) {
        if(is_special(i)) { cout << i; return 0; }
    }
    cout << -1;
}
