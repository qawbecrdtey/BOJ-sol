#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    long long n; cin >> n; cout << (n * (n + 1)) / 2 * (2 * n + 1) / 3;
}
