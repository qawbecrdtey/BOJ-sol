#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n; auto a = new string[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int q, r{}; cin >> q; while(q--) {
        string s; cin >> s; r += binary_search(a, a + n, s);
    } cout << r;
}