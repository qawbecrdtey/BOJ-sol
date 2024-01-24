#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    auto a = new pair<int, int>[n];
    auto b = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
        b[i] = i + 1;
    }
    sort(b, b + n, [a](int x, int y) {
        return a[x - 1] < a[y - 1];
    });
    for(int i = 1; i < n; i++) {
        cout << b[i - 1] << ' ' << b[i] << '\n';
    }
}