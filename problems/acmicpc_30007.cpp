#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; while(n--) {
        int a, b, c; cin >> a >> b >> c; cout << a * (c - 1) + b << '\n';
    }
}