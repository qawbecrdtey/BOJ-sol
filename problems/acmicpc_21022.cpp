#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, r{}; cin >> n; auto a = new int[n]; auto b = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) {
        r += 3 * (a[i] > b[i]) + (a[i] == b[i]);
    } cout << r;
}