#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new int[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    auto px = max_element(a, a + n);
    int sum = 0;
    for(auto p = a; p != px; p++) sum += *p;
    cout << sum << '\n'; sum = 0;
    for(auto p = px + 1; p != a + n; p++) sum += *p;
    cout << sum;
}