#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n; i; i--) for(int j = 1; j < i; j++) a[j - 1] = abs(a[j] - a[j - 1]);
    cout << a[0];
}