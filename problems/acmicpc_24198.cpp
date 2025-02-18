#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    int a[2]{};
    int turn = 1;
    while(n) {
        a[turn] += (n + 1) / 2;
        n -= (n + 1) / 2;
        turn = 1 - turn;
    }
    cout << a[0] << ' ' << a[1];
}
