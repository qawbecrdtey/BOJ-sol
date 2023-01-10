#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, a, b, c; cin >> n >> a >> b >> c; cout << min(n, a) + min(n, b) + min(n, c);
}