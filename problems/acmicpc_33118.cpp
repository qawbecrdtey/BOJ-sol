#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new int[n * 3];
    for(int i = 0; i < n * 3; i++) cin >> a[i];
    sort(a, a + n * 3);
    cout << a[n];
}
