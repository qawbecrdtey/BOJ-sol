#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; cout << (n % 2024 == 0 && n <= 100000 ? "Yes" : "No");
}
