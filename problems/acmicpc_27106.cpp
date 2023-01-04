#include <iostream>
using namespace std;
static constexpr int money[] = { 25, 10, 5, 1 };
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; n = 100 - n;
    for(int x : money) {
        cout << n / x << ' ';
        n %= x;
    }
}